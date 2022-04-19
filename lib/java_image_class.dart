import 'dart:ffi';
import 'image_details.dart';
import 'dart:typed_data';
import 'native.dart';
import 'structs/byte_array.dart';

class JavaImageClass extends Native {
  late Pointer<Uint16> jobject;
  JavaImageClass() {
    jobject = constructor();
  }

  Pointer<Uint16> constructor() {
    Pointer<Uint16> Function() _constructor = dynamicLibrary
        .lookup<NativeFunction<Pointer<Uint16> Function()>>(
            'JavaImageClass_constructor')
        .asFunction();
    return _constructor();
  }

  Uint8List getImage(ImageDetails imageDetails) {
    Pointer<ByteArray> Function(Pointer<Uint32>) temp = dynamicLibrary
        .lookup<NativeFunction<Pointer<ByteArray> Function(Pointer<Uint32>)>>(
            'JavaImageClass_getImage')
        .asFunction();
    ByteArray byteArray = temp(imageDetails.jObjectPtr).cast<ByteArray>().ref;
    return byteArray.imageBuffer.asTypedList(byteArray.imageBufferLength);
  }
}
