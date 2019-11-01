#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxFaceTracker2.h"

class karstenFaceMirror : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    
        vector < ofImage > images;
        vector < ofImage > imagesLeft;
        vector < ofImage > imagesRight;
        ofxFaceTracker2 tracker;
        ofImage average;
        ofImage averageLeft;
        ofImage averageRight;
    
    int maxImgNumber = 0;
    int padding = 50;
    ofPoint diff;
    ofPoint leftAvg;
    ofPoint rightAvg;
    ofParameter < int > imgNumber;
    ofParameter < int > side;
};
