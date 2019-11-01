int x = ofRandom(200, 400);
int y = ofRandom(200, 400);
float time = ofGetElapsedTimef();
float xOrig = dimensions.getWidth()/2;
float yOrig = dimensions.getHeight()/2;;
float radius = 300; //ofMap(sin(time*10), -1, 1, 100, 300);

for (int i = 0; i < 10; i++){
    float colorAmount = ofMap(i, 0, 9, 0.8, 1.15);
    ofSetColor(219 * colorAmount, 174 * colorAmount, 202 * colorAmount);
    float angle = i * 20 + time * 0.5;
    float x = xOrig + radius * cos(angle*[[xAngleParam]]);
    float y = yOrig + radius * sin(angle*[[yAngleParam]]);
    
    ofPushMatrix();
    ofTranslate(x, y);
    ofScale(ofNoise(i, time * 0.1));
    ofDrawTriangle(0, 0, 160, 300, 320, 0);
    ofPopMatrix();
    };
