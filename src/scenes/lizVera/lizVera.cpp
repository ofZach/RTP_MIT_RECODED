
#include "lizVera.h"

void lizVera::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in lizVera.h
    // parameters.add(param.set("param", 5, 0, 100));

    
    parameters.add( randomness.set("randomness", 0, 0, 100));
    parameters.add( color.set("color", 0, 0, 250));
    parameters.add( randomSeed.set("randomSeed", 0, 0, 250));
    
    setAuthor("Liz");
    setOriginalArtist("Vera Molnar");

    loadCode("scenes/lizVera/exampleCode.cpp");
}

void lizVera::update(){
    
}

void lizVera::draw(){
    
    ofBackground(255);
    ofSetColor(color);
    ofSeedRandom(randomSeed*100);
    for (int i = 0; i < 25; i++){
        ofDrawRectangle(50 + i*20,50 + ofRandom(-1,1) * randomness,10,500 + ofRandom(-1,1) * randomness);
    }
   
}
