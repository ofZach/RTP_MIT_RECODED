void draw(){
    ofBackground(229,229,222);
    
    float  time = ofGetElapsedTimef()*[[speed]];
    
    for (int i = 100; i < 600; i = i+100+time) {
        for (int j = 150; j < 500; j = j+100+time){
            for (int z = 200; z < 500 ; z = z+100+time){
                for (int w = 250; w < 400 ; w = w+100+time){
                    for (int u = 300; u < 400 ; u = u+100+time){
                        
                        ofPushMatrix();
                        ofTranslate(400,0);
                        ofSetColor(108,101,67); //green
                        ofDrawEllipse(100-time,10+i,90,90);
                        ofDrawBezier(95-time, -35+i, 170-time, -65+i, 130-time, -65+i, 145-time, 10+i);
                        ofSetColor(59-time, 119, 201); //blue
                        ofDrawEllipse(100-time,10+i,43,43);
                    }
                }
            }
        }
    }
}
