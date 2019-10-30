#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxFaceTracker2.h"
#include "ofxDelaunay.h"

class pbeshaiBurson1 : public baseScene {
  
public:
  
  void setup();
  void update();
  void draw();
  
  ofParameter<int> param1;
  ofParameter<int> param2;
  ofParameter<float> param3;
  
  int targetImgNumber;
  int sourceImgNumber;
  
  //  ofVideoGrabber grabber;
  ofxFaceTracker2 tracker;
  ofFbo cameraFbo;
  
  ofImage sourceImg;
  ofxFaceTracker2 trackerSource;
  
  ofImage targetImg;
  ofxFaceTracker2 trackerTarget;
  
  ofShader shader;
  
  bool showWireframe;
};
