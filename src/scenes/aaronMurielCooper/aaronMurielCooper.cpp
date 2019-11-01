
#include "aaronMurielCooper.h"

// based on a book cover by muriel cooper
// the mathematical sciences
// a collection of essays

void aaronMurielCooper::setup(){
  
    // setup parameters
    parameters.add(numberRows.set("numberRows", 4, 1, 8));
    parameters.add(depth.set("depth", 25, 0, 50));
    parameters.add(strokeWidth.set("strokeWidth", 3, 1, 5));

    setAuthor("aaron montoya-moraga");
    setOriginalArtist("Muriel Cooper");
    
    // load fonts
    caslonBold10.load("fonts/LibreCaslonText-Bold.ttf", 20);
    caslonRegular10.load("fonts/LibreCaslonText-Regular.ttf", 20);
    caslonRegular06.load("fonts/LibreCaslonText-Regular.ttf", 12);

    // load pseudocode
    loadCode("scenes/aaronMurielCooper/exampleCode.cpp");
}

void aaronMurielCooper::update(){
    
}

void aaronMurielCooper::draw(){
    
    float offsetY = dimensions.getHeight()/2;
    
    ofPushStyle();
    
    // yellow, with fill
    ofSetColor(250, 200, 0);
    ofFill();
    
    // yellow background
    ofDrawRectangle(0,0,dimensions.getWidth(), dimensions.getHeight());
    
    // black, with fill
    ofSetColor(0, 0, 0);
    ofFill();
    
    // text upper left
    ofSetLineWidth(strokeWidth);
    caslonBold10.drawString("The\nMathematical Sciences", 1*dimensions.getWidth()/10, 1*dimensions.getHeight()/10);
    
    // text upper right
    caslonRegular10.drawString("A  Collection of\nEssays", 6*dimensions.getWidth()/10, 1*dimensions.getHeight()/10);
    
    // text lower left
    caslonRegular06.drawString("Edited by the Committee on Support of\nResearch in the Mathematical Sciences with\nthe Collaboration of George A. W. Boehm", 1*dimensions.getWidth()/10, 3*dimensions.getHeight()/10);
    
    // square size is as big as number of rows+1
    // the extra 1 is used for margins
    float rectSizeX = dimensions.getWidth()/(numberRows+1);
    float rectSizeY = 0.5*dimensions.getHeight()/(numberRows+1);
    
    // upper row has as many squares as numberRows
    for (int i = 0; i < numberRows; i++) {
        // draw as many squares on this row as each
        for (int j = 0; j < numberRows-i; j++) {
            
            float originX = rectSizeX/2+j*rectSizeX;
            float originY = offsetY+i*rectSizeY;
            
            // black no fill
            ofSetColor(0, 0, 0);
             ofNoFill();
            
            // stroke size
            ofSetLineWidth(strokeWidth);
            
            // original rectangle
            ofDrawRectangle(originX, originY, rectSizeX, rectSizeY);
            
            // rectangle offset to right and above
            ofDrawRectangle(originX + depth, originY - depth, rectSizeX, rectSizeY);
            
            // light blue color
            ofSetColor(210, 220, 210);
            
            // lines between squares
            // upper left
            ofDrawLine(originX, originY, originX + depth, originY - depth);
            // upper right
            ofDrawLine(originX + rectSizeX, originY, originX + rectSizeX + depth, originY - depth);
            // lower left
            ofDrawLine(originX, originY + rectSizeY, originX + depth, originY + rectSizeY - depth);
            // lower right
            ofDrawLine(originX + rectSizeX, originY + rectSizeY, originX + rectSizeX + depth, originY + rectSizeY - depth);
        }
    }
    ofPopStyle();
}
