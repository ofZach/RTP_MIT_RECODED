
void draw(){
    // Set color to purple
    ofSetColor(70,55,85, 150);
    float r = space*0.001;
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            //Draw rectangles
            float offset = ofNoise(ofRandom(r, 0.09))*440;
            ofDrawRectangle(45*i + offset-100, 48*j + offset-100, 50, 50);
        }
    }
}
