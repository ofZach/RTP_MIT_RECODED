for (int i = 0; i < vid.getHeight(); i += [[Density]]) {
	for (int j = 0; j < vid.getWidth(); j += [[Density]]) {

		ofColor col = vid.getPixels().getColor(i, j);
		int brightness = col.getBrightness();
		int w = ofMap(brightness, 0, 255, 0, [[Rectangle Scale]]);

		ofPushMatrix();
			
		ofTranslate(i , j);
		ofDrawRectangle(0, 0, [[Rectangle Scale]], [[Rectangle Scale]]);

		ofPopMatrix();

	}
}