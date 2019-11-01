void manaswiVeraMolnar::draw(){
    if (ofGetFrameNum() % 40 == 0) {
        computeVertices();
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            ofSetHexColor(colorArray[i][j]);
            ofRotate(ofGetFrameNum()%360 * [[Rotate]]);
            ofBeginShape();
            for (int k = 0; k < 32; k++) {
                ofVertex(vertexArray[i][j][k].x - sideLength/2, vertexArray[i][j][k].y - sideLength/2);
            }
            ofEndShape(true);
        }
    }
}

void manaswiVeraMolnar::computeVertices() {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            // Choose Vertices
            for (int k = 0; k < 8; k++) {
                
                int weight = [[Spaghetti Monster]];
                int m = [[Spacing]], std = [[Variance]];
    
                vertexArray[i][j][4 * k + 0] = ofVec2f((weight * (m + std*ofRandomf())), (weight * (m + std * ofRandomf())));;
                vertexArray[i][j][4 * k + 1] = ofVec2f( sideLength - (weight * (m + std * ofRandomf())),  (weight * (m + std * ofRandomf())));
                vertexArray[i][j][4 * k + 2] = ofVec2f( sideLength - (weight *(m + std * ofRandomf())), sideLength - (weight *(m + std * ofRandomf())));
                vertexArray[i][j][4 * k + 3] = ofVec2f((weight * (m + std * ofRandomf())), sideLength - (weight * (m + std * ofRandomf())));
            }
        }
    }
}
