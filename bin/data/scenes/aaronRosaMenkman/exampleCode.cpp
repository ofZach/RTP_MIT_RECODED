void setup() {
    original.load("medialab.jpg");
}

 
void update(){
    
    whereToGlitch = buffer.size() * sin([[sweepSpeed]]*elapsedTime);
    
    originalImage[whereToGlitch].glitch([[glitchFlavor]]);
    
    newImage.load(glitchedImage);
    newImage.draw(0,0);
}

