void draw() {
  setLineThickness([[thickness]]);
  
  
  for (let i = 0; i < [[numLines]]; ++i) {
    let sign = random(0, 1) < 0.5 ? -1 : 1;

    let x1 = 0;
    let x2 = width;
    
    let y = map(i, 0, [[numLines]] - 1, 0, height);
    let y1 =  y + sign * ofRandom([[offset]] * 0.5, [[offset]]);
    let y2 = y1 + sign * ofRandom([[offset]] * 0.5, [[offset]]);
    
    // draw segmented line
    let slope = (y2 - y1) / (x2 - x1);
    let offset = y1 - slope * x1;
    let x = x1;
    let y = y1;
    
    while (x < x2) {
        drawLine(x, y, x + [[segmentWidth]], y);
        x += [[segmentWidth]];
        y = slope * x + offset;
    }
  }
  
  maskWithCircle(width / 2, height / 2, width * 0.4);
}
