for(int j=-3; j<4; j++){
    for(int k=-3; k<4; k++){
        pushMatrix();
        translate(width/2 + j*width/4, height/2 + k*height/4);
        fill(60,40,170);
        scale([[scaleB]]);
        rotate(2*PI*sin(theta));
        for(int i=0; i<4; i++){
            rotate(i*PI/4);
            rect(-w,-h,2*w,2*h);
        }
        popMatrix();
    }
}

for(int j=-3; j<4; j++){
    for(int k=-3; k<4; k++){
        pushMatrix();
        translate(width/2 + j*width/4 + width/8, height/2 + k*height/4 + height/8);
        fill(250,250,250);
        scale([[scaleS]]);
        rotate(-2*PI*sin(theta+PI/2));
        for(int i=0; i<4; i++){
            rotate(-sin(theta+PI/2));
            rect(-w,-h,2*w,2*h);
        }
        popMatrix();
    }
}
