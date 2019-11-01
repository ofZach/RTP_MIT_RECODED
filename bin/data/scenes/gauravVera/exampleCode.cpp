ofSetColor(240,235,230);
ofFill();
ofRect(0,0,dimensions.width,dimensions.height);
ofNoFill();
//ofSeedRandom(s);

ofSeedRandom((int)(ofGetSeconds()*1000));
for(int k=0; k<instances; k++){
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            ofPushMatrix();
        ofTranslate([[s]]*i+(dimensions.width-[[s]]*5.-[[d]])/2.,[[s]]*j+(dimensions.width-[[s]]*5.-[[d]])/2.);
            ofSetColor(120, ofRandom(0,100), ofRandom(0,100));
            
            ofBeginShape();
            
            ofVertex(ofRandom(-[[hr]],[[hr]]), ofRandom(-[[vr]],[[vr]]));
            ofVertex([[d]]+ofRandom(-[[hr]],[[hr]]), ofRandom(-[[vr]],[[vr]]));
            ofVertex([[d]]+ofRandom(-[[hr]],[[hr]]), [[d]]+ofRandom(-[[vr,[[vr]]));
            ofVertex(ofRandom(-[[hr]],[[hr]]), [[d]]+ofRandom(-[[vr]],[[vr]]));
                                                                       
            ofEndShape(true);
                                                                       
            ofPopMatrix();
            
        }
    }
