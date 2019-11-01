
#include "karstenJohnMaeda.h"

void karstenJohnMaeda::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in karstenJohnMaeda.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Karsten Schuhl");
    setOriginalArtist("John Maeda");

   
    parameters.add(freq.set("freq", 0.1, 0.0, 1.0));
    parameters.add(amp.set("amp", -1, -4.0, 4.0));
    parameters.add(noiseFactor.set("noiseFactor", 0.05, 0.0, 0.1));
    parameters.add(rot.set("rot", 0.271, 0.0, 1.0));
    
    ofTrueTypeFontSettings settings("scenes/karstenJohnMaeda/nicokaku_v1.ttf", 264);
    settings.antialiased = true;
    settings.direction = OF_TTF_LEFT_TO_RIGHT;
    settings.contours = true;
    settings.addRange(ofUnicode::Katakana);
    fff.load(settings);
    
    loadCode("scenes/karstenJohnMaeda/exampleCode.cpp");
    
    
}

void karstenJohnMaeda::update(){
    
}

void karstenJohnMaeda::draw(){
    
        float xBegin = 0.0;
        float yBegin = 0.0;
        float width = dimensions.getWidth();
        float height = dimensions.getHeight();
        int repeatLetters = 350;
        
        ofSetColor(245);
        ofFill();
        ofDrawRectangle(0, 0, width, height);
        ofSetColor(0);

        string logo = "モリサワ"; //MO-RI-SA-WA
        ofRectangle bounds = fff.getStringBoundingBox(logo, 0.0, 0.0);
        
        xBegin = (width-bounds.width)/2-10;
        yBegin = (bounds.height+3);
        vector < ofPath > paths = fff.getStringAsPoints(logo, true, false);
            
        ofNoFill();
        ofSetLineWidth(1);
        
        ofPushMatrix();
        ofTranslate(xBegin,yBegin);
        int character = paths.size();
        for (int i = 0; i < character; i++){
            ofPath path = paths[i];
            vector < ofPolyline > lines = path.getOutline();
            float xPos = 0.0;
            ofPushMatrix();
            for(int j = 0; j < repeatLetters; j++ ){
                float yPos = (j+1)/9.2;
                
                if(i >= character - 2){
                    xPos = amp * sin(-j * freq) * ofNoise(j* noiseFactor, i * 1.39);
                } else{
                    xPos = amp * sin(j * freq) * ofNoise(j* noiseFactor, i * 0.047);
                }
                ofTranslate(xPos, yPos);
                ofRotateZDeg(ofSignedNoise(rot, i));
                
                for (int k = 0; k < lines.size(); k++){
                    ofPolyline line = lines[k];
                    ofSetColor(80, 80, 80, ofMap(yPos, 0, 16 , 255, 0));
                    lines[k].draw();
                }
            }
            ofPopMatrix();
        }
        
        ofSetColor(0);
        fff.drawString(logo, 0, 0); // MO - RI - SA - WA
        ofPopMatrix();
    
}
