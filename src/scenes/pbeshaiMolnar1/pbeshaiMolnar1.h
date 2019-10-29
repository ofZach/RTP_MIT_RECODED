#pragma once

#include "ofMain.h"
#include "baseScene.h"

class pbeshaiMolnar1 : public baseScene {
  
public:
  
  void setup();
  void update();
  void draw();
  
  ofParameter<int> param1;
  ofParameter<int> param2;
  ofParameter<float> param3;
  ofParameter<int> param4;
  
  ofFbo originalFbo;
  ofFbo mask;
};
