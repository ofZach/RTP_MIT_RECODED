void setup(){
    video.load("480.mov"); // load a video
    video.play();
    int w = video.getWidth();
    int h = video.getHeight();
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            mesh.addVertex(ofPoint(x,y,0)); // make a mesh
            mesh.addColor(ofFloatColor(0,0,0));
        }
    }
}
void update(){
    video.update();

    if (video.isFrameNew()){ // get color into the mesh
       for (int i = 0; i < video.getWidth()*video.getHeight(); i++)
            color sampleColor(video.getPixels();
            vec tempVec = mesh.getVertex(i);
            tempVec.z = sin(i*[[phaseZ]]*0.001)*[[extrusionAmount]];
            }
        mesh.setVertex(i, tempVec);
        mesh.setColor(i, sampleColor);
}
    
void draw(){
     mesh.drawFaces();
}

