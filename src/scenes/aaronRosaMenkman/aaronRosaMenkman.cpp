
#include "aaronRosaMenkman.h"

void aaronRosaMenkman::setup(){
  
    // setup parameters
    // param was declared in aaronRosaMenkman.h
    parameters.add(sweepSpeed.set("sweepSpeed", 0.1, 0.0, 0.2));
    parameters.add(glitchFlavor.set("glitchFlavor", 50, 0, 100));

    setAuthor("aaron montoya-moraga");
    setOriginalArtist("Rosa Menkman");

    // load pseudocode
    loadCode("scenes/aaronRosaMenkman/exampleCode.cpp");
    
    // load original image
    original.load("scenes/aaronRosaMenkman/medialab.jpg");
    original.setImageType(OF_IMAGE_COLOR);
}

void aaronRosaMenkman::update(){
    
    // create buffer
    ofBuffer buffer;
    ofSaveImage(original.getPixels(), buffer, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_BEST);
    
    ofSeedRandom(glitchFlavor);
    
    int whereToSkip = ofMap(sin(sweepSpeed*ofGetElapsedTimef()), -1, 1, 0, buffer.size(), true);
    int left = buffer.size() - whereToSkip;
    
    int howMuchToSkip = ofMap(sin(sweepSpeed*ofGetElapsedTimef()), -1, 1, 0, 0.5*left, true);
    
    ofBuffer buffer2;
    
    for (int i = 0; i < buffer.size(); i++){
        if (i < whereToSkip || i > (whereToSkip+howMuchToSkip)){
            buffer2.append(buffer.getData() + i, 1);
        } else {
            char * data = new char[1];
            data[0] = ofRandom(0,255);
            buffer2.append(data, 1);
            delete data;
            
        }
    }
    newImage.load(buffer2);
}

void aaronRosaMenkman::draw(){
    newImage.draw(0,0);
}
