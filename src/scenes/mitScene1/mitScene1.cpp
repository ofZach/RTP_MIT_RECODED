
#include "mitScene1.h"

void mitScene1::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in mitScene1.h
    //parameters.add(param.set("param", 5, 0, 100));

    parameters.add(radius.set("radius", 5, 0, 1000));
    
    setAuthor("Zach Lieberman");
    setOriginalArtist("Vera Molnar");

    loadCode("scenes/mitScene1/exampleCode.cpp");
}

void mitScene1::update(){
    
}

void mitScene1::draw(){
    
    ofDrawCircle(dimensions.getCenter(), radius);
    ofLine(0,0, dimensions.getWidth(), dimensions.getHeight());
}
