#include "myfunction.h"
static  JavaVM* vm = NULL;
 jclass globalJavaImageClass;

//Executes when Native Library will load
JNIEXPORT jint JNI_OnLoad(JavaVM* vms, void* reserved) {
    vm = vms;
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jclass localImageClass = (*env)->FindClass(env,"com/example/gsocgoodproject/JavaImageClass");
    globalJavaImageClass = (*env)->NewGlobalRef(env,localImageClass);
    return JNI_VERSION_1_6;
}

JavaImageClass* javaImageClass;
jobject globalObject;

JavaImageClass* JavaImageClassConstructor(){
    javaImageClass = malloc(sizeof(JavaImageClass));
    javaImageClass->getImage = &getImage;
    javaImageClass->setImageName = &setImageName;
    javaImageClass->loadImage = &loadImage;
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jmethodID  MethodId = (*env)->GetMethodID(env,globalJavaImageClass,"<init>", "()V");
    jobject object = (*env)->NewObject(env,globalJavaImageClass,MethodId);
    globalObject = (*env)->NewGlobalRef(env,object);
    return javaImageClass;
}

int* getImage(){
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jmethodID getImageMethodId= (*env)->GetMethodID(env,globalJavaImageClass,"getImage", "()[B");
    jobject obj = (*env)->CallObjectMethod(env,globalObject,getImageMethodId);
    jbyte* imageByte = (*env)->GetByteArrayElements(env,(jbyteArray) obj,NULL);
    javaImageClass->imageBufferLength = (*env)->GetArrayLength(env,(jbyteArray)obj);
    return (int*) imageByte;
}
void setImageName(char* name){
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jstring names = (*env)->NewStringUTF(env, (const char *) name);
    jmethodID getImageMethodId= (*env)->GetMethodID(env,globalJavaImageClass,"setImageName", "(Ljava/lang/String;)V");
    (*env)->CallVoidMethod(env,globalObject,getImageMethodId,names);
}
void loadImage(){
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jstring names = (*env)->NewStringUTF(env, (const char *) "/flutterLogo.jpg");
    jmethodID getImageMethodId= (*env)->GetMethodID(env,globalJavaImageClass,"loadImage", "()V");
    (*env)->CallVoidMethod(env,globalObject,getImageMethodId);
}
