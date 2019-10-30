#pragma once

#include "ofMain.h"
#include "baseScene.h"

class pbeshaiWhitney1 : public baseScene {
  
public:
  
  void setup();
  void update();
  void draw();
  
  
  ofParameter<float> param1;
  ofParameter<float> param2;
  ofParameter<float> param3;
  ofParameter<float> param4;
  
  string text;
  ofTrueTypeFont font;
  ofFbo textFbo;
  ofPixels textPixels;
  vector<glm::vec3> textPoints;
};
