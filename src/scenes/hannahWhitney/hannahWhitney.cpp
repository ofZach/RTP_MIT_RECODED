
#include "hannahWhitney.h"

void hannahWhitney::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in mitScene1.h
    //parameters.add(param.set("param", 5, 0, 100));

    parameters.add(speed.set("speed", 1, 0, 5));
    parameters.add(noise.set("noise", 10, 0, 100));
    
    setAuthor("Hannah Lienhard");
    setOriginalArtist("John Whitney");

    loadCode("scenes/hannahWhitney/exampleCode.cpp");
}

void hannahWhitney::update(){
    
}

void hannahWhitney::draw(){
    ofBackground(0);
    ofSetColor(255);
    float time = speed*ofGetElapsedTimef()*50;
    ofSeedRandom(noise);
    for (int z = 0; z < 10; z++){
        float radius = fmod(time + ofMap(z, 0, 10, 0, 300), 300);
        ofPoint center(300,300);
        for (int i = 0; i < 100; i++){
            float angle = ofMap(i, 0, 100, 0, TWO_PI);
            float offset = ofNoise(ofRandom(0.01, 0.06))*100;
            ofDrawCircle(center.x + offset+ radius * cos(angle),
                         center.y + +offset+ radius * sin(angle),
                         3);
        }
        
    }
}
