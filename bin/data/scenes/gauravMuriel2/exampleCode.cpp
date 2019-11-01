pushMatrix();
translate(width/2, height/2);
scale(1);
for(int i=0; i<4; i++){
    rotate(i*PI/2);
    fill(250);
    rect(0+80*(1-sin(theta))*[[e]],-20,10,20);
    rect(20+140*(1-sin(theta))*[[e]],0,10,20);
    rect(50+100*(1-sin(theta))*[[e]],40,20,10);
    fill(0);
    rect(50+30*(1-sin(theta))*[[e]],-70,20,140);
    rect(10+70*(1-sin(theta))*[[e]],-70,40,40);
    rect(20+50*(1-sin(theta))*[[e]],0,50,30);
    rect(0+120*(1-sin(theta))*[[e]],-20,20,40);
    rect(0+20*(1-sin(theta))*[[e]],-20,40,60);
}
popMatrix();
theta+=0.01;
}
