
for(int i = 0; i < 13; i++){
    for(int j = 0; j < 13; j++){
        float loop_inc = .05;
        int x = 29+55*j;
        int y = 29+55*i;
        for(float loop = 1; loop < random(40)+2; loop+=loop_inc){
            if(random()>(1-[[Density]])){
                addVertex(x + ([[Side Length]]+random([[Random]]))/loop,
                                y - ([[Side Length]]+random([[Random]]))/loop);
                lineTo(x + ([[Side Length]]+random([[Random]]))/loop,
                            y + ([[Side Length]]+ofRandom([[Random]]))/loop);
                lineTo(x - ([[Side Length]]+ofRandom([[Random]]))/loop,
                            y + ([[Side Length]]+ofRandom([[Random]]))/loop);
                lineTo(x - ([[Side Length]]+ofRandom([[Random]]))/loop,
                            y - ([[Side Length]]+ofRandom([[Random]]))/loop);
                line.close();
                loop_inc+=(.5-[[Loop Tightness]]);
            }
        }
    }
}
