//
//  ethanMolnarScene.cpp
//  RTP_MIT_RECODED
//
//  Created by Ethan Nevidomsky on 10/29/19.
//

#include "ethanMolnarScene.h"


void ethanMolnarScene::setup(){
    
    density.set("Density", .7, 0, 1);
    side_length.set("Side Length", 25, 5, 50);
    random.set("Random", 5, 0, 20);
    inc.set("Loop Tightness", .4, 0, .5);
    
    
    parameters.add(density);
    parameters.add(side_length);
    parameters.add(random);
    parameters.add(inc);
    
    setAuthor("Ethan Nevidomsky");
    setOriginalArtist("Vera Molnar");
    
    loadCode("scenes/ethanMolnarScene/exampleCode.cpp");
    
    //Affects size of squares
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            //Affects density
            float loop_inc = .05;
            int x = 29+55*j;
            int y = 29+55*i;
            int counter = 0;
            //random affects amount of squares
            for(float loop = 1; loop < ofRandom(40)+2; loop+=loop_inc){
                if(ofRandomuf()>(1-density)){
                    ofPolyline line; line.addVertex(ofVec3f(x+(side_length+ofRandom(random))/loop,y-(side_length+ofRandom(random))/loop,0));
                    line.lineTo(x+(side_length+ofRandom(random))/loop,y+(side_length+ofRandom(random))/loop,0);
                    line.lineTo(x-(side_length+ofRandom(random))/loop,y+(side_length+ofRandom(random))/loop,0);
                    line.lineTo(x-(side_length+ofRandom(random))/loop,y-(side_length+ofRandom(random))/loop,0);
                    line.close();
                    lines.push_back(line);
                    counter++;
                    loop_inc+=(.5-inc);
                }
            }
            lineSizes.push_back(counter);
        }
    }
    
}

void ethanMolnarScene::update(){}

void ethanMolnarScene::draw(){
    ofBackground(225, 220, 215);
    
    ofSetColor(0);
    
    lines.erase(lines.begin(), lines.begin() + lineSizes[0]);
    lineSizes.pop_front();
    float loop_inc = .05;
    int x = 29+55*x_counter;
    int y = 29+55*y_counter;
    int counter = 0;
    for(float loop = 1; loop < ofRandom(40)+2; loop+=loop_inc){
        if(ofRandomuf()>(1-density)){
            ofPolyline line; line.addVertex(ofVec3f(x+(side_length+ofRandom(random))/loop,y-(side_length+ofRandom(random))/loop,0));
            line.lineTo(x+(side_length+ofRandom(random))/loop,y+(side_length+ofRandom(random))/loop,0);
            line.lineTo(x-(side_length+ofRandom(random))/loop,y+(side_length+ofRandom(random))/loop,0);
            line.lineTo(x-(side_length+ofRandom(random))/loop,y-(side_length+ofRandom(random))/loop,0);
            line.close();
            counter++;
            lines.push_back(line);
            loop_inc+=(.5-inc);
        }
    }
    lineSizes.push_back(counter);
    if(x_counter==12)
        y_counter = (y_counter + 1) % 13;
    x_counter = (x_counter + 1) % 13;
    
    for(ofPolyline l: lines)
        l.draw();
}
