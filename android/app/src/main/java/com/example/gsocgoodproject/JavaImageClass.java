package com.example.gsocgoodproject;

import android.os.Build;
import android.os.Environment;

import androidx.annotation.Keep;
import androidx.annotation.RequiresApi;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

@Keep
public class JavaImageClass {
    @RequiresApi(api = Build.VERSION_CODES.O)
    public byte[] getImage(ImageDetails imageDetails){
        byte[] i = {};
        try {
            String internalStoragePath = Environment.getExternalStorageDirectory().getAbsolutePath();
            i = Files.readAllBytes(Paths.get(internalStoragePath+'/'+imageDetails.getImageName()));
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return i;
    }
}
