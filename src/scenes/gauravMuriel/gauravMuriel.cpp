
#include "gauravMuriel.h"

void gauravMuriel::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in gauravMuriel.h
    // parameters.add(param.set("param", 5, 0, 100));

      setAuthor("Gaurav Rajaram Patekar");
    setOriginalArtist("Muriel Cooper");

    
    parameters.add(scaleB.set("scaleB", 1.2, 0.5, 1.3));
    parameters.add(scaleS.set("scaleS", 0.3, 0.2, 0.8));

    loadCode("scenes/gauravMuriel/exampleCode.cpp");
}

void gauravMuriel::update(){
    
}

void gauravMuriel::draw(){
    
    ofSetColor(10,170,50);
    ofFill();
    ofRect(0,0,dimensions.width,dimensions.height);
    float width = dimensions.width;
    float height = dimensions.height;
    
    
    for(int j=-3; j<4; j++){
        for(int k=-3; k<4; k++){
            ofPushMatrix();
            ofTranslate(width/2 + j*width/4, height/2 + k*height/4);
            ofSetColor(60,40,170);
            ofFill();
            ofScale(scaleB,scaleB);
            ofRotateZ(2*PI*sin(theta) * RAD_TO_DEG);
            for(int i=0; i<4; i++){
                ofRotateZ(i*PI/4*RAD_TO_DEG);
                ofRect(-w,-h,2*w,2*h);
            }
            ofPopMatrix();
        }
    }
    
    for(int j=-3; j<4; j++){
        for(int k=-3; k<4; k++){
            ofPushMatrix();
            ofTranslate(width/2 + j*width/4 + width/8, height/2 + k*height/4 + height/8);
            ofSetColor(250,250,250);
            ofScale(scaleS,scaleS);
            ofRotateZ(-2*PI*sin(theta+PI/2) * RAD_TO_DEG);
            for(int i=0; i<4; i++){
                ofRotateZ(-sin(theta+PI/2) * RAD_TO_DEG );
                ofRect(-w,-h,2*w,2*h);
            }
            ofPopMatrix();
        }
    }
    
    theta += 0.002;
}
