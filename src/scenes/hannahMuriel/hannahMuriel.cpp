
#include "hannahMuriel.h"

void hannahMuriel::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in mitScene1.h
    //parameters.add(param.set("param", 5, 0, 100));

    parameters.add(speed.set("speed", 0, 0.0, 2.0));
    
    setAuthor("Hannah Lienhard");
    setOriginalArtist("Muriel Cooper");

    loadCode("scenes/hannahMuriel/exampleCode.cpp");
}

void hannahMuriel::update(){
    
}

void hannahMuriel::draw(){
    ofBackground(229,229,222);

    float  time = ofGetElapsedTimef()*speed;

    for (int i = 100; i < 600; i = i+100+time) {
        for (int j = 150; j < 500; j = j+100+time){
            for (int z = 200; z < 500 ; z = z+100+time){
                for (int w = 250; w < 400 ; w = w+100+time){
                    for (int u = 300; u < 400 ; u = u+100+time){
                        
                        ofPushMatrix();
                        ofTranslate(90,40);
                        ofSetColor(108,101,67); //green
                        ofDrawEllipse(100-time,10+i,90,90);
                        ofDrawBezier(95-time, -35+i, 170-time, -65+i, 130-time, -65+i, 145-time, 10+i);
                        ofSetColor(59-time, 119, 201); //blue
                        ofDrawEllipse(100-time,10+i,43,43);
                        
                        ofSetColor(108,101,67); //green
                        ofDrawEllipse(200-time,10+j,90,90);
                        ofDrawBezier(195-time, -35+j, 270-time, -65+j, 230-time, -65+j, 245-time, 10+j);
                        ofSetColor(59, 119, 201); //blue
                        ofDrawEllipse(200-time,10+j,43,43);
                        
                        ofSetColor(108,101,67); //green
                        ofDrawEllipse(300-time,10+z,90,90);
                        ofDrawBezier(295-time, -35+z, 370-time, -65+z, 330-time, -65+z, 345-time, 10+z);
                        ofSetColor(59, 119, 201); //blue
                        ofDrawEllipse(300-time,10+z,43,43);
                        
                        ofSetColor(108,101,67); //green
                        ofDrawEllipse(400-time,10+w,90,90);
                        ofDrawBezier(395-time, -35+w, 470-time, -65+w, 430-time, -65+w, 445-time, 10+w);
                        ofSetColor(59, 119, 201); //blue
                        ofDrawEllipse(400-time,10+w,43,43);
                        
                        ofSetColor(108,101,67); //green
                        ofDrawEllipse(500-time,10+u,90,90);
                        ofDrawBezier(495-time, -35+u, 570-time, -65+u, 530-time, -65+u, 545-time,10+u);
                        ofSetColor(59, 119, 201); //blue
                        ofDrawEllipse(500-time,10+u,43,43);
                        
                        ofPopMatrix();
                    }
                }
            }
        }
    }
}
