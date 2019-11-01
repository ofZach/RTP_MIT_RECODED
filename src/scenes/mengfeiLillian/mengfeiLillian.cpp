
#include "mengfeiLillian.h"

void mengfeiLillian::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in mengfeiLillian.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Mengfei Wang");
    setOriginalArtist("Lillian Schwartz");

    
    parameters.add(r.set("seedrandom", 5, 1, 100));
    parameters.add(gap.set("gap", 10, 1, 50));
    parameters.add(noise1.set("noise1", 5, 1, 17));
    parameters.add(noise2.set("noise2", 20, 10, 35));
    
    loadCode("scenes/mengfeiLillian/exampleCode.cpp");
}

void mengfeiLillian::update(){
    
}

void mengfeiLillian::draw(){
    
    ofBackground(0);
    ofSeedRandom(r);
    
    //iterate through pixels in each row and column
    for (int i = 0; i < dimensions.getWidth(); i += gap)
    {
        for (int j = 0; j < dimensions.getHeight(); j += gap)
        {
            //select pixels using a criterias
            if (ofRandom(10)*sin(5*i) + 5*cos(10*j) <= noise1)
            {
                //set up the color for a small rectangle
                ofSetColor(0);
                //draw rectangle
                ofDrawRectangle(i, j, 10, 10);
            }
            else if (28*sin(20 * i) + 6 * cos(50 * j) > noise2)
            {
                ofSetColor(255);
                ofDrawRectangle(i, j, 30, 30);
            }
            else
            {
                ofSetColor(127);
                ofDrawRectangle(i, j, 10, 10);
            }
        }
    }
    
}
