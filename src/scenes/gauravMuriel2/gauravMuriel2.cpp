
#include "gauravMuriel2.h"

void gauravMuriel2::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in gauravMuriel2.h
    // parameters.add(param.set("param", 5, 0, 100));

     setAuthor("Gaurav Rajaram Patekar");
    setOriginalArtist("Muriel Cooper");

    parameters.add(e.set("e", 1.5, 0.3, 1.5));
    
    loadCode("scenes/gauravMuriel2/exampleCode.cpp");
}

void gauravMuriel2::update(){
    
}

void gauravMuriel2::draw(){
    
    ofSetColor(200,0,0);
    ofFill();
    ofRect(0,0,dimensions.width,dimensions.height);
    ofPushMatrix();
    ofTranslate(dimensions.width/2, dimensions.height/2);
    ofScale(1);
    for(int i=0; i<4; i++){
        ofRotateZ(i*PI/2 * RAD_TO_DEG);
        ofSetColor(250);
        ofRect(0+80*(1-sin(theta))*e,-20,10,20);
        ofRect(20+140*(1-sin(theta))*e,0,10,20);
        ofRect(50+100*(1-sin(theta))*e,40,20,10);
        ofSetColor(0);
        ofRect(50+30*(1-sin(theta))*e,-70,20,140);
        ofRect(10+70*(1-sin(theta))*e,-70,40,40);
        ofRect(20+50*(1-sin(theta))*e,0,50,30);
        ofRect(0+120*(1-sin(theta))*e,-20,20,40);
        ofRect(0+20*(1-sin(theta))*e,-20,40,60);
    }
    ofPopMatrix();
    theta+=0.01;
}
