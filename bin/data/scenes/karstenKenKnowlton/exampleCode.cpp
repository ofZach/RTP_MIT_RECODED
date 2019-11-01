void setup(){
    video.load("video.mov"); // get that video
    video.play();
}

//--------------------------------------------------------------
void draw(){
    setColor(45);
    frawRectangle(0, 0, getWidth(), getHeight());
    setColor(200);
    pushMatrix();
    scale(1.2,1.2); // scale the video just for fun
    translate(-video.getWidth()/4, 0);
    for (int i = 0; i < video.getWidth(); i+=cellSize){
          for (int j = 0; j < video.getHeight(); j+=cellSize){
              color color = video.getPixels().getColor(i,j);
              float bright = color.getBrightness();
              float brightness = map(bright, 0, 255, 0, [[threshold]]);
              pushMatrix();
              translate(i, j);
              fill();
              setColor(230);
              if(brightness <= 63){
                ofDrawTriangle(0, 0, [[cellSize]]/2, [[cellSize]]/2, 0, [[cellSize]]);
              } else if (64 <= brightness && brightness <= 128){
                ofDrawTriangle(0, 0, [[cellSize]], 0, [[cellSize]], 0);
              } else if (129 <= brightness && brightness <= 192){
                  drawShape([[cellsize]]);
              } else if (brightness > 192) {
                drawRectangle(0, 0, [[cellSize]], [[cellSize]]);
              }
              noFill();
              setColor(45);
              setLineWidth([[weight]]);
              popMatrix();
          }
      }
    popMatrix();
}
