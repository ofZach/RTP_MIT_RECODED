void draw() {
  let elapsed  = getElapsedTime();
  let minNoise = map(sin(elapsed * [[speed]] * 0.3),      -1, 1, 0.3, 0.6);
  let maxNoise = map(sin(elapsed * [[speed]] * 0.2 + PI), -1, 1, 1.0, 0.8);
  
  // for each pixel
  for (let y = 0; y < height; ++y) {
    for (let x = 0; x < width; ++x) {
      let noise = simplexNoise3D(x, y, elapsed * [[speed]], [[noiseZoom]]);
      let color = Color.black;
      
      if (minNoise < noise < maxNoise &&
          (noise % ([[bandSize]] * 2) / [[bandSize]]) < 1) {
          color = Color.white;
        }
      }
      
      drawPixel(x, y, color);
    }
  }
}
