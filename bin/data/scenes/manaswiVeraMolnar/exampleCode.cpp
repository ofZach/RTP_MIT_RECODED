for (int i = 0; i < gridSize; i++) {
	for (int j = 0; j < gridSize; j++) {

		// Select Color
		ofSetHexColor(colorArray[i][j]);
		ofPushMatrix();
		ofTranslate(i * sideLength, j * sideLength);

		// Rotate
		ofRotate(ofGetFrameNum() % 360 * [[Rotate]]);

		ofBeginShape();

		for (int k = 0; k < 32; k++) {

			// Choosing vertices
			ofVec2f v1 = ofVec2f(([[Spaghetti Monster]] * ([[Spacing]] + [[Variance]] * ofRandomf())), ([[Spaghetti Monster]] * ([[Spacing]] + [[Variance]] * ofRandomf())));
			ofVec2f v2 = ofVec2f(sideLength - ([[Spaghetti Monster]] * ([[Spacing]] + [[Variance]] * ofRandomf())), ([[Spaghetti Monster]] * ([[Spacing]] + [[Variance]] * ofRandomf())));
			ofVec2f v3 = ofVec2f(sideLength - ([[Spaghetti Monster]] *([[Spacing]] + [[Variance]] * ofRandomf())), sideLength - ([[Spaghetti Monster]] *([[Spacing]] + [[Variance]] * ofRandomf())));
			ofVec2f v4 = ofVec2f(([[Spaghetti Monster]] * ([[Spacing]] + [[Variance]] * ofRandomf())), sideLength - ([[Spaghetti Monster]] * ([[Spacing]] + [[Variance]] * ofRandomf())));
		
		}

		ofEndShape(true);
		ofPopMatrix();
	}
}