import 'dart:ffi';
import 'package:ffi/ffi.dart';
import 'structs/java_image_details_structure.dart';

typedef jObject = Dart_CObject;

class ImageDetails {
  String imageName;
  late DynamicLibrary dynamicLibrary;
  late Pointer<jObject> jobjectPtr;

  ImageDetails(this.imageName){
    jobjectPtr = getObjectPointer();
  }

  String getImageName() {
    Pointer<Utf8> Function() _getImageName = dynamicLibrary
        .lookup<NativeFunction<Pointer<Utf8> Function()>>(
            'ImageDetails_getImageName')
        .asFunction();
    return _getImageName().toDartString();
  }

  Pointer<jObject> getObjectPointer() {
    Pointer<jObject> Function() _getObjectPointer = dynamicLibrary
        .lookup<NativeFunction<Pointer<jObject> Function()>>('getObjectPointer')
        .asFunction();
    return _getObjectPointer();
  }

  Pointer<JavaImageDetailsStructure> toStruct() {
    Pointer<JavaImageDetailsStructure> imageDetails = malloc();
    imageDetails.ref.imageName = imageName.toNativeUtf8();
    imageDetails.ref.getImageName = nullptr;
    return imageDetails;
  }
}
