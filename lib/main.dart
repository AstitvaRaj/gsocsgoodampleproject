import 'package:flutter/material.dart';
import 'package:gsocgoodproject/java_image_class.dart';
import 'image_details.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key? key}) : super(key: key);

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  late JavaImageClass javaLibraryApi;
  late ImageDetails firstObject;
  late ImageDetails secondObject;

  @override
  void initState() {
    super.initState();
    javaLibraryApi = JavaImageClass();
    firstObject = ImageDetails('flutterLogo.jpg');
    secondObject = ImageDetails('a.jpg');
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('GSOC Good Sample Project'),
      ),
      body: Center(
        child: ListView(
          children: [
            Image.memory(
              javaLibraryApi.getImage(firstObject),
            ),
            Image.memory(
              javaLibraryApi.getImage(secondObject),
            ),
          ],
        ),
      ),
    );
  }
}
