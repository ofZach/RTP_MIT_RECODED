void setup() {
  video = loadVideo();
}

void draw() {
  let numPoints = (width * height) / [[cellSize]];
  
  for (let i = 0; i < numPoints; ++i) {
    // compute phyllotaxis layout
    let phylloX = ([[cellSize]] / 2.0) * sqrt(i) *
                   cos(i * (PI * (3 - sqrt(5)) + [[rotate]] * (i / numPoints)));
    
    let phylloY = ([[cellSize]] / 2.0) * sqrt(i) *
                   sin(i * (PI * (3 - sqrt(5)) + [[rotate]] * (i / numPoints)));
    
    let x = phylloX * cos([[edgeWarp]]) - phylloY * sin([[edgeWarp]]);
    let y = phylloX * sin([[edgeWarp]]) + phylloY * cos([[edgeWarp]]);
    
    // get brightness from video
    let brightness = video.getBrightness(x + width / 2.0, y + height / 2.0);
    
    // draw blob
    let radiusBase = map(brightness, 0, 1, [[cellSize]] * 0.02, [[cellSize]] * 0.4);
    let noiseOffset = random(0, 1000);
    let path = new Path(x, y);
    for (let i = 0; i < 30; ++i) {
      let theta = TWO_PI * i / 30;
      let noise = simplexNoise2D(cos(theta) + noiseOffset, sin(theta), [[blobbiness]]);
      let radius = radiusBase * noise;
      let x = radius * cos(theta);
      let y = radius * sin(theta);
      
      path.addVertex(x, y);
    }
    path.draw();
  }
}
