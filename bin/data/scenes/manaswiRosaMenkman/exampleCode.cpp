float s = ofMap(sin(ofGetElapsedTimef() / 100 * [[Glitch Speed]]), -1, 1, 0, 1);

for (int i = 0; i < buffer.size(); i++) {
	if (i < [[Skip Location]] ||
		i >([[Skip Location]] + [[Skip Amount]])) {
		buffer2.append(buffer.getData() + i, 1);
	}
	else {
		char * data = new char[1];
		data[0] = ofRandom(0, 255);
		buffer2.append(data, 1);
		delete data;
	}
}

newImage.load(buffer2);