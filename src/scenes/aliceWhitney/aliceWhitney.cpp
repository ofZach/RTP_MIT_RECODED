
#include "aliceWhitney.h"

void aliceWhitney::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in aliceWhitney.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Alice Hong");
    setOriginalArtist("John Whitney");

    
    parameters.add(xAngleParam.set("xAngleParam", 1, 1, 1.2));
    parameters.add(yAngleParam.set("yAngleParam", 1, 1, 1.2));
    
    
    loadCode("scenes/aliceWhitney/exampleCode.cpp");
}

void aliceWhitney::update(){
    
}

void aliceWhitney::draw(){
    
    ofBackground(0);
    ofSetColor(219, 174, 202);
    //ofDrawBitmapString(ofGetMouseX(), 100,100);
    //ofDrawBitmapString(ofGetMouseY(), 200,100); // measurments
    ofSetLineWidth(1);
    
    //Set of Triangles 1
    
//    ofSetColor(219, 174, 202);
//    ofNoFill();
//    ofDrawTriangle(80, 150, 240, 450, 400, 150);
//
//    ofSetColor(219, 174, 202);
//    ofNoFill();
//    ofDrawTriangle(200, 320, 360, 620, 520, 320);
//
//    ofSetColor(219, 174, 202);
//    ofNoFill();
//    ofDrawTriangle(335, 50, 495, 350, 650, 50);
//
//    ofSetColor(219, 174, 202);
//    ofNoFill();
//    ofDrawTriangle(460, 270, 620, 570, 775, 270);
    
    //Set of Randoms Triangles
    
    //
    //    for (int i= 0; i < 5; i++){
    //         for (int j= 0; j < 5; j++){
    //
    //
    //
    //            int ran = ofRandom(5);
    //            int tri_x= i;
    //            int tri_y= j;
    //
    //
    //           ofDrawTriangle((tri_x)*ran, tri_y, (tri_x+160)*ran, tri_y+300*ran, tri_x+320, tri_y*ran);
    //
    
    /*
     pseudocode
     
     John Whitney Sr
     BY ceoaliceee
     
     void draw() {
     let numTriangles = 10;
     for (int i = 0; i < numTriangles; i++){
     let x = 400 + 300 * cos(angle*[[xAngleParam]]);
     let y = 300 + 300 * sin(angle*[[yAngleParam]]);
     let size = 160 * noise(i, time * 0.1)
     drawTriangle(x, y, size);
     }
     }
     
     */
    
    
    ofSetColor(219, 174, 202);
    ofNoFill();
    ofSetLineWidth(3);
   // ofScale(0.83);
    
   
    int x = ofRandom(200, 400);
    int y = ofRandom(200, 400);
    float time = ofGetElapsedTimef();
    float xOrig = dimensions.getWidth()/2;
    float yOrig = dimensions.getHeight()/2;;
    float radius = 300; //ofMap(sin(time*10), -1, 1, 100, 300);
    
    for (int i = 0; i < 10; i++){
        float colorAmount = ofMap(i, 0, 9, 0.8, 1.15);
        ofSetColor(219 * colorAmount, 174 * colorAmount, 202 * colorAmount);
        float angle = i * 20 + time * 0.5;
        float x = xOrig + radius * cos(angle*xAngleParam);
        float y = yOrig + radius * sin(angle*yAngleParam);

        ofPushMatrix();
        ofTranslate(x, y);
        ofScale(ofNoise(i, time * 0.1));
        ofDrawTriangle(0, 0, 160, 300, 320, 0);
        ofPopMatrix();
    };
    
}
