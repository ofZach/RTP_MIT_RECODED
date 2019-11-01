//inspired by art work by Steina and Woody Vasulka
//recoded by Liang Zhipeng
for (int i = -0.66*center_x; i < 0.66*center_x; i++){
    for (int j = -0.7*center_y; j < 0.7*center_y; j++){
        if((i*i + j*j)< (48*center_x^2+(int)ofRandom(-(float)[[Magic Number]])+48*center_y^2)){
           ofSeedRandom([[Speed]]);
           ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
           ofDrawRectangle(i+ofRandom(-10,10), j+ofRandom(-10,10), 1, 1);
        } else {
            ofSetColor( ofNoise(i*0.01, j*0.01, 0.01*[[Speed]])*255,ofNoise(i*0.01, j*0.01, 0.01*[[Speed]])*255,ofNoise(i*0.01, j*0.01, 0.01*[[Speed]])*255);
           ofDrawRectangle(i,j,1,1);
         }}}
