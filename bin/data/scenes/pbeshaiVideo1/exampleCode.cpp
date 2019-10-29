void setup() {
  video = loadVideo();
}

void draw() {
  let img = applySlitScan(video, [[slitSpeed]]);
  let mesh;
  
  for (let y = 0; y < img.height; y += 2) {
    for (let x = 0; x < img.width; x += [[size]]) {
      let brightness = img.getBrightness(x, y);
      
      mesh.addVertex(x,
                     y + map(brightness, 0, 255, 0, [[yImpact]])
                     0 + map(brightness, 0, 255, 0, [[zImpact]]));
    }
  }
  
  rotateX([[zImpact]] / 3.0);
  mesh.draw();
}
