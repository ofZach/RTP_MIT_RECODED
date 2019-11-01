void draw(){
    
    ofBackground(255);
    ofSetColor([[color]]);
    ofSeedRandom([[randomSeed]]*100);
    for (int i = 0; i < 25; i++){
        ofDrawRectangle(50 + i*20,50 + ofRandom(-1,1) * [[randomness]],10,500 + ofRandom(-1,1) * [[randomness]]);
    }
   
}
