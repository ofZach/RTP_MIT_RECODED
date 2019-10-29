
#include "pbeshaiVideo1.h"

void pbeshaiVideo1::setup(){
  
  // setup parameters
  // if your original code use an ofxPanel instance dont use it here, instead
  // add your parameters to the "parameters" instance as follows.
  // param was declared in pbeshaiVideo1.h
  parameters.add(param1.set("slitSpeed", 2, 1, 8));
  parameters.add(param2.set("size", 6, 4, 20));
  parameters.add(param3.set("yImpact", 60, 20, 100));
  parameters.add(param4.set("zImpact", 20, 0, 200));
  
  
  setAuthor("Peter Beshai");
  setOriginalArtist("Woody and Steina Vasulka");
  
  loadCode("scenes/pbeshaiVideo1/exampleCode.cpp");
  
  player.load("scenes/pbeshaiVideo1/sample_footage_600.mp4");
  player.setSpeed(0.75);
  player.setVolume(0);
  player.play();
  player.setLoopState(OF_LOOP_NORMAL);
  float width = player.getWidth();
  float height = player.getHeight();
  img.allocate(width, height, OF_IMAGE_COLOR);
}

void pbeshaiVideo1::update(){
  player.update();
  ofPixels & currPixels = player.getPixels();
  float width = player.getWidth();
  float height = player.getHeight();
  
  int speed = param1;
  // shuffle the frames
  for (int i = 0; i < speed || frames.size() < 60; ++i) {
    ofImage temp;
    temp.setImageType(OF_IMAGE_COLOR);
    frames.push_back(temp);
    frames.back().setUseTexture(false);
    frames.back().setFromPixels(currPixels);
    if (frames.size() > 60){
      frames.erase(frames.begin());
    }
  }
  
  // for each line in the camera
  for (int j = 0; j < height; j++) {
    
    // find the frame for that line
    int whichFrame = ofMap(j, 0, height, 0, frames.size());
    if (whichFrame < frames.size()) {
      for (int i = 0; i < width; i++){
        img.setColor(i, j, frames[whichFrame].getColor(i, j));
      }
    }
  }
  
  img.update();
}

void pbeshaiVideo1::draw(){
  
  float xInc = param2;
  int yInc = 2;
  float yImpact = param3;
  float zImpact = param4;
  float xRotateDeg = zImpact / 3.0;
  
  ofSetColor(255);
  //  player.draw(player.getWidth(), 0);
  //  img.draw(img.getWidth(), 0);
  ofPushMatrix();
  float dimWidth = dimensions.getWidth();
  float dimHeight = dimensions.getHeight();
  
  ofTranslate(0, dimHeight / 2);
  
  ofRotateXDeg(xRotateDeg);
  ofTranslate(0, -dimHeight / 2);
  float height = img.getHeight();
  float width = img.getWidth() ;
  ofScale(dimWidth / width, dimHeight / height);
  
  float time = ofGetElapsedTimef();
  float yMaxOffset = ofMap(sin(time), -1, 1, yImpact * 0.66, yImpact);
  float zMaxOffset = zImpact;
  
  ofMesh mesh;
  
  int numXPoints = floor((width - 1) / xInc);
  // need numXPoints to be divisible by 3
  numXPoints -= numXPoints % 3;
  
  for (int i = 0; i < img.getHeight(); i+= yInc){
    for (int j = 0; j < numXPoints; ++j){
      float x = j * xInc;
      float yRaw = i;
      ofColor col = img.getPixels().getColor(x,yRaw);
      int brightness = col.getBrightness();
      float y = yRaw + ofMap(brightness, 0, 255, 0, yMaxOffset);
      float z = ofMap(brightness, 0, 255, 0, zImpact);
      mesh.addVertex(ofPoint(x, y, z));
      mesh.addColor(ofColor(
                            sin(time + yRaw * 0.01) * 100 + 155,
                            cos(time + x * 0.01) * 100 + 155,
                            sin(time * 3 + x * 0.01) * 100 + 155
                            ));
      
    }
    
    mesh.draw();
  }
  ofPopMatrix();
}
