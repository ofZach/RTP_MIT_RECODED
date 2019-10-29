void draw() {
  let points = pointsFromText("1961");
  let progress = abs(sin(elapsedTime() * 0.3));
  
  for (let point in points) {
    let x = point.x +
            [[spread]] * random(-[[radius]], [[radius]]) +
            [[twist1]] * simplexNoise3D(progress, point.x, point.y, [[twist2]]);
    
    let y = point.y +
            [[spread]] * random(-[[radius]], [[radius]]) +
            [[twist1]] * simplexNoise3D(15 + progress, point.x, point.y, [[twist2]]);
    
    drawCircle(x, y, [[radius]]);
  }
}
