import 'dart:ffi' as ffi;

import 'dart:typed_data';

class ImageBufferArrayDetails extends ffi.Struct {
  external ffi.Pointer<ffi.Uint8> array;

  @ffi.Int32()
  external int length;
}

class NativeLibrary {
  late ffi.DynamicLibrary dynamicLibrary;

  NativeLibrary() {
    dynamicLibrary = ffi.DynamicLibrary.open('libnewtojni.so');
  }


  void loadImageBuffer() {
    void Function() _loadImageBuffer = dynamicLibrary
        .lookup<ffi.NativeFunction<ffi.Void Function()>>('loadImageBuffer')
        .asFunction();
    _loadImageBuffer();
  }

  ffi.Pointer<ImageBufferArrayDetails> getImageBufferPointer() {
    ffi.Pointer<ImageBufferArrayDetails> Function() temp = dynamicLibrary
        .lookup<ffi.NativeFunction<ffi.Pointer<ImageBufferArrayDetails> Function()>>(
            'getImageBufferPointer')
        .asFunction();
    return temp();
  }


  Uint8List getImageBuffer() {
    loadImageBuffer();
    ImageBufferArrayDetails data = getImageBufferPointer().cast<ImageBufferArrayDetails>().ref;
    return data.array.asTypedList(data.length);    
  }
}
