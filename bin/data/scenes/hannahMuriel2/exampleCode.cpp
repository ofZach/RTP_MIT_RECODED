void draw{
    
for (int j = 0; j < 8; j=j+1){
    ofDrawRectangle(300, 300, 540-(j-j*[[red]])*59, 540-(j-j*[[red]])*59);
    ofSetColor(48,91,216);
    ofDrawRectangle(300, 300, 500-(j-j*[[blue]])*60, 500-(j-j*[[blue]])*60);
}
    ofSetColor(250,30,30);
    ofDrawRectangle(300, 300, 140, 140);
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(300,300);
    ofRotate(45);
    ofDrawRectangle(0,0,150,5);
    ofRotate(-90);
    ofDrawRectangle(0,0,150,5);
    ofPopMatrix();
}
