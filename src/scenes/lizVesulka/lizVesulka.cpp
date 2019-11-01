
#include "lizVesulka.h"

void lizVesulka::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in lizVesulka.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Lizbeth Barrios De La Torre");
    setOriginalArtist("Woody and Steina Vasulka");

    
    parameters.add( rotate.set("rotate", 0, 0, 5));
    parameters.add( rotate2.set("rotate2", 0, 0, 5));
    
    
    
    parameters.add( size.set("size", 200, 0, 450));
    
    loadCode("scenes/lizVesulka/exampleCode.cpp");
    
    TransitMovie.load("scenes/lizVesulka/transit.mov");
    TransitMovie.play();
}

void lizVesulka::update(){
    
}

void lizVesulka::draw(){
    
    ofRectangle rr(0, 0, 1200, 700);
    rr.scaleTo(dimensions, OF_SCALEMODE_FILL);
    TransitMovie.draw(rr);
    
    box.setPosition(dimensions.getWidth()*.5, dimensions.getWidth()*.50, 0);
    box.rotate(rotate, 1.0, 0.0, 0.0);
    box.rotate(rotate2, 0, 1.0, 0.0);
    
    box.draw();
    
    box.set( size );

}


