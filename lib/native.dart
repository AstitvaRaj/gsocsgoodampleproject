import 'dart:ffi';

abstract class Native {
  late DynamicLibrary dynamicLibrary;
  Native() {
    dynamicLibrary = DynamicLibrary.open('libnewtojni.so');
  }
}
