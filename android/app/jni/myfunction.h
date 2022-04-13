#include <jni.h>
#include <stdlib.h>

typedef struct {
    int* imageBuffer;
    int imageBufferLength;
    void (*setImageName)(char*);
    int* (*getImage)();
    void (*loadImage)();
} JavaImageClass ;

JavaImageClass* JavaImageClassConstructor();
void setImageName(char*);
int* getImage();
void loadImage();