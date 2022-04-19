#include <jni.h>
#include <stdlib.h>

typedef struct {
    char* imageName;
    char* (*getImageName)();
} ImageDetails;

typedef struct {
    int* imageBuffer;
    int imageBufferLength;
    int* (*getImage)(ImageDetails*);
} JavaImageClass ;

JavaImageClass* JavaImageClassConstructor();
int* JavaImageClass_getImage(ImageDetails*);

ImageDetails* ImageDetailsConstructor(char*);
char* ImageDetails_getImageName();