#include "myfunction.h"
static  JavaVM* vm = NULL;
 jclass  globalImageClass;

//Executes when Native Library will load
JNIEXPORT jint JNI_OnLoad(JavaVM* vms, void* reserved) {
    vm = vms;
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jclass localImageClass = (*env)->FindClass(env,"com/example/gsocgoodproject/Image");

    globalImageClass = (jclass) (*env)->NewGlobalRef(env,localImageClass);
    return JNI_VERSION_1_6;
}

ImageBufferArrayDetails tempStruct;

void loadImageBuffer(){
    if(vm!=NULL){
        JNIEnv* env;
        (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
        jmethodID i = (*env)->GetStaticMethodID(env,globalImageClass,"loadImageBuffer", "()V");
        (*env)->CallStaticVoidMethod(env,globalImageClass,i);
    }
}

ImageBufferArrayDetails * getImageBufferPointer(){
    if(vm!=NULL){
        JNIEnv* env;
        (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
        jfieldID fieldId = (*env)->GetStaticFieldID(env,globalImageClass,"ImageBuffer", "[B");
        jobject jObject = (*env)->GetStaticObjectField(env,globalImageClass,fieldId);
        jbyte* data = (*env)->GetByteArrayElements(env,(jbyteArray) jObject, NULL);
        tempStruct.firstElement = (int* ) data;
        tempStruct.length = (int)(*env)->GetArrayLength(env,(jbyteArray) jObject);
        return &tempStruct;
    }
    return NULL;
}
