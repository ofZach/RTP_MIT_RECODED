void setup(){
    
    directory dir;
    image img [] = dir.load();
    int w = images[0].getWidth();
    int h = images[0].getHeight();
    
    image left;
    image right;
}


void draw(){
    
    track.leftEye();
    track.rightEye();
    [[[imgNumber]]].getLeftEye();
    [[[imgNumber]]].getRightEye();
    
    int calcCenter = rightAverage - leftAverage;
    point center = leftAverage + calcCenter/2;

    left.update();
    right.update();
    
    left.mirror();
    right.mirror();
    
    left.draw();
    right.draw();
}
