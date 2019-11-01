
#include "mengfeiVera.h"

void mengfeiVera::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in mengfeiVera.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Mengfei Wang");
    setOriginalArtist("Vera Molnar");

    parameters.add(color.set("color", 255, 0, 255));
    parameters.add(seed.set("seed", 50, 0, 100));
    parameters.add(vertexnumber.set("vertexnumber", 18, 1, 30));

    loadCode("scenes/mengfeiVera/exampleCode.cpp");
}

void mengfeiVera::update(){
    
}

void mengfeiVera::draw(){
    
    
    ofBackground(0);
    ofSetColor(color);
    //cout << pl.size() << endl;
    
    ofPolyline pl;
    //pl.clear();
    pl.addVertex(100, 150);//beginning position of the whole drawing
    ofSeedRandom(seed);//change according to the x coordinate of mouse
    
    int i = 0;
    
    ofPushMatrix();
    
    ofScale((float)dimensions.getWidth() / 1050.0 );
    
    for (int i = 0; i < 5; i++)//iterating through each row
    {
        for (int j = 0; j < 5; j++)//iterating through each column
        {
            for (int k = 0; k < vertexnumber; k++)//k is the number of notes in each small square
            {
                if (i % 2 == 0)//for the row with even index (2, 4)
                {
                    int rx = (int)ofRandom(3.9);// each small square has 4 rows and 4 columns, this syntax is to get a random integer number in the range(0,4) to be the x coordinate of a point.
                    int ry = (int)ofRandom(3.9);
                    pl.addVertex(50 + j * 200 + (double)rx * 50, 50 + i * 200 + (double)ry * 50);//add new point to the polyline.
                }
                else// for the row with odd index (1, 3, 5)
                {
                    int rm = (int)ofRandom(3.9);
                    int rn = (int)ofRandom(3.9);
                    pl.addVertex(1000 - j * 200 - (double)rm * 50, 50 + i * 200 + (double)rn * 50);
                }
            }
            
            
        }
        
    }
    pl.draw();
    
    ofPopMatrix();
    
}
