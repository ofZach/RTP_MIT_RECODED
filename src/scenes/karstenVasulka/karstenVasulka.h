#pragma once

#include "ofMain.h"
#include "baseScene.h"

class karstenVasulka : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
        ofVboMesh mesh;
        ofEasyCam cam;
        int counter = 0;
        float currentTime = 0.0;
        float lastTime = 0.0;
        float period = 5000;
        bool effect = false;
        int windowSizeX = 0;
        int windowSizeY = 0;
            
    ofVideoPlayer player;
    ofParameter < float > phaseZ;
    ofParameter < float > extrusionAmount;
};
