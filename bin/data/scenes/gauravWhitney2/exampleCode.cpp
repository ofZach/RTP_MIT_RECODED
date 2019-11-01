for(int k=-5; k<6; k++){
    for(int i=0; i<[[res]]; i++){
        ofStrokeWeight(4);
        float x = [[d]]*cos(i*2*PI/[[res]])*scaleH;
        float y = [[d]]*sin(i*2*PI/[[res]])*[[scaleV]];
        ofPoint(x+k*150,y);
    }
}
for(int k=-5; k<6; k++){
    for(int i=0; i<[[res]]; i++){
        ofStroke(0,0,250);
        ofStrokeWeight(3);
        float x = 100 + [[d]]*cos(i*2*PI/[[res]]+PI/3)*scaleH;
        float y = [[d]]*sin((i*2*PI/[[res]]))*[[scaleV]];
        ofPoint((x+k*150)/1.5,y/1.5);
    }
}
for(int k=-8; k<9; k++){
    for(int i=0; i<[[res]]; i++){
        ofStroke(250,0,0);
        ofStrokeWeight(2);
        float x = 100 + [[d]]*cos(i*2*PI/[[res]]-PI/3)*scaleH;
        float y = [[d]]*sin((i*2*PI/[[res]]))*[[scaleV]];
        ofpoint((x+k*150)/3,y/3);
    }
}
