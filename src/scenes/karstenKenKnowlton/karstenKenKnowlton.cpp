
#include "karstenKenKnowlton.h"

void karstenKenKnowlton::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in karstenKenKnowlton.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Karsten Schuhl");
    setOriginalArtist("Ken Knowlton");

    loadCode("scenes/karstenKenKnowlton/exampleCode.cpp");
    
    player.load("scenes/karstenKenKnowlton/cam_480.mov");
    player.setSpeed(1.0);
    player.setVolume(0);
    player.play();
    player.setLoopState(OF_LOOP_NORMAL);
    
    parameters.add(cellSize.set("cellSize", 10.0, 5.0, 50.0));
    parameters.add(threshold.set("threshold", 255.0, 0.0, 255.0));
    parameters.add(weight.set("weight", 0.0, 0.0, 5.0));
    
    scaleFactor = dimensions.getHeight()/player.getHeight();
}

void karstenKenKnowlton::update(){
    player.update();
    
}

void karstenKenKnowlton::draw(){
     ofSetColor(45);
     ofDrawRectangle(0, 0, dimensions.getWidth(), dimensions.getHeight());
     ofSetColor(200);
     ofPushMatrix();
     ofScale(scaleFactor,scaleFactor);
     ofTranslate(-player.getWidth()/4, 0);
     for (int i = 0; i < player.getWidth(); i+=cellSize){
           for (int j = 0; j < player.getHeight(); j+=cellSize){
               ofColor color = player.getPixels().getColor(i,j);  //DISNEYLAND
               float bright = color.getBrightness();
               float brightness = ofMap(bright, 0, 255, 0, threshold);
               ofPushMatrix();
               ofTranslate(i, j);
                  ofFill();
                       ofSetColor(230);
                       if(brightness <= 63){
                           ofDrawTriangle(0, 0, cellSize/2, cellSize/2, 0, cellSize);
                       } else if (64 <= brightness && brightness <= 128){
                           ofDrawTriangle(0, 0, cellSize, 0, cellSize, 0);
                       } else if (129 <= brightness && brightness <= 192){
                           ofBeginShape();
                             ofVertex(0,0);
                             ofVertex(0,cellSize);
                             ofVertex(cellSize,cellSize);
                             ofVertex(cellSize/2,cellSize/2);
                             ofVertex(0,cellSize);
                           ofEndShape();
                       } else if (brightness > 192) {
                           ofDrawRectangle(0, 0, cellSize, cellSize);
                       }
                   
                       ofNoFill();
                       ofSetColor(45);
                       ofSetLineWidth(weight);
                   
                       if(brightness <= 63){
                           ofDrawTriangle(0, 0, cellSize/2, cellSize/2, 0, cellSize);
                       } else if (64 <= brightness && brightness <= 128){
                           ofDrawTriangle(0, 0, cellSize, 0, cellSize, 0);
                       } else if (129 <= brightness && brightness <= 192){
                           ofBeginShape();
                             ofVertex(0,0);
                             ofVertex(0,cellSize);
                             ofVertex(cellSize,cellSize);
                             ofVertex(cellSize/2,cellSize/2);
                             ofVertex(0,cellSize);
                           ofEndShape();
                       } else if (brightness > 192) {
                           ofDrawRectangle(0, 0, cellSize, cellSize);
                       }
               ofPopMatrix();
           }
       }
     ofPopMatrix();
}
