
#include "karstenVeraMolnar.h"

void karstenVeraMolnar::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in karstenVeraMolnar.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Karsten Schuhl");
    setOriginalArtist("Vera Molnar");

    loadCode("scenes/karstenVeraMolnar/exampleCode.cpp");
    
    parameters.add(numSquares.set("numSquares", 5, 2, 20));
    parameters.add(offAmount.set("offAmount", 1.0, 0.0, 3.0));
    parameters.add(rotation.set("rotation", 0.0, 0.0, 360.0));
    parameters.add(margin.set("margin", 36, 0, 50));
    
    windowSize = dimensions.getWidth();

}

void karstenVeraMolnar::update(){
    ofSeedRandom(1);
    squareSize = windowSize/numSquares;
}

void karstenVeraMolnar::draw(){
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(0, windowSize);
        ofScale(1, -1);
        ofSetColor(255);
        ofDrawRectangle(windowSize/2, windowSize/2, windowSize, windowSize);
        
        ofSetColor(0, 0, 0, 200);
        for(int i = 0; i < numSquares; i++){
            for(int j= 0; j < numSquares; j++){
                float posX = (ofMap(i, 0, numSquares-1, squareSize, (windowSize - squareSize)));
                float posY = (ofMap(j, 0, numSquares-1, squareSize, (windowSize - squareSize))); //*ofNoise(i*0.02, j*0.04))*noiseScale);
                float offset = ofRandom(-offAmount*(squareSize/numSquares), offAmount*(squareSize/numSquares));
                ofPushMatrix();
                ofTranslate(posX, posY);
                ofRotateZDeg(rotation);
                ofDrawRectangle(0+offset, 0+offset, squareSize-margin, squareSize-margin);
                ofPopMatrix();
            }
        }
        ofPopMatrix();
}
