paintBackground();

drawText();

rectSizeX = width/[[numberRows]];
rectSizeY = height/[[numberRows]];

// upper row has as many squares as numberRows
for (int i = 0; i < numberRows; i++) {
    // draw as many squares on this row as each
    for (int j = 0; j < numberRows-i; j++) {
        
        ofSetLineWidth([[strokeWidth]]);
        
        // foreground rectangle
        ofDrawRectangle(posX, posY, rectSizeX, rectSizeY);
        
        // background rectangle
        ofDrawRectangle(posX + [[depth]], posY - [[depth]], rectSizeX, rectSizeY);
        
        // lines between squares
        ofDrawLines([[depth]]);
    }
}
