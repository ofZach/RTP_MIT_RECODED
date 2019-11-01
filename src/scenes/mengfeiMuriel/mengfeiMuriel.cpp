
#include "mengfeiMuriel.h"

void mengfeiMuriel::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in mengfeiMuriel.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Mengfei Wang");
    setOriginalArtist("John Maeda");

    parameters.add(r.set("r", 200, 1, 1000));
    parameters.add(para.set("para", 0.25, 0.1, 1));

    //set settings of the font
    ofTrueTypeFontSettings settings("scenes/mengfeiMuriel/huaifangti.ttf",125);
    settings.antialiased = true;
    settings.dpi = 72;
    settings.direction = OF_TTF_LEFT_TO_RIGHT;
    settings.contours = false;
    settings.addRanges(ofAlphabet::Japanese);
    
    //load font once
    font.load(settings);
    
    loadCode("scenes/mengfeiMuriel/exampleCode.cpp");
}

void mengfeiMuriel::update(){
    
}

void mengfeiMuriel::draw(){
    
    ofBackground(255);
    ofSetColor(0);
    //move coordinate origin to the uper edge center
    ofPushMatrix();
    ofTranslate(dimensions.getWidth() / 2, 0);
    
    //set the number of rows
    /*int r = 200;*/
    //int y = 0;
    
    //set j's range
    //int jbegin = 0.7;
    //int jend = 40;
    /*float para = 0.25;*/
    
    //iterate through each row
    for (int i = 0; i < r; i++)
    {
        string text = u8"モリサワ";
        float fontWidth = font.stringWidth(text);
        float x = dimensions.getWidth()/ 2;
        int y = font.stringHeight(text);
        
        //locate the new row's starting point
        ofTranslate(0, y*0.9);
        font.drawString(text, -fontWidth / 2, 0);
        
        //the scale multiplier changes according to the number of rows
        float j = ofMap(i, 0, (r-1), 0.7, 40);
        float size = 1 - (float)para / j;
        ofScale(size, size, 1);
    }
    ofPopMatrix();
   
}
