package com.example.gsocgoodproject;

import android.os.Build;
import android.os.Environment;

import androidx.annotation.Keep;
import androidx.annotation.RequiresApi;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
@Keep
public class Image {
    @Keep
    private static byte[] ImageBuffer;
    @RequiresApi(api = Build.VERSION_CODES.O)
    @Keep
    public static void loadImageBuffer(){
        try {
            String internalStoragePath = Environment.getExternalStorageDirectory().getAbsolutePath();
            ImageBuffer = Files.readAllBytes(Paths.get(internalStoragePath+"/flutterLogo.jpg"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
