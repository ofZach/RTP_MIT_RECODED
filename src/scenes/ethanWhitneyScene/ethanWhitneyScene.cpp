//
//  ethanMolnarScene.cpp
//  RTP_MIT_RECODED
//
//  Created by Ethan Nevidomsky on 10/29/19.
//

#include "ethanWhitneyScene.h"


void ethanWhitneyScene::setup(){
    ofBackground(0);
    
    circleSize.set("Circle Size", 2, 1, 10);
    speed.set("Speed", .04, 0, .05);
    radius.set("Radius", .15, .05, .5);
    
    
    parameters.add(circleSize);
    parameters.add(speed);
    parameters.add(radius);
    
    setAuthor("Ethan Nevidomsky");
    setOriginalArtist("John Whitney");
    
    loadCode("scenes/ethanWhitneyScene/exampleCode.cpp");
    
    
    
}

void ethanWhitneyScene::update(){
}

void ethanWhitneyScene::draw(){
    float time = ofGetElapsedTimef();
    for(int i = 0; i < 2000; i++){
        ofSetColor(ofMap(i,0,2000,100,210)+ofRandom(40), ofMap(i*sin(time*2), -2000,2000,100,230)+ofRandom(20), ofMap(i*cos(time*2),-2000,2000,100,235)+ofRandom(20));

        ofDrawCircle(sin(time*i*speed)*i*radius+dimensions.width/2, cos(time*i*speed)*i*radius+dimensions.height/2, circleSize);
    }
}
