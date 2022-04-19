import 'dart:ffi';

class ByteArray extends Struct {
  external Pointer<Uint8> imageBuffer;

  @Int32()
  external int imageBufferLength;
}
