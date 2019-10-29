
#include "pbeshaiMolnar1.h"

void pbeshaiMolnar1::setup(){
  
  // setup parameters
  // if your original code use an ofxPanel instance dont use it here, instead
  // add your parameters to the "parameters" instance as follows.
  // param was declared in pbeshaiMolnar1.h
  //parameters.add(param.set("param", 5, 0, 100));
  setAuthor("Peter Beshai");
  setOriginalArtist("Vera Molnar");
  
  loadCode("scenes/pbeshaiMolnar1/exampleCode.cpp");
  
  parameters.add(param1.set("thickness", 7, 1, 20));
  parameters.add(param2.set("numLines", 75, 10, 300));
  parameters.add(param3.set("offset", 40, 0, 200));
  parameters.add(param4.set("segmentWidth", 55, 4, 200));
  
  float width = dimensions.getWidth();
  float height = dimensions.getHeight();
  
  originalFbo.allocate(width, height);
  mask.allocate(width, height);
  
  mask.begin();
  ofClear(0,0,0);
  ofSetColor(255);
  ofSetCircleResolution(100);
  ofDrawCircle(width / 2, height / 2, width * 0.4);
  mask.end();
}


void drawLine(float x1, float y1, float x2, float y2,float chunkWidth) {
    float slope = (y2 - y1) / (x2 - x1);
    float offset = y1 - slope * x1;
    float x = x1;
    float y = y1;
    while (x < x2) {
        ofDrawLine(x, y, x + chunkWidth, y);
        x += chunkWidth;
        y = slope * x + offset;
    }

}

void pbeshaiMolnar1::update(){
  float width = ofGetWidth();
  float height = ofGetHeight();
  float lineWidth = param1;
  int numLines = param2;
  float randomAmountMin = param3 * 0.5;
  float randomAmountMax = param3;
  float chunkWidth = param4;
  
  originalFbo.begin();
  ofClear(255);
  ofSetColor(15);
  ofSetLineWidth(lineWidth);
  ofSeedRandom(649);
  
  
  
  for (int i = 0; i < numLines; ++i) {
      float y = ofMap(i, 0, numLines - 1, 0, height);
      float sign = ofRandom(0, 1) < 0.5 ? -1 : 1;
      float y1 = y + sign * ofRandom(randomAmountMin, randomAmountMax);
      float y2 = y1 + sign * ofRandom(randomAmountMin, randomAmountMax);
      drawLine(0, y1, width, y2, chunkWidth);
  }
  
  
  originalFbo.end();
}



void pbeshaiMolnar1::draw(){
  ofBackground(230);
  originalFbo.getTexture().setAlphaMask(mask.getTexture());
  originalFbo.draw(0,0);
}
