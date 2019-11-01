
#include "manaswiVeraMolnar.h"

void manaswiVeraMolnar::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in manaswiVeraMolnar.h
    //parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Manaswi Mishra");
    setOriginalArtist("Vera Molnar");

	parameters.add(variance.set("Variance", 30, 0, 50));
	parameters.add(speed.set("Rotate", 0, -5, 5));
	parameters.add(space.set("Spacing", 5, 0, 50));
	parameters.add(spaghetti.set("Spaghetti Monster", 1, 1, 5));

	startX = dimensions.width*0.1;
	startY = dimensions.height*0.1;
	finishX = dimensions.width*0.9;
	sideLength = ((finishX - startX) / gridSize);

    loadCode("scenes/manaswiVeraMolnar/exampleCode.cpp");
}

void manaswiVeraMolnar::update(){
    
}

void manaswiVeraMolnar::draw(){

	ofNoFill();
	ofSetLineWidth(2.5);

	if (ofGetFrameNum() % 40 == 0) {
		computeVertices();
	}


	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {

			ofSetHexColor(colorArray[i][j]);

			ofPushMatrix();

			ofTranslate(sideLength/2 + startX + i*sideLength, sideLength / 2 + startY + j*sideLength);
			ofRotate(ofGetFrameNum()%360 * speed);
			
			ofBeginShape();

			for (int k = 0; k < 32; k++) {
				ofVertex(vertexArray[i][j][k].x - sideLength/2, vertexArray[i][j][k].y - sideLength/2);
			}

			ofEndShape(true);
			ofPopMatrix();
		}
	}
}

void manaswiVeraMolnar::computeVertices() {

	int r = -1, prev_r = -1;
	int colorCounter[7] = {0,0,0,0,0,0,0};



	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			

			// Choose Color
			while (1) {
				r = int(ofRandom(0, 7));
				if (r == prev_r && (ofNoise(1) < 0.9)) {
					continue;
				}

				if (colorCounter[r] > 5) {
					continue;
				}
				else {
					colorCounter[r]++;
					prev_r = r;
					break;
				}		
			}

			colorArray[i][j] = colorID[r];


			// Choose Vertices
			for (int k = 0; k < 8; k++) {

				int weight = spaghetti;
				int m = space, std = variance;
				ofVec2f v1 = ofVec2f((weight * (m + std*ofRandomf())), (weight * (m + std * ofRandomf())));
				ofVec2f v2 = ofVec2f( sideLength - (weight * (m + std * ofRandomf())),  (weight * (m + std * ofRandomf())));
				ofVec2f v3 = ofVec2f( sideLength - (weight *(m + std * ofRandomf())), sideLength - (weight *(m + std * ofRandomf())));
				ofVec2f v4 = ofVec2f((weight * (m + std * ofRandomf())), sideLength - (weight * (m + std * ofRandomf())));
			
			
				vertexArray[i][j][4 * k + 0] = v1;
				vertexArray[i][j][4 * k + 1] = v2;
				vertexArray[i][j][4 * k + 2] = v3;
				vertexArray[i][j][4 * k + 3] = v4;
				
			}
		}
	}
}