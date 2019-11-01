for (int i = 0; i < [[Line count]]; i++) {

	// Lissajous curves
	s1 = sin((count + (3 * i)) / [[Sloth-ness]]);
	s2 = cos((count + (5 * i)) / [[Sloth-ness]]);
	s3 = sin(((count + i) / 2) / [[Sloth-ness]]);
	s4 = cos(((count + i) * 3) / [[Sloth-ness]]);

	//Mapping to (x1,y1) and (x2,y2) coordinates for each line
	x1 = ofMap(s1, -1, 1, dimensions.width*0.1, dimensions.width*0.9);
	y1 = ofMap(s2, -1, 1, dimensions.height*0.1, dimensions.height*0.9);
	x2 = ofMap(s3, -1, 1, dimensions.width*0.1, dimensions.width*0.9);
	y2 = ofMap(s4, -1, 1, dimensions.height*0.1, dimensions.height*0.9);

	ofDrawLine(x1, y1, 0, x2, y2, 0);
	ofDrawCircle(x1, y1, 0, 2);

}