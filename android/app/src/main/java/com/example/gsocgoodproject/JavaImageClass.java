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
    private byte[] ImageBuffer;
    private String name;
    @RequiresApi(api = Build.VERSION_CODES.O)
    public void loadImage(){
        try {
            String internalStoragePath = Environment.getExternalStorageDirectory().getAbsolutePath();
            ImageBuffer = Files.readAllBytes(Paths.get(internalStoragePath+'/'+name));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void setImageName(String name){
        this.name = name;
    }
    public byte[] getImage(){
        return ImageBuffer;
    }
}
