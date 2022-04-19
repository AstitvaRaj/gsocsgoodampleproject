import 'dart:ffi' as ffi;
import 'dart:typed_data';
import './structs/java_image_class_structure.dart';
import './structs/java_image_details_structure.dart';
import 'image_details.dart';



class JavaImageClass {

  late JavaImageClassStructure imageClass;
  late ffi.DynamicLibrary dynamicLibrary;

  JavaImageClass() {
    dynamicLibrary = ffi.DynamicLibrary.open('libnewtojni.so');
    ffi.Pointer<JavaImageClassStructure> Function() _javaImageClassConstructor =
        dynamicLibrary
            .lookup<
                ffi.NativeFunction<
                    ffi.Pointer<JavaImageClassStructure>
                        Function()>>('JavaImageClassConstructor')
            .asFunction();
    imageClass = _javaImageClassConstructor().ref;
  }

  Uint8List getImage(ImageDetails imageStructure) {
    ffi.Pointer<ffi.Uint8> Function(ffi.Pointer<JavaImageDetailsStructure>) _loadImage = dynamicLibrary
        .lookup<ffi.NativeFunction<ffi.Pointer<ffi.Uint8> Function(ffi.Pointer<JavaImageDetailsStructure>)>>('JavaImageClass_getImage')
        .asFunction();
   return  _loadImage(imageStructure.toStruct()).asTypedList(imageClass.imageBufferLength);
  }

}
