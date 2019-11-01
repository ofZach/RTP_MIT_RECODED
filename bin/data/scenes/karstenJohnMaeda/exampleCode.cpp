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
        string logo = "モリサワ"; //MO-RI-SA-WA
        pushMatrix();
        translate(xBegin,yBegin);
        int character = paths.size();
        for (int i = 0; i < character; i++){
            float xPos = 0.0;
            pushMatrix();
            for(int j = 0; j < repeatLetters; j++ ){
                float yPos = (j+1)/9.2;
                if(i >= character - 2){
                    xPos = [[amp]] * sin(-j * [[freq]]) * noise(j* [[noiseFactor]], i);
                } else{
                    xPos = [[amp]] * sin(j * [[freq]]) * noise(j* [[noiseFactor]], i);
                }
                translate(xPos, yPos);
                rotate(noise([[rot]], i));
            }
            popMatrix();
        }
        setColor(0);
        font.drawString(logo, 0, 0); // MO - RI - SA - WA
        popMatrix();
             
}
