import 'dart:ffi';
import 'native.dart';
import 'package:ffi/ffi.dart';

class ImageDetails extends Native {
  String imageName;
  late Pointer<Uint32> jObjectPtr;

  ImageDetails(this.imageName) {
    jObjectPtr = constructor(imageName);
  }

  Pointer<Uint32> constructor(String imageName) {
    Pointer<Uint32> Function(Pointer<Utf8>) _getObjectPointer = dynamicLibrary
        .lookup<NativeFunction<Pointer<Uint32> Function(Pointer<Utf8>)>>(
            'ImageDetails_constructor')
        .asFunction();
    return _getObjectPointer(imageName.toNativeUtf8());
  }

  String getImageName() {
    Pointer<Utf8> Function(Pointer<Uint32>) _getImageName = dynamicLibrary
        .lookup<NativeFunction<Pointer<Utf8> Function(Pointer<Uint32>)>>(
            'ImageDetails_getImageName')
        .asFunction();
    return _getImageName(jObjectPtr).toDartString();
  }
}
