
#include "mengfeiWhitney.h"

void mengfeiWhitney::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in mengfeiWhitney.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Mengfei Wang");
    setOriginalArtist("John Whitney");

    
    parameters.add(n.set("n", 7, 2, 20));
    parameters.add(radiusX.set("radiusX", 200, 100, 300));
    parameters.add(radiusY.set("radiusY", 200, 100, 300));
    parameters.add(number.set("number", 15, 5, 100));
    
    
    loadCode("scenes/mengfeiWhitney/exampleCode.cpp");
}

void mengfeiWhitney::update(){
    
    
}

void mengfeiWhitney::draw(){
    
    ofBackground(0);
    ofSetColor(238, 168, 231);
    ofNoFill();
    
    float time = ofGetElapsedTimef();
    //get the center point of the window
    float centerX = dimensions.getWidth() * 0.5;
    float centerY = dimensions.getHeight() * 0.5;
    
    ////n affects the length of each side of the triangle
    //float n = 7;
    ////set the radius of the circular trajectory for triangles
    //float radiusX = 200;
    //float radiusY = 200;
    ////set the total number of triangles
    //int number = 15;
    
    //draw a group of triangles moving couter-clockwise
    for (int i = 0; i < number; i++)
    {
        //get the center point coordinates of triangles where the point moves counter-clockwise.
        float x0 = centerX + radiusX * sin(time+i);
        float y0 = centerY + radiusY * cos(time+i);
        //draw a triangle by giving the coordinates of three vertexes
        ofDrawTriangle(x0 - 1.732 * i*n, y0 - i*n, x0 + 1.732*i*n, y0 - i*n, x0, y0 + 2 * i*n);
    }
    
    
    ofSetColor(101, 25, 68);
    ofNoFill();
    
    //draw a group of triangles moving clockwise
    for (int j = 0; j < number; j++)
    {
        //get the center point coordinates of triangles where the point moves clockwise.
        float x0 = centerX + radiusX * sin(time + j+180);
        float y0 = centerY + radiusY * cos(time + j+180) * (-1);
        //draw a triangle by giving the coordinates of three vertexes
        ofDrawTriangle(x0 - 1.732 * j*n, y0 - j * n, x0 + 1.732*j*n, y0 - j * n, x0, y0 + 2 * j*n);
    }
    
   
}
