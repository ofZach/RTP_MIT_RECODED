#pragma once

#include "ofMain.h"
#include "baseScene.h"

class pbeshaiVideo1 : public baseScene {
  
public:
  
  void setup();
  void update();
  void draw();
  
  ofParameter<int> param1;
  ofParameter<int> param2;
  ofParameter<float> param3;
  ofParameter<float> param4;
  
  
  vector <ofImage> frames;
  ofImage img;
  ofVideoPlayer player;
};
