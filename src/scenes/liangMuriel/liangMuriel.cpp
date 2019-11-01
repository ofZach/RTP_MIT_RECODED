
#include "liangMuriel.h"

void liangMuriel::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in liangMuriel.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Liang Zhipeng");
    setOriginalArtist("Muriel Cooper");
    
    parameters.add(spd.set("Distance", 0.4, 0, 2));
    parameters.add(magicNum.set("Size",114,50,600));
    parameters.add(colorFac.set("Wind",0,0,255));
    
    loadCode("scenes/liangMuriel/exampleCode.cpp");
}

void liangMuriel::update(){
    
}

void liangMuriel::draw(){
    
    ofPushMatrix();
    ofScale(0.5, 0.5);
    
    ofBackground(226,182,61);
    
    //    for (int i = 0; i < 800; i++){
    //
    //        //ofRandom();
    //        //ofNoise();
    //
    //        ofDrawCircle(i, 400 + ofNoise(i*0.01)*200, 1);
    //    }
    
    
    
    float time = ofGetElapsedTimef()*spd;
    
    
    //time = ofGetFrameNum()/speed;
    
    
    
    int center_x=ofGetWindowWidth()/2;
    int center_y=ofGetWindowHeight()/2;
    //magicNumber = -3000*sin(0.02*time);
    // magicNumber = -magicNum;
    
    
    // magicNum + ofRandom(15);
    
    // for(int i=1;i<k;i++){
    
    
    ofPushMatrix();
    
    ofTranslate(center_x, center_y);
    
    
    
    for (int i = -0.8*center_x; i < 0.6 * center_x+magicNum; i+=magicNum){
        int w=0;
        for (int j = -0.4*center_y; j < (2*magicNum-i - 0.4* center_y); j+=magicNum){
            w++;
            ofSetColor(255-colorFac*ofRandom(0,1));
            ofSetLineWidth(5);
            ofNoFill();
            ofDrawLine(i, j, i+spd*magicNum+colorFac*ofRandom(-1,1), j-spd*magicNum+colorFac*ofRandom(-1,1));
            
            if(w==((2*magicNum-i)/magicNum)){
                ofDrawLine(i+magicNum, j+magicNum, i+magicNum+spd*magicNum+colorFac*ofRandom(-1,1), j+magicNum-spd*magicNum+colorFac*ofRandom(-1,1));
            }
            
        }
        
    }
    ofPopMatrix();
    
    
    ofPushMatrix();
    
    ofTranslate(center_x+spd*magicNum+colorFac*0.1*ofRandom(colorFac*0.01,colorFac*0.1), center_y-spd*magicNum-colorFac*0.1*ofRandom(colorFac*0.01,colorFac*0.1));
    
    for (int i = -0.8*center_x; i < 0.6 * center_x; i+=magicNum){
        for (int j = -0.4*center_y; j < (magicNum-i - 0.4* center_y); j+=magicNum){
            
            ofSetColor(colorFac*ofRandom(0,1),colorFac*ofRandom(0,1),colorFac*ofRandom(0,1));
            ofSetLineWidth(5+colorFac*0.1*ofRandom(-1,1));
            ofNoFill();
            ofDrawRectangle(i, j, magicNum, magicNum);
            
        }
        
    }
    ofPopMatrix();
    
    
    //}
    
    ofPushMatrix();
    
    ofTranslate(center_x, center_y);
    
    for (int i = -0.8*center_x; i < 0.6 * center_x; i+=magicNum){
        for (int j = -0.4*center_y; j < (magicNum-i - 0.4* center_y); j+=magicNum){
            
            ofSetColor(colorFac*ofRandom(0,1),colorFac*ofRandom(0,1),colorFac*ofRandom(0,1));
            ofSetLineWidth(5);
            ofNoFill();
            ofDrawRectangle(i, j, magicNum, magicNum);
            
        }
        
    }
    ofPopMatrix();
    
    ofPopMatrix();
    
    
}
