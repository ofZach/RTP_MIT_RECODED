void draw(){
    ofBackground(0);
    int frameCount = ofGetElapsedTimef()*10;
    float time = ofGetElapsedTimef();
    
    if (0 < [[color]] < 10){
        ofBackground(6,28,209,150);
    }
    if (20 < [[color]] < 40){
        ofBackground(193,155,232);
    }
    if (20 < [[color]] < 60){
        ofBackground(115,168,219);
    }
    if ([60 < [[color]] < 80){
        ofBackground(255);
    }
    if (80 < [[color]] < 100){
        ofBackground(193,155,232);
    }
    
    ofPushMatrix();
    ofTranslate(500,300);
    ofRotate([[speed]]*time);
    if (frameCount%5 ==0 | frameCount%3 ==0 | (frameCount > 50 && frameCount < 150) ){
        ofSetColor(234,229,178,200);
        if ((frameCount > 150 && frameCount < 200)){
            ofSetColor(0);
        }
    }
    
    else {
        ofSetColor(6, 28, 209, 2000);
    }
    ofDrawEllipse(0,90,220,180);
    ofDrawEllipse(0,90,260,180);
    if (frameCount%7 ==0 | frameCount%5 ==0){
        ofSetColor(6,28,209,150);
    }
    else {
        ofSetColor(209,16,6,200);
    }
    ofRotate(-2*[[speed]]*time);
    ofDrawEllipse(0,-90,220,180);
    ofDrawEllipse(0,-90,260,180);
    ofPopMatrix();

}
