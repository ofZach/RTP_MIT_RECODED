void draw(){
    ofSetColor(255);
    float time = [[speed]]*ofGetElapsedTimef()*50;
    ofSeedRandom([[noise]]);
    for (int z = 0; z < 10; z++){
        float radius = fmod(time + ofMap(z, 0, 10, 0, 300), 300);
        ofPoint center(400,300);
        for (int i = 0; i < 100; i++){
            float angle = ofMap(i, 0, 100, 0, TWO_PI);
            float offset = ofNoise(ofRandom(0.01, 0.06))*100;
            ofDrawCircle(center.x + offset+ radius * cos(angle),
                         center.y + +offset+ radius * sin(angle),
                         3);
        }
        
    }
}
