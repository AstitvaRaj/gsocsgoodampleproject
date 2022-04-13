import 'package:flutter/material.dart';
import 'package:gsocgoodproject/nativelibrary.dart';

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

  @override
  void initState() {
    super.initState();
    javaLibraryApi = JavaImageClass();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('GSOC Good Sample Project'),
      ),
      body: Center(
        child: Image.memory(javaLibraryApi.getImage()),
      ),
    );
  }
}
