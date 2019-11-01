
#include "liangVasulka.h"

void liangVasulka::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in liangVasulka.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Liang Zhipeng");
    setOriginalArtist("Woody and Steina Vasulka");

    parameters.add(magicNum.set("Magic Number",90,60,6000));
    parameters.add(spd.set("Speed", 12, 1, 20));
    
    
    loadCode("scenes/liangVasulka/exampleCode.cpp");
}

void liangVasulka::update(){
    
}

void liangVasulka::draw(){
    
    ofBackground(0);
    
    //    for (int i = 0; i < 800; i++){
    //
    //        //ofRandom();
    //        //ofNoise();
    //
    //        ofDrawCircle(i, 400 + ofNoise(i*0.01)*200, 1);
    //    }
    
    // float time = ofGetElapsedTimef();
    
    ofPushMatrix();
    ofScale(1.3, 1.3);
    speed = 20/spd;
    
    time = ofGetFrameNum()/speed;
    
    
    //
    //    int center_x=ofGetWindowWidth()/2;
    //    int center_y=ofGetWindowHeight()/2;
    int center_x=250;
    int center_y=250;
    //magicNumber = -3000*sin(0.02*time);
    magicNumber = -magicNum;
    
    ofPushMatrix();
    
    ofTranslate(center_x, center_y);
    
    
    
    for (int i = -0.66*center_x; i < 0.66*center_x; i++){
        for (int j = -0.7*center_y; j < 0.7*center_y; j++){
            
            //flipper =((int)time%2);
            // flipper = (int)sin(spd*ofGetFrameNum());
            // center_x=ofGetWindowWidth()/2;
            
            if((i*i + j*j)< (48*center_x^2+(int)ofRandom(-(float)magicNumber)+48*center_y^2)){
                
                
                // ofSetColor( ofNoise(i*0.01, j*0.01, time)*255, ofNoise(i*0.012, j*0.013, time)*255, ofNoise(i*0.015, j*0.014, time)*255);
                //ofSetColor(flipper*255);
                // ofDrawRectangle(i,j,1,1);
                ofSeedRandom(time);
                ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
                
                // ofDrawRectangle(i,j, 1, 1);
                ofDrawRectangle(i+ofRandom(-10,10), j+ofRandom(-10,10), 1, 1);
                
                
            } else {
                ofSetColor( ofNoise(i*0.01, j*0.01, 0.01*time)*255,ofNoise(i*0.01, j*0.01, 0.01*time)*255,ofNoise(i*0.01, j*0.01, 0.01*time)*255);
                //  ofSetColor(abs(flipper - 1)*255);
                ofDrawRectangle(i,j,1,1);
                
            }
            
            
        }
    }
    
    
    ofPopMatrix();
    
    ofPopMatrix();
    
    
}
