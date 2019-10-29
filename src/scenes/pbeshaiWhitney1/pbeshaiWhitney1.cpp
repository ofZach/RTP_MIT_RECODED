
#include "pbeshaiWhitney1.h"

void pbeshaiWhitney1::setup(){
  
  // setup parameters
  // if your original code use an ofxPanel instance dont use it here, instead
  // add your parameters to the "parameters" instance as follows.
  // param was declared in pbeshaiWhitney1.h
  // parameters.add(param.set("param", 5, 0, 100));
  //  parameters.add(param1.set("fontSize", 170, 100, 300));
  parameters.add(param1.set("radius", 3, 2.5, 500));
  parameters.add(param2.set("spread", 0, 0, 1));
  parameters.add(param3.set("twist1", 0, 0, 500));
  parameters.add(param4.set("twist2", 0.02, 0, 0.08));
  //  parameters.add(param3.set("brightnessFactor", 0.2, 0.5, 0.01));
  //  parameters.add(param4.set("zImpact", 20, 0, 200));
  //  float radius = param2; //ofMap(t * t, 0, 1, 3, 250);
  //  float brightnessFactor = param3; //ofMap(ofClamp(sqrt(t), 0, 1), 0, 1, 0.2, 0.03);
  
  
  setAuthor("Peter Beshai");
  setOriginalArtist("John Whitney Sr.");
  
  loadCode("scenes/pbeshaiWhitney1/exampleCode.cpp");
  
  
  float fontSize = 170;
  ofBackground(0);
  font.load("scenes/pbeshaiWhitney1/PinyonScript-Regular.ttf", fontSize, true, false, true);
  
  font.setLineHeight(fontSize);
  
  //    text = "LOVE";
  //    font.setLetterSpacing(1.3);
  text = "1961";
  font.setLetterSpacing(0.9);
  
  // add some buffer to the edges
  float fullStringWidth = font.stringWidth(text) + fontSize;;
  
  textFbo.allocate(fullStringWidth, fontSize);
  
  
  textFbo.begin();
  ofClear(0,0,0);
  ofSetColor(255);
  font.drawString(text, fontSize / 2.0, fontSize); // offset x for buffer
  textFbo.end();
  textFbo.readToPixels(textPixels);
  
  //    cout << textPixels.getColor(mouseX, mouseY) << endl;
  for (int i = 0; i < fullStringWidth; ++i) {
    for (int j = 0; j < fontSize; ++j) {
      ofColor pixColor = textPixels.getColor(i, j);
      float brightness = pixColor.getBrightness() / 255.0; // 0 to 255 -> 0 to 1
      
      if (brightness > 0) {
        textPoints.push_back(glm::vec3(i, j, brightness));
      }
    }
  }
}

void pbeshaiWhitney1::update(){
  
}

void pbeshaiWhitney1::draw(){
  ofColor blue(60, 150, 255);
  //    ofColor blue(5, 100, 200);
  ofColor green(110, 237, 100);
  //    ofColor green(50, 200, 50);
  ofColor greenBg(44, 119, 92, 150);
  ofColor greenBg2(greenBg.r, greenBg.g, greenBg.b, 100);
  ofColor blueBg(25, 65, 103, 150);
  ofColor blueBg2(blueBg.r, blueBg.g, blueBg.b, 100);
  
  float time = ofGetElapsedTimef();
  float t = abs(sin(time * 0.3));
  t = t < 0.05 ? 0 : ofMap(t, 0.05, 1, 0, 1); // hang at 0 a bit
  
  float fontSize = 170;
  float width = dimensions.getWidth();
  float height = dimensions.getHeight();
  
  // draw bg gradient
  ofMesh temp;
  temp.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
  temp.addVertex(ofPoint(0, 0));
  temp.addColor(greenBg2);
  temp.addVertex(ofPoint(0, height));
  temp.addColor(greenBg2);
  temp.addVertex(ofPoint(width * 0.33, 0));
  temp.addColor(greenBg);
  temp.addVertex(ofPoint(width * 0.33, height));
  temp.addColor(greenBg);
  temp.addVertex(ofPoint(width * 0.66, 0));
  temp.addColor(blueBg);
  temp.addVertex(ofPoint(width * 0.66, height));
  temp.addColor(blueBg);
  temp.addVertex(ofPoint(width, 0));
  temp.addColor(blueBg2);
  temp.addVertex(ofPoint(width, height));
  temp.addColor(blueBg2);
  temp.draw();
  
  
  
  ofPushMatrix();
  ofTranslate(width / 2, height / 2);
  float fullStringWidth = font.stringWidth(text) + fontSize; // add buffer
  float part1StringWidth = font.stringWidth(text.substr(0, round(text.length() / 2.0))) + fontSize / 2.0; // add buffer
  ofPushMatrix();
  ofTranslate(-fullStringWidth / 2, -fontSize / 2);
  ofSetColor(blue);
  //    textFbo.draw(0, 0);
  ofSetColor(green);
  ofSetCircleResolution(100);
  
  ofNoFill();
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofDisableDepthTest();
  ofSeedRandom(0);
  //    t = mouseX / width;
  
  float radius = param1; //ofMap(t * t, 0, 1, 3, 250);
  float randomLevel = param2;
  float sinLevel = param3;
  //  float brightnessFactor = ofMap(sqrt(radius), 1.6, 16, 0.2, 0.03, true);
  float brightnessFactor = ofMap(radius, 3, 30, 0.2, 0.03, true);
  
  //    float brightnessFactor = mouseX * 0.001;
  //    ofSetLineWidth(mouseY * 0.01);
  for (int i = 0; i < textPoints.size(); ++i) {
    glm::vec3 point = textPoints[i];
    
    if (point.x <= part1StringWidth) {
      ofSetColor(green * brightnessFactor);
    } else {
      ofSetColor(blue * brightnessFactor);
    }
    //
    //        ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    //
    float noiseZoom = param4;
    ofDrawCircle(
                 textPoints[i].x + randomLevel * ofRandom(-radius, radius) + sinLevel * (ofNoise(noiseZoom * t, noiseZoom * textPoints[i].x, noiseZoom * textPoints[i].y) - 0.5),
                 textPoints[i].y + randomLevel * ofRandom(-radius, radius) + sinLevel * (ofNoise(15 + noiseZoom * t, noiseZoom * textPoints[i].x, noiseZoom * textPoints[i].y) - 0.5),
                 radius);
  }
  
  ofPopMatrix();
  ofPopMatrix();
}
