
#include "karstenJohnWhitney.h"

void karstenJohnWhitney::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in karstenJohnWhitney.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Karsten Schuhl");
    setOriginalArtist("John Whitney");

    loadCode("scenes/karstenJohnWhitney/exampleCode.cpp");
    
    parameters.add(jStretch.set("jStretch", -2.1, -2.5, 2.5));
    parameters.add(xScale.set("xScale", -1, -1.0, 1.0));
    parameters.add(yScale.set("yScale", 1, -1.0, 1.0));
        
    xOrig = dimensions.getWidth()/4;
    yOrig = dimensions.getHeight()/4;
    lissRad = xOrig/2;
    pink = ofColor(255, 210, 230, 255);
    
}

void karstenJohnWhitney::update(){
    
}

void karstenJohnWhitney::draw(){
        
        float time = ofGetElapsedTimef();
        float angle = time;
        ofSetColor(0);
        ofFill();
        ofDrawRectangle(0, 0, dimensions.getWidth(), dimensions.getHeight());
        ofSetColor(pink);
        ofSetLineWidth(2);

        for (int i = 0; i < 5; i++){
          for(int j = 0; j < 8; j++){
            
            float x = xOrig + lissRad * cos(((i*xScale)+angle+(j*jStretch))*0.432);
            float y = yOrig + lissRad * sin(((i*yScale)+angle+(j*jStretch))*0.287);

            float hexRad = ofMap(sin((angle+i)), 1, -1, 3, 120);
            ofPushMatrix();
                ofTranslate(dimensions.getWidth()/8+dimensions.getWidth()/32, -dimensions.getHeight()/8);
                ofTranslate(x, y);
                ofSetCircleResolution(6);
                ofNoFill();
                ofRotateZDeg(30);
                ofDrawCircle(x, y, hexRad);
                ofPopMatrix();
          }
        }
    
}
