
#include "hannahVera.h"

void hannahVera::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in mitScene1.h
    //parameters.add(param.set("param", 5, 0, 100));

    parameters.add(noise.set("noise", 0, 0, 100));
    parameters.add(space.set("space", 20, 0, 100));
    
    setAuthor("Hannah Lienhard");
    setOriginalArtist("Vera Molnar");

    loadCode("scenes/hannahVera/exampleCode.cpp");
}

void hannahVera::update(){
    
}

void hannahVera::draw(){
    ofBackground(255);
    ofSeedRandom(noise);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(70,55,85, 150);
    float r = space*0.001;
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            
            float offset = ofNoise(ofRandom(r, 0.09))*440;
            ofDrawRectangle(55*i + offset-150, 57*j + offset-150, 60, 60);
         
        }
    }
}
