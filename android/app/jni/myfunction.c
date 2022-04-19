#include "myfunction.h"
static  JavaVM* vm = NULL;
jclass globalJavaImageClass;
jobject globalJavaImageClassObject;

jclass globalImageDetailsClass;
jobject  globalImageDetailsObject;
//Executes when Native Library will load
JNIEXPORT jint JNI_OnLoad(JavaVM* vms, void* reserved) {
    vm = vms;
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jclass localImageClass = (*env)->FindClass(env,"com/example/gsocgoodproject/JavaImageClass");
    globalJavaImageClass = (*env)->NewGlobalRef(env,localImageClass);
    jclass localImageDetails = (*env)->FindClass(env,"com/example/gsocgoodproject/ImageDetails");
    globalImageDetailsClass = (*env)->NewGlobalRef(env,localImageDetails);
    return JNI_VERSION_1_6;
}

JavaImageClass* javaImageClass;

JavaImageClass* JavaImageClassConstructor(){
    javaImageClass = malloc(sizeof(JavaImageClass));
    javaImageClass->getImage = &JavaImageClass_getImage;
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jmethodID  MethodId = (*env)->GetMethodID(env,globalJavaImageClass,"<init>", "()V");
    jobject object = (*env)->NewObject(env,globalJavaImageClass,MethodId);
    globalJavaImageClassObject = (*env)->NewGlobalRef(env,object);
    return javaImageClass;
}

int* JavaImageClass_getImage(ImageDetails* imageDetails){
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jmethodID loadImage= (*env)->GetMethodID(env,globalJavaImageClass,"getImage",
                                             "(Lcom/example/gsocgoodproject/ImageDetails;)[B");

    jmethodID methodId = (*env)->GetMethodID(env,globalImageDetailsClass,"<init>", "(Ljava/lang/String;)V");
    jstring imagenames = (*env)->NewStringUTF(env,imageDetails->imageName);
    jobject imageDetailsObject = (*env)->NewObject(env,globalImageDetailsClass,methodId,imagenames);
    jobject obj = (*env)->CallObjectMethod(env,globalJavaImageClassObject,loadImage,imageDetailsObject);
    jbyte* imageByte = (*env)->GetByteArrayElements(env,(jbyteArray) obj,NULL);
    javaImageClass->imageBufferLength = (*env)->GetArrayLength(env,(jbyteArray)obj);
    return (int*) imageByte;
}


ImageDetails* imageDetails;

ImageDetails* ImageDetailsConstructor(char* name){
    imageDetails = malloc(sizeof(ImageDetails));
    imageDetails->getImageName =  &ImageDetails_getImageName;
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jmethodID  MethodId = (*env)->GetMethodID(env,globalImageDetailsClass,"<init>",
                                              "(Ljava/lang/String;)V");
    jstring imageNames = (*env)->NewStringUTF(env,name);
    jobject object = (*env)->NewObject(env,globalImageDetailsClass,MethodId,imageNames);
    globalImageDetailsObject = (*env)->NewGlobalRef(env,object);
    return imageDetails;
}


char *ImageDetails_getImageName() {
    JNIEnv* env;
    (*vm)->GetEnv(vm,(void*) &env,JNI_VERSION_1_6);
    jmethodID methodId = (*env)->GetMethodID(env,globalImageDetailsClass,"getImageName",
                                             "()Ljava/lang/String;");
    jobject jStr = (*env)->CallObjectMethod(env,globalImageDetailsObject,methodId);
    char* temp = (char *) (*env)->GetCharArrayElements(env, jStr, 0);
    return temp;
}