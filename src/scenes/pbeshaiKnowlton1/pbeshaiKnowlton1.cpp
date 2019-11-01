
#include "pbeshaiKnowlton1.h"

void pbeshaiKnowlton1::setup(){
  
  // setup parameters
  // if your original code use an ofxPanel instance dont use it here, instead
  // add your parameters to the "parameters" instance as follows.
  // param was declared in pbeshaiKnowlton1.h
  // parameters.add(param.set("param", 5, 0, 100));
  parameters.add(param1.set("cellSize", 20, 14, 40));
  parameters.add(param2.set("blobbiness", 0.5, 0.0, 1.0));
  parameters.add(param3.set("edgeWarp", 0, -0.002, 0.002));
  parameters.add(param4.set("rotate", 0, -HALF_PI * 0.5, HALF_PI * 0.5));
  
  
  setAuthor("Peter Beshai");
  setOriginalArtist("Kenneth Knowlton");
  
  loadCode("scenes/pbeshaiKnowlton1/exampleCode.cpp");
  
  player.load("scenes/pbeshaiVideo1/sample_footage_600.mp4");
  player.setSpeed(1.0);
  player.setVolume(0);
  player.play();
  player.setLoopState(OF_LOOP_NORMAL);
}

void pbeshaiKnowlton1::update(){
  player.update();
}

void drawPebble(float size, float rMin = 3, float rMax = 100, int numSegments = 100, float noiseSmooth = 0.8, float noiseMin = 0, float noiseMax = 1) {
  float rBase = ofMap(size, 0, 1, rMin, rMax);
  float noiseOffset = ofRandom(0, 1000);
  
  ofPath path;
  for (int i = 0; i < numSegments; ++i) {
    float theta = TWO_PI * i / ((float) numSegments);
    float noise = ofMap(ofNoise(cos(theta) * noiseSmooth + noiseOffset, sin(theta) * noiseSmooth), 0, 1, noiseMin, noiseMax);
    float r = rBase* noise;
    
    float x = r * cos(theta);
    float y = r * sin(theta);
    if (i == 0) {
      path.moveTo(x, y);
    } else {
      path.lineTo(x, y);
    }
  }
  path.close();
  path.draw();
}

void pbeshaiKnowlton1::draw(){
  ofBackground(0);
  ofSetColor(255);
  //    grabber.draw(640,0);
  
  
  float width = player.getWidth();
  float height = player.getHeight();
  
  
  ofSeedRandom(0);
  
  float time = ofGetElapsedTimef();
  float cellSize = param1; //ofMap(sin(time * 0.5 + PI), -1, 1, 20, 28);
  float noiseSmooth = param2; ////ofMap(sin(time), -1, 1, 0.1, 0.8);
  int numPoints = (width * height) / cellSize;
  
  // theta determines the spiral of the layout
  float theta = PI * (3 - sqrt(5));
  float pointRadius = cellSize / 2.0;
  ofPushMatrix();
  ofTranslate(width / 2.0, height / 2.0);
  float thetaOffset = param3; //ofMap(sin(time * 0.1 + 3.75), -1, 1, -0.002, 0.002);
  float phylloRotationTheta = param4; //ofMap(sin(time * 0.5 + 4.3), -1, 1, -HALF_PI, HALF_PI);
  for (int i = 0; i < numPoints; i += 1) {
    int index = i;
    float thetaOffsetAmount = i / ((float)numPoints);
    float phylloX = pointRadius * sqrt(index) * cos(index * (theta + thetaOffset * thetaOffsetAmount));
    float phylloY = pointRadius * sqrt(index) * sin(index * (theta + thetaOffset * thetaOffsetAmount));
    
    // apply rotation
    float x = phylloX * cos(phylloRotationTheta) - phylloY * sin(phylloRotationTheta);
    float y = phylloX * sin(phylloRotationTheta) + phylloY * cos(phylloRotationTheta);
    
    
    float imageX = (x + width / 2.0);
    float imageY = (y + height / 2.0);
    
    // skip for efficiency
    if (imageX < -cellSize || imageX > width + cellSize || imageY < -cellSize || imageY > height + cellSize) {
      continue;
    }
    
    
    
    ofColor color = player.getPixels().getColor(
                                                 ofClamp(floor(imageX), 0, width - 1),
                                                 ofClamp(floor(imageY), 0, height -1 ));
    float brightness = color.getBrightness();
    ofPushMatrix();
    ofTranslate(x, y);
    //        ofDrawCircle(0, 0, pointRadius * 0.8);
    
    ofTranslate(pointRadius, pointRadius);
    drawPebble(brightness / 255.0, cellSize * 0.02, cellSize * 0.4, 30,
               noiseSmooth,
               0.6, 1.5);
    
    ofPopMatrix();
  }
  ofPopMatrix();
  
}
