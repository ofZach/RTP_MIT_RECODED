
#include "mengfeiKen.h"

void mengfeiKen::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in mengfeiKen.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Mengfei Wang");
    setOriginalArtist("Ken Knowlton");

    parameters.add(gap.set("gap", 20, 10, 100));
    parameters.add(threshold.set("threshold", 50, 0, 255));
    
    player.load("scenes/pbeshaiVideo1/sample_footage_600.mp4");
    player.play();
    //grabber.setup(1080, 768);
    font.load("scenes/mengfeiKen/framd.ttf", 10);

    loadCode("scenes/mengfeiKen/exampleCode.cpp");
}

void mengfeiKen::update(){
    
    player.update();
}

void mengfeiKen::draw(){
    
    
    for (int i = 0; i < player.getWidth(); i += gap)
    {
        for (int j = 0; j < player.getHeight(); j += gap)
        {
            ofColor color = player.getPixels().getColor(i, j);
            float brightness = color.getBrightness();
            
            ofSetColor(color);
            
            if (brightness > threshold)
            {
                //ofDrawCircle(i, j, 10);
                font.drawString("Create", i, j);
                /*float r = ofMap(brightness, 127, 255, 0, 50);
                 ofDrawTriangle(i, j, (i - r), j, i, (j + r));*/
            }
        }
    }
    
}
