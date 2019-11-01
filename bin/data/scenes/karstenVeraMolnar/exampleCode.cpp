void setup(){
    windowSize = getWidth();
}

void draw(){
    seedRandom(1);
    squareSize = windowSize/[[numSquares]];
    RectMode(CENTER);
    
    // flip canvas and draw upside down because math is hard
    PushMatrix();
    Translate(0, windowSize);
    Scale(1, -1);
    SetColor(255);
    DrawRectangle(windowSize/2, windowSize/2, windowSize, windowSize);
    SetColor(0, 0, 0, 200);
    
    for(int i = 0; i < [[numSquares]]; i++){
        for(int j= 0; j < [[numSquares]]; j++){
            float posX = (Map(i, 0, [[numSquares]]-1, squareSize, (windowSize - squareSize)));
            float posY = (Map(j, 0, [[numSquares]]-1, squareSize, (windowSize - squareSize)));
            float offset = Random(-[[offAmount]]*(squareSize/[[numSquares]]), [[offAmount]]*(squareSize/[[numSquares]]));
    
            PushMatrix();
            Translate(posX, posY);
            RotateZDeg([[rotation]]);
            DrawRectangle(0+offset, 0+offset, squareSize-[[margin]], squareSize-[[margin]]);
            PopMatrix();
        }
    }
    PopMatrix();
}
