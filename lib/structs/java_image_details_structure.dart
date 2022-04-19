import 'dart:ffi';

import 'package:ffi/ffi.dart';

class JavaImageDetailsStructure extends Struct {

  external Pointer<Utf8> imageName;
  external Pointer<NativeFunction<Pointer<Utf8> Function()>> getImageName;

}
