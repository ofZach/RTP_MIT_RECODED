void draw(){
    float time = getTime();
    float angle = time;
    color(0);
    fill();
    drawRectangle(0, 0, getWidth(), getHeight());
    color(pink);
    lineWidth(2);

    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 8; j++){
            float x = xOrig + lissRad * cos(((i*[[xScale]])+angle+(j*[[jStretch]]))*0.432);
            float y = yOrig + lissRad * sin(((i*[[yScale]])+angle+(j*[[jStretch]]))*0.287);
            float hexRad = map(sin((angle+i)), 1, -1, 3, 120);
            pushMatrix();
            translate(getWidth()/8 + getWidth()/32, -getHeight()/8);
            translate(x, y);
            circleResolution(6);
            noFill();
            rotateZDeg(30);
            drawCircle(x, y, hexRad);
            popMatrix();
          }
        }
    
}

