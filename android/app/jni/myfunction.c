#include "myfunction.h"
static  JavaVM* vm = NULL;
jclass JavaImage;
jclass ImageDetailsClass;
//Executes when Native Library will load
JNIEXPORT jint JNI_OnLoad(JavaVM* vms, void* reserved) {
    vm = vms;
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jclass localImageClass = (*env)->FindClass(env,"com/example/gsocgoodproject/JavaImageClass");
    JavaImage = (*env)->NewGlobalRef(env,localImageClass);
    jclass localImageDetails = (*env)->FindClass(env,"com/example/gsocgoodproject/ImageDetails");
    ImageDetailsClass = (*env)->NewGlobalRef(env,localImageDetails);
    return JNI_VERSION_1_6;
}

jobject JavaImageObject;

jobject* JavaImageClass_constructor(){
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jmethodID constructor = (*env)->GetMethodID(env,JavaImage,"<init>","()V");
    jobject object = (*env)->NewObject(env,JavaImage,constructor);
    JavaImageObject = malloc(sizeof(JavaImageClass));
    JavaImageObject = (*env)->NewGlobalRef(env,object);
    return &JavaImageObject;
}

ByteArray* byteArray;

ByteArray* JavaImageClass_getImage(jobject* imageDetailsObject){
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jmethodID loadImage= (*env)->GetMethodID(env,JavaImage,"getImage",
                                             "(Lcom/example/gsocgoodproject/ImageDetails;)[B");
    jobject temp = imageDetailsObject;

    jobject obj = (*env)->CallObjectMethod(env,JavaImageObject,loadImage,temp);

    jbyte* imageByte = (*env)->GetByteArrayElements(env,(jbyteArray) obj,NULL);
    byteArray = malloc(sizeof(ByteArray));
    byteArray->imageBufferLength = (*env)->GetArrayLength(env,(jbyteArray)obj);
    byteArray->imageBuffer = (int*) imageByte;
    return byteArray;
}

jobject* ImageDetailsObject;

jobject* ImageDetails_constructor(char* name){
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jmethodID constructor = (*env)->GetMethodID(env,ImageDetailsClass,"<init>",
                                                "(Ljava/lang/String;)V");
    jstring imageName = (*env)->NewStringUTF(env,name);
    jobject object = (*env)->NewObject(env,ImageDetailsClass,constructor,imageName);
    ImageDetailsObject = malloc(sizeof(ImageDetails));
    ImageDetailsObject = (*env)->NewGlobalRef(env,object);
    return ImageDetailsObject;
}

jstring ImageDetails_getImageName(jobject* detailsObject){
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jmethodID  methodId =  (*env)->GetMethodID(env,ImageDetailsClass,"getImageName", "()Ljava/lang/String;");
    jstring s = (*env)->CallObjectMethod(env,*detailsObject,methodId);
    return s;
}