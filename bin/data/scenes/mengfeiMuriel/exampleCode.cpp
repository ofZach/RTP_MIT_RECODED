for (int i = 0; i < [[r]]; i++)
{
    string text = u8 Morisawa;
    float fontWidth = font.stringWidth(text);
    float x = ofGetWidth()/ 2;
    int y = font.stringHeight(text);
    
    Translate(0, y*0.9);
    font.drawString(text, -fontWidth / 2, 0);
    
    float j = ofMap(i, 0, (r-1), 0.7, 40);
    float size = 1 - (float)[[para]] / j;
    Scale(size, size, 1);
}
