void setup(){
    video.load("480.mov");
    video.play();
    int w = video.getWidth();
    int h = video.getHeight();
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            mesh.addVertex(ofPoint(x,y,0));
            mesh.addColor(ofFloatColor(0,0,0));
        }
    }
    windowSizeX = dimensions.getWidth();
    windowSizeY = dimensions.getHeight();
}

void update(){
    video.update();
       if (video.isFrameNew()){
           for (int i = 0; i < video.getWidth()*video.getHeight(); i++)
               color sampleColor(video.getPixels();
               vec3f tempVec = mesh.getVertex(i);
               tempVec.z = sin(i*[[phaseZ]]*0.001)*[[extrusionAmount]];
               }
               mesh.setVertex(i, tempVec);
               mesh.setColor(i, sampleColor);
           }
       }
}

void draw(){
     setColor(0);
     drawRectangle(0, 0, windowSizeX, windowSizeY);
     cam.begin();
     pushMatrix();
     translate(-video.getWidth(), video.getHeight(), -video.getWidth());
     scale(2,-2,2);
     mesh.drawFaces();
     popMatrix();
     cam.end();
}

