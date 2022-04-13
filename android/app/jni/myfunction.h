#include <jni.h>
typedef struct ImageBufferArrayDetails{
    int* firstElement;
    int length;
}ImageBufferArrayDetails;

ImageBufferArrayDetails * getImageBufferPointer();

void loadImageBuffer();