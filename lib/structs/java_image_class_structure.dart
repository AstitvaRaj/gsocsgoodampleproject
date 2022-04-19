import 'dart:ffi' as ffi;
import 'java_image_details_structure.dart';

class JavaImageClassStructure extends ffi.Struct {
  external ffi.Pointer<ffi.Uint8> imageBuffer;

  @ffi.Int32()
  external int imageBufferLength;


  external ffi.Pointer<ffi.NativeFunction<ffi.Uint8 Function()>> getImage;

  external ffi.Pointer<ffi.NativeFunction<ffi.Uint8 Function(ffi.Pointer<JavaImageDetailsStructure>)>> loadImage;
}
