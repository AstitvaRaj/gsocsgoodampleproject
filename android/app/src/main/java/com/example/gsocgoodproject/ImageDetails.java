package com.example.gsocgoodproject;

import androidx.annotation.Keep;

@Keep
public class ImageDetails {
    private final String imageName;

    ImageDetails(String imageName){
        this.imageName = imageName;
    }

    String getImageName(){
        return  imageName;
    }
}
