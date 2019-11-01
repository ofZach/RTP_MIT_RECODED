
#include "karstenVasulka.h"

void karstenVasulka::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in karstenVasulka.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Karsten Schuhl");
    setOriginalArtist("The Vasulkas");

    loadCode("scenes/karstenVasulka/exampleCode.cpp");
    
    player.load("scenes/karstenVasulka/cam_480.mov");
    player.setSpeed(1.0);
    player.setVolume(0);
    player.play();
    player.setLoopState(OF_LOOP_NORMAL);
    
    parameters.add(phaseZ.set("phaseZ", 0.05, -1.0, 1.0));
    parameters.add(extrusionAmount.set("extrusionAmount", 10.0, 0.0, 50.0));
    
    lastTime = ofGetElapsedTimeMillis();
    
    int w = player.getWidth();
    int h = player.getHeight();
    
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            mesh.addVertex(ofPoint(x,y,0));
            mesh.addColor(ofFloatColor(0,0,0));
        }
    }
    
    for (int y = 0; y < h-1; y++){
        for (int x = 0; x < w-1; x++){
            mesh.addIndex(x+y*w);
            mesh.addIndex((x+1)+y*w);
            mesh.addIndex(x+(y+1)*w);
            
            mesh.addIndex((x+1)+y*w);
            mesh.addIndex((x+1)+(y+1)*w);
            mesh.addIndex(x+(y+1)*w);
        }
    }
    
    extrusionAmount = 50;
    
    windowSizeX = dimensions.getWidth();
    windowSizeY = dimensions.getHeight();
}

void karstenVasulka::update(){
    player.update();
       currentTime = ofGetElapsedTimeMillis();
       if (currentTime - lastTime > period){
           counter++;
           if(counter > 10){
               counter = 0;
           }
       }
       if (player.isFrameNew()){
           
           for (int i = 0; i < player.getWidth()*player.getHeight(); i++){
           
               ofFloatColor sampleColor(player.getPixels()[i*3]/255.f,
                                        player.getPixels()[i*3+1]/255.f,
                                        player.getPixels()[i*3+2]/255.f);
               
               ofVec3f tempVec = mesh.getVertex(i);
               if(effect == true){
                   tempVec.z = sin(i*phaseZ*0.001)*extrusionAmount;
                   tempVec.y = sin(i*0.001)*extrusionAmount;
                   tempVec.x = sin(i*0.001)*extrusionAmount;
               } else{
                   tempVec.z = sin(i*phaseZ*0.001)*extrusionAmount;
                    
               }
               mesh.setVertex(i, tempVec);
               mesh.setColor(i, sampleColor);
               
           }
       }
}

void karstenVasulka::draw(){
     ofSetColor(0);
        ofDrawRectangle(0, 0, windowSizeX, windowSizeY);
        cam.begin();
        ofPushMatrix();
        ofTranslate(-player.getWidth(), player.getHeight(), -player.getWidth());
        ofScale(2,-2,2);
        mesh.drawFaces();
        ofPopMatrix();
        cam.end();
}

