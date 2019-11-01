
#include "gauravVera.h"

void gauravVera::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in gauravVera.h
    // parameters.add(param.set("param", 5, 0, 100));
    
    
    
    //    int vr = 20;  //vertical random range (range 0-50)
    //    int hr = 20;  //horizontal random range (range 0-50)
    //    int d = 60;  //rect base size (range 40-120)
    //    int s = 100;  //spacing between rectangles (range 50-150)
    //
    
     parameters.add(vr.set("vr", 20, 0, 50));
     parameters.add(hr.set("hr", 20, 0, 50));
     parameters.add(d.set("d", 60, 40, 120));
     parameters.add(s.set("s", 100, 50, 150));

    setAuthor("Gaurav Rajaram Patekar");
    setOriginalArtist("Vera Molnar");

    loadCode("scenes/gauravVera/exampleCode.cpp");
}

void gauravVera::update(){
    
}

void gauravVera::draw(){
    
    ofSetColor(240,235,230);
    ofFill();
    ofRect(0,0,dimensions.width,dimensions.height);
    ofNoFill();
    //ofSeedRandom(s);
    
    ofSeedRandom((int)(ofGetSeconds()*1000));
    for(int k=0; k<instances; k++){
        for(int i=0; i<6; i++){
            for(int j=0; j<6; j++){
                
                
                
                ofPushMatrix();
                ofTranslate(s*i+(dimensions.width-s*5.-d)/2.,s*j+(dimensions.width-s*5.-d)/2.);
                ofSetColor(120, ofRandom(0,100), ofRandom(0,100));
                
                ofBeginShape();
                
                ofVertex(ofRandom(-hr,hr), ofRandom(-vr,vr));
                ofVertex(d+ofRandom(-hr,hr), ofRandom(-vr,vr));
                ofVertex(d+ofRandom(-hr,hr), d+ofRandom(-vr,vr));
                ofVertex(ofRandom(-hr,hr), d+ofRandom(-vr,vr));
                ofEndShape(true);
                ofPopMatrix();
                
            }
        }
    }
    
}
