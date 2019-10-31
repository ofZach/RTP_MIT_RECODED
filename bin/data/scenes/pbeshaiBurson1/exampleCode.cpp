void draw() {
  let image1 = loadImage([[image1]]);
  let image2 = loadImage([[image2]]);
  
  let face1 = extractFace(image1);
  face1.draw(0, 0);
  
  let face2 = extractFace(image2);
  face2.draw(0, height / 2);
  
  // draw blended face
  translate(200, 0);
  img1.draw();
  let blendedFace = face1.blendWith(face2, [[blend]])
  blendedFace.draw();
}
