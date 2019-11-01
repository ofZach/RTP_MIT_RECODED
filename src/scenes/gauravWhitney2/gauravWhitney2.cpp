
#include "gauravWhitney2.h"

void gauravWhitney2::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in gauravWhitney2.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Gaurav Rajaram Patekar");
    setOriginalArtist("John Whitney");

    parameters.add(scaleV.set("scaleV", 1.0, 0.5, 2.0));
    parameters.add(d.set("d", 300, 200, 500));
    parameters.add(res.set("res", 50, 50, 150));

    loadCode("scenes/gauravWhitney2/exampleCode.cpp");
}

void gauravWhitney2::update(){
    
}

void gauravWhitney2::draw(){
    
  
    ofFill();
    ofSetColor(0);
    ofRect(0,0,dimensions.width,dimensions.height);
    ofNoFill();
    ofSetColor(0,255,0);
    ofSetLineWidth(3);
    
    ofPushMatrix();
    ofTranslate(dimensions.width/2,dimensions.height/2);
    
    //ofNoStroke();
    ofFill();
    
    for(int k=-5; k<6; k++){
        for(int i=0; i<res; i++){
            float x = d*cos(i*2*PI/res)*scaleH;
            float y = d*sin(i*2*PI/res)*scaleV;
            ofSetLineWidth(4);
            ofCircle(x+k*150,y, 2);
            //point(x+k*150,y);
        }
    }
    for(int k=-5; k<6; k++){
        for(int i=0; i<res; i++){
            ofSetColor(0,0,250);
            float x = 100 + d*cos(i*2*PI/res+PI/3)*scaleH;
            float y = d*sin((i*2*PI/res))*scaleV;
            ofSetLineWidth(3);
            ofCircle((x+k*150)/1.5,y/1.5, 1.5);
            //point((x+k*150)/1.5,y/1.5);
        }
    }
    for(int k=-8; k<9; k++){
        for(int i=0; i<res; i++){
            ofSetColor(250,0,0);
            float x = 100 + d*cos(i*2*PI/res-PI/3)*scaleH;
            float y = d*sin((i*2*PI/res))*scaleV;
            ofSetLineWidth(2);
            //point((x+k*150)/3,y/3);
            ofCircle((x+k*150)/3,y/3,1);
        }
    }
    scaleH=2*sin(theta1);
    theta1 += 0.005;
    ofPopMatrix();
}
