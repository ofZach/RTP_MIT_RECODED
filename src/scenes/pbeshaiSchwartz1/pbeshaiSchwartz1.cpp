
#include "pbeshaiSchwartz1.h"

void pbeshaiSchwartz1::setup(){
  
  // setup parameters
  // if your original code use an ofxPanel instance dont use it here, instead
  // add your parameters to the "parameters" instance as follows.
  // param was declared in pbeshaiSchwartz1.h
  // parameters.add(param.set("param", 5, 0, 100));
  
  setAuthor("Peter Beshai");
  setOriginalArtist("Lillian Schwartz");
  
  loadCode("scenes/pbeshaiSchwartz1/exampleCode.cpp");
  
  parameters.add(param1.set("noiseZoom", 0.008, 0.001, 0.1));
  parameters.add(param2.set("bandSize", 0.06, 0.06, 0.5));
  parameters.add(param3.set("speed", 1, 0.25, 10));
//  parameters.add(param4.set("cellSize", 1, 1, 40));
  
  float width = dimensions.getWidth();
  float height = dimensions.getHeight();
  img.allocate(width, height, OF_IMAGE_COLOR);
}

void pbeshaiSchwartz1::update(){
  
  ofColor color1 = ofColor(0);
  ofColor color2 = ofColor(255);
  
  
  float cellSize = 1;
  float width = dimensions.getWidth();
  float height = dimensions.getHeight();
  int numCols = ceil(width / cellSize);
  int numRows = ceil(height / cellSize);
  
  float noiseZoom = param1;
  
  float time = ofGetElapsedTimef() * param3;
  
  float bandSize = param2; //ofMap(sin(time * 0.514), -1, 1, 0.04, 0.1);
  float bandMin = ofMap(sin(time * 0.3), -1, 1, 0.3, 0.6);
  float bandMax = ofMap(sin(time * 0.2 + PI), -1, 1, 1.0, 0.8);
  float slice = time * 20;
  
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      ofColor color;
      bool skip = false;
      
      float noise = ofNoise(j * noiseZoom, i * noiseZoom, slice * noiseZoom);
      
      for (int b = 0; b < 1 / bandSize; ++b) {
        if (noise >= b * bandSize && noise < (b + 1) * bandSize) {
          if (noise < bandMin || noise > bandMax) {
            skip = true;
            break;
          }
          color = b % 2 == 0 ? color1 : color2;
          
        }
      }
      
      if (!skip) {
        img.setColor(j * cellSize, i * cellSize, color);
      } else {
        // erase
        img.setColor(j * cellSize, i * cellSize, color1);
      }
      
    }
  }
  
  img.update();
}

void pbeshaiSchwartz1::draw(){
  ofSetColor(255);
  ofFill();
  img.draw(0, 0);
}
