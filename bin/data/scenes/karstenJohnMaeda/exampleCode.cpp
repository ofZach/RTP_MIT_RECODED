void setup(){

    font = loadFont("nicokaku.ttf")
    settings.addRange(Unicode.Katakana); // make sure we can draw Katakana
    font.load(settings);
}

void draw(){
    
        float xBegin = 0.0;
        float yBegin = 0.0;
        float width = getWidth();
        float height = getHeight();
        int repeatLetters = 350;
        setColor(245);
        fill();
        drawRectangle(0, 0, width, height);
        setColor(0);
        string logo = "モリサワ"; //MO-RI-SA-WA
        rectangle bounds = font.getStringBoundingBox(logo, 0.0, 0.0);
        xBegin = (width-bounds.width)/2-10;
        yBegin = (bounds.height+3);
        noFill();
        setLineWidth(1);
    
        pushMatrix();
        translate(xBegin,yBegin);
        int character = paths.size();
        for (int i = 0; i < character; i++){
            ofPath path = paths[i];
            vector < ofPolyline > lines = path.getOutline();
            float xPos = 0.0;
            pushMatrix();
            for(int j = 0; j < repeatLetters; j++ ){
                float yPos = (j+1)/9.2;
                if(i >= character - 2){
                    xPos = [[amp]] * sin(-j * [[freq]]) * noise(j* [[noiseFactor]], i * 1.39);
                } else{
                    xPos = [[amp]] * sin(j * [[freq]]) * noise(j* [[noiseFactor]], i * 0.047);
                }
                translate(xPos, yPos);
                rotate(noise([[rot]], i));
                
                for (int k = 0; k < lines.size(); k++){
                    line line = lines[k];
                    setColor(80, 80, 80, ofMap(yPos, 0, 16 , 255, 0));
                    lines[k].draw();
                }
            }
            popMatrix();
        }
        setColor(0);
        font.drawString(logo, 0, 0); // MO - RI - SA - WA
        popMatrix();
             
}
