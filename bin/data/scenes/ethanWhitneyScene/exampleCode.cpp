time = getTime();
for(int i = 0; i < 2000; i++){
    setColor(map(i, 0, 2000, 100, 210) + random(40),
               map(i * sin(time * 2), -2000, 2000, 100, 230)+random(20),
               map(i * cos(time * 2), -2000, 2000, 100, 235)+random(20));
    
    x = sin(time * i * [[Speed]]) * i * [[Radius]] + dimensions.width/2;
    y =cos(time * i * [[Speed]]) * i * [[Radius]] + dimensions.height/2;
    drawCircle(x, y, [[Circle Size]]);
}
