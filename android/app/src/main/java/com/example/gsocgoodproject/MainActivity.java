package com.example.gsocgoodproject;
import android.os.Build;
import android.os.Environment;

import androidx.annotation.Keep;
import androidx.annotation.RequiresApi;


import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

import io.flutter.embedding.android.FlutterActivity;
 public class MainActivity extends FlutterActivity {
    static {
        System.loadLibrary("newtojni");
    }
}
