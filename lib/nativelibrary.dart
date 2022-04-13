import 'dart:ffi' as ffi;
import 'dart:typed_data';
import 'package:ffi/ffi.dart';

class JavaImageClassStructure extends ffi.Struct {
  external ffi.Pointer<ffi.Uint8> imageBuffer;

  @ffi.Int32()
  external int imageBufferLength;

  external ffi.Pointer<ffi.NativeFunction<ffi.Void Function(String)>>
      setImageName;

  external ffi.Pointer<ffi.NativeFunction<ffi.Uint8 Function()>> getImage;

  external ffi.Pointer<ffi.NativeFunction<ffi.Void Function()>> loadImage;
}

typedef NativeSetImageName = ffi.Void Function(ffi.Pointer<ffi.Int8>);
typedef DartsetImageName = void Function(ffi.Pointer<ffi.Int8>);

class JavaImageClass {
  late ffi.DynamicLibrary dynamicLibrary;
  late JavaImageClassStructure imageClass;

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
    setImageName('flutterLogo.jpg');
    loadImage();
  }

  void setImageName(String s) {
    final _setImageName = dynamicLibrary
        .lookupFunction<NativeSetImageName, DartsetImageName>('setImageName');
    final ptr = s.toNativeUtf8().cast<ffi.Int8>();
    _setImageName(ptr);
  }

  void loadImage() {
    void Function() _loadImage = dynamicLibrary
        .lookup<ffi.NativeFunction<ffi.Void Function()>>('loadImage')
        .asFunction();
    _loadImage();
  }

  Uint8List getImage() {
    ffi.Pointer<ffi.Uint8> Function() _getImage = dynamicLibrary
        .lookup<ffi.NativeFunction<ffi.Pointer<ffi.Uint8> Function()>>(
            'getImage')
        .asFunction();
    return _getImage().asTypedList(imageClass.imageBufferLength);
  }
}
