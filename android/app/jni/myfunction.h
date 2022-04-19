#include <jni.h>
#include <stdlib.h>

typedef struct {
    char* imageName;
    char* (*getImageName)();
} ImageDetails;

typedef struct {
    int* imageBuffer;
    int imageBufferLength;
} ByteArray;

typedef struct {
    ByteArray* (*getImage)(ImageDetails*);
} JavaImageClass ;


jobject* JavaImageClass_constructor();
ByteArray* JavaImageClass_getImage(jobject*);
jobject* ImageDetails_constructor(char*);
jstring ImageDetails_getImageName(jobject*);