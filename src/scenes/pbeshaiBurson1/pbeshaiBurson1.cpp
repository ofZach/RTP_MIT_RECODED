
#include "pbeshaiBurson1.h"

void pbeshaiBurson1::setup(){
  
  // setup parameters
  // if your original code use an ofxPanel instance dont use it here, instead
  // add your parameters to the "parameters" instance as follows.
  // param was declared in pbeshaiBurson1.h
  parameters.add(param1.set("image1", 6, 0, 30));
  parameters.add(param2.set("image2", 17, 0, 30));
  parameters.add(param3.set("blend", 0.74, 0, 1));
  
  setAuthor("Peter Beshai");
  setOriginalArtist("Nancy Burson");
  
  loadCode("scenes/pbeshaiBurson1/exampleCode.cpp");
  
  float screenWidth = dimensions.getWidth();
  float screenHeight = dimensions.getHeight();
  float imgGutterWidth = floor(screenWidth * 0.25);
  float imgGutterHeight = screenHeight;
  float combinedImgWidth = screenWidth - imgGutterWidth;
  float combinedImgHeight = screenHeight;
  
  //  grabber.setDeviceID(0); // use external webcam with '1'
  //  grabber.setup(combinedImgWidth, combinedImgHeight);
  tracker.setup();
  targetImg.load("scenes/pbeshaiBurson1/ml-face-30.jpg");
  trackerTarget.setup();
  trackerSource.setup();
  sourceImg.load("scenes/pbeshaiBurson1/ml-face-0.jpg");
  //  sourceImg.allocate(combinedImgWidth, combinedImgHeight, OF_IMAGE_COLOR);
  cameraFbo.allocate(combinedImgWidth, combinedImgHeight);
  
  // these don't seem to do anything until in the update method
  trackerSource.update(sourceImg);
  trackerTarget.update(targetImg);
  
  shader.load("scenes/pbeshaiBurson1/shader.vert", "scenes/pbeshaiBurson1/shader.frag");
  
  showWireframe = false;
}

void pbeshaiBurson1::update(){
  //  grabber.update();
  //  if (grabber.isFrameNew()) {
  //    tracker.update(grabber);
  //  }
  
  // load new source img on change
  if (param1 != sourceImgNumber) {
    sourceImgNumber = param1;
    sourceImg.load("scenes/pbeshaiBurson1/ml-face-" + ofToString(sourceImgNumber) + ".jpg");
  }
  
  if (param2 != targetImgNumber) {
    targetImgNumber = param2;
    targetImg.load("scenes/pbeshaiBurson1/ml-face-" + ofToString(targetImgNumber) + ".jpg");
  }
  
  // TODO: see which of this is necessary
  //  cameraFbo.getTexture().readToPixels(sourceImg.getPixels());
  sourceImg.update();
  targetImg.update();
  trackerSource.update(sourceImg);
  trackerTarget.update(targetImg);
  
  if (ofGetFrameNum() % 60 == 0){
    shader.load("scenes/pbeshaiBurson1/shader.vert", "scenes/pbeshaiBurson1/shader.frag");
  }
}


void drawCameraFace(float x, float y, ofxFaceTracker2& tracker, ofVideoGrabber& grabber) {
  // if no tracker data
  if (tracker.size() <= 0) {
    // just draw the camera for now
    grabber.draw(0, 0);
    return;
  }
  
  auto &landmarks = tracker.getInstances()[0].getLandmarks();
  
  // find eye positions
  ofPolyline leftEye = landmarks.getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE);
  glm::vec3 leftEyeCenter = leftEye.getCentroid2D();
  ofPolyline rightEye = landmarks.getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE);
  glm::vec3 rightEyeCenter = rightEye.getCentroid2D();
  glm::vec3 betweenEyes = glm::mix(leftEyeCenter, rightEyeCenter, 0.5);
  
  
  float desiredEyeWidth = 100;
  glm::vec3 eyeDiff = rightEyeCenter - leftEyeCenter;
  
  float angle = atan2(eyeDiff.y, eyeDiff.x);
  float scale = desiredEyeWidth / glm::length(eyeDiff);
  scale = glm::round(scale * 10) / 10;
  
  ofPushMatrix();
  ofTranslate(320, 207);
  ofScale(scale, scale);
  ofRotateZRad(-angle);
  grabber.setAnchorPoint(betweenEyes.x, betweenEyes.y);
  grabber.draw(0, 0);
  ofSetColor(255);
  
  // draw debug eyes
#ifdef DRAW_DEBUG_EYES
  ofPushMatrix();
  ofTranslate(-betweenEyes);
  ofDrawCircle(leftEyeCenter, 6);
  ofDrawCircle(rightEyeCenter, 6);
  ofDrawCircle(betweenEyes, 3);
  ofPopMatrix();
#endif
  
  // tracker.drawDebug();
  ofPopMatrix();
}


void pbeshaiBurson1::draw(){
  float screenWidth = dimensions.getWidth();
  float screenHeight = dimensions.getHeight();
  
  float imgGutterWidth = floor(screenWidth * 0.25);
  float imgGutterScale = 0.5;
  float imgGutterHeight = screenHeight;
  float combinedImgWidth = screenWidth - imgGutterWidth;
  float combinedImgHeight = screenHeight;
  
  ofBackground(0);
  ofSetColor(255);
  
  // draw main face
  //  cameraFbo.begin();
  //  drawCameraFace(0, 0, tracker, grabber);
  //  cameraFbo.end();
  
  ofPushMatrix();
  // ofTranslate(-100, 0);
  
  
  ofMesh sourceMesh;
  ofMesh targetMesh;
  
  
  
  // compute source mesh
  if (trackerSource.size() > 0) {
    auto &landmarks = trackerSource.getInstances()[0].getLandmarks();
    sourceMesh = landmarks.getImageMesh();
    auto vertices = sourceMesh.getVertices();
    int numVx = vertices.size();
    
    for (int i = 0; i < numVx; ++i) {
      sourceMesh.addTexCoord(vertices[i]);
    }
  }
  
  
  // draw blended + source img
  ofPushMatrix();
  
  // compute bounds of mesh to center the image
  auto sourceCentroid = sourceMesh.getCentroid();
  ofRectangle sourceBbox(sourceMesh.getVertex(0), 1, 1);
  for (int i = 1; i < sourceMesh.getNumVertices(); ++i) {
    sourceBbox.growToInclude(sourceMesh.getVertex(i));
  }
  ofTranslate(imgGutterWidth, 0); // translate outside of the gutter
  
  // sadly cannot do this scaling since it breaks the shader
  ofTranslate(combinedImgWidth / 2.0, combinedImgHeight / 2.0);
//  ofScale(combinedImgWidth / (sourceBbox.getWidth() * 1.5));
  ofTranslate(-sourceCentroid.x, -sourceCentroid.y);
//
  // DRAW: draw the full frame camera base layer
  sourceImg.draw(0, 0);
  //  ofPopMatrix();
  ofSetColor(255);
  // sourceImg.draw(-640, 0);
  //    trackerSource.drawDebug();
  
  
  
  if (trackerSource.size() > 0 && trackerTarget.size() > 0) {
    auto &sourceLandmarks = trackerSource.getInstances()[0].getLandmarks();
    auto sourcePts = sourceLandmarks.getImagePoints();
    
    ofxDelaunay sourceTri;
    for (int i = 0; i < sourcePts.size(); ++i) {
      sourceTri.addPoint(sourcePts[i]);
    }
    sourceTri.triangulate();
    ofMesh sourceMesh = sourceTri.triangleMesh;
    
    auto sourceVx = sourceMesh.getVertices();
    int numSourceVx = sourceVx.size();
    
    auto &targetLandmarks = trackerTarget.getInstances()[0].getLandmarks();
    auto targetPts = targetLandmarks.getImagePoints();
    
    ofxDelaunay targetTri;
    for (int i = 0; i < targetPts.size(); ++i) {
      targetTri.addPoint(targetPts[i]);
    }
    targetTri.triangulate();
    ofMesh targetMesh = targetTri.triangleMesh;
    
    auto targetVx = targetMesh.getVertices();
    int numTargetVx = targetVx.size();
    
    // find x and y extents for target and source vertices
    glm::vec2 sourceXExtent(0, 0);
    glm::vec2 sourceYExtent(0, 0);
    glm::vec2 targetXExtent(0, 0);
    glm::vec2 targetYExtent(0, 0);
    
    for (int i = 0; i < numSourceVx; ++i) {
      if (sourceVx[i].x < sourceXExtent[0]) {
        sourceXExtent[0] = sourceVx[i].x;
      }
      if (sourceVx[i].x > sourceXExtent[1]) {
        sourceXExtent[1] = sourceVx[i].x;
      }
      if (sourceVx[i].y < sourceYExtent[0]) {
        sourceYExtent[0] = sourceVx[i].y;
      }
      if (sourceVx[i].y > sourceYExtent[1]) {
        sourceYExtent[1] = sourceVx[i].y;
      }
    }
    for (int i = 0; i < numTargetVx; ++i) {
      if (targetVx[i].x < targetXExtent[0]) {
        targetXExtent[0] = targetVx[i].x;
      }
      if (targetVx[i].x > targetXExtent[1]) {
        targetXExtent[1] = targetVx[i].x;
      }
      if (targetVx[i].y < targetYExtent[0]) {
        targetYExtent[0] = targetVx[i].y;
      }
      if (targetVx[i].y > targetYExtent[1]) {
        targetYExtent[1] = targetVx[i].y;
      }
    }
    
    for (int i = 0; i < numSourceVx; ++i) {
      glm::vec2 vx;
      vx = targetVx[i];
      sourceMesh.addTexCoord(vx);
    }
    
    
    // DRAW: draw a 50% img of the target texture on the source img mesh
    float blend = param3;
    shader.begin();
    
    shader.setUniformTexture("sourceImg", sourceImg, 0);
    shader.setUniformTexture("targetImg", targetImg, 1);
    // convert the current matrix translations
    float xOffset = imgGutterWidth + combinedImgWidth / 2.0 - sourceCentroid.x;
    float yOffset = 0 + combinedImgHeight / 2.0 - sourceCentroid.y;
//    ofTranslate(imgGutterWidth, 0); // translate outside of the gutter
//
//      // sadly cannot do this scaling since it breaks the shader
//      ofTranslate(combinedImgWidth / 2.0, combinedImgHeight / 2.0);
//    //  ofScale(combinedImgWidth / (sourceBbox.getWidth() * 1.5));
//      ofTranslate(-sourceCentroid.x, -sourceCentroid.y);
    shader.setUniform1f("xOffset", xOffset); //imgGutterWidth);
    shader.setUniform1f("yOffset", yOffset);
    shader.setUniform2f("mouse", blend * combinedImgWidth, blend * combinedImgHeight); // TODO
    shader.setUniform2f("screen", combinedImgWidth, combinedImgHeight);
    sourceMesh.drawFaces();
    shader.end();
    
    
    if (showWireframe) {
      ofSetColor(255, 0, 0);
      sourceMesh.drawWireframe();
      ofSetColor(255);
    }
  }
  ofPopMatrix();
  
  
  // draw just the face portion of the source
  // draw just the face portion of the target
  
  // normalize source and target to be the same shape
  // --> or just try drawing the target in the shape of the source.
  
  
  
  // draw target image
  ofPushMatrix();
  //  ofTranslate(500, 0); // FIXME was 800
  ofSetColor(255);
  //    targetImg.draw(0, 0);
  //    trackerTarget.drawDebug();
  
  if (trackerTarget.size() > 0) {
    auto &landmarks = trackerTarget.getInstances()[0].getLandmarks();
    ofMesh targetMesh = landmarks.getImageMesh();
    auto vertices = targetMesh.getVertices();
    int numVx = vertices.size();
    for (int i = 0; i < numVx; ++i) {
      targetMesh.addTexCoord(vertices[i]);
    }
    
    
    // DRAW: draw target face
    ofPushMatrix();
    // scale to fit in margin
    auto targetCentroid = targetMesh.getCentroid();
    ofRectangle targetBbox(targetMesh.getVertex(0), 1, 1);
    for (int i = 1; i < targetMesh.getNumVertices(); ++i) {
      targetBbox.growToInclude(targetMesh.getVertex(i));
    }
    ofTranslate(imgGutterWidth / 2.0, imgGutterHeight * 0.75);
    ofScale(imgGutterWidth / targetBbox.getWidth());
    ofTranslate(-targetCentroid.x, -targetCentroid.y);
    
    targetImg.bind();
    targetMesh.drawFaces();
    targetImg.unbind();
    ofPopMatrix();
    
    
    if (showWireframe) {
      ofSetColor(0, 255, 0);
      targetMesh.drawWireframe();
      ofSetColor(255);
      
      auto &targetLandmarks = trackerTarget.getInstances()[0].getLandmarks();
      auto targetPts = targetLandmarks.getImagePoints();
      
      ofxDelaunay targetTri;
      for (int i = 0; i < targetPts.size(); ++i) {
        targetTri.addPoint(targetPts[i]);
      }
      targetTri.triangulate();
      ofMesh targetMesh2 = targetTri.triangleMesh;
      ofSetColor(255, 255, 0);
      targetMesh2.drawWireframe();
      ofSetColor(255);
    }
    
  }
  
  
  ofPopMatrix();
  
  // draw source img
  if (trackerSource.size() > 0) {
    // MARK - DRAW: draw the source face mesh using the sourceImg as a texture
    ofPushMatrix();
    // scale to fit in margin
    auto sourceCentroid = sourceMesh.getCentroid();
    ofRectangle sourceBbox(sourceMesh.getVertex(0), 1, 1);
    for (int i = 1; i < sourceMesh.getNumVertices(); ++i) {
      sourceBbox.growToInclude(sourceMesh.getVertex(i));
    }
    ofTranslate(imgGutterWidth / 2.0, imgGutterHeight * 0.25);
    ofScale(imgGutterWidth / sourceBbox.getWidth());
    ofTranslate(-sourceCentroid.x, -sourceCentroid.y);
    
    
    sourceImg.bind();
    sourceMesh.drawFaces();
    sourceImg.unbind();
    ofPopMatrix();
    
    
    if (showWireframe) {
      ofSetColor(255, 0, 0);
      sourceMesh.drawWireframe();
      ofSetColor(255);
    }
    
    //    ofPushMatrix();
    //    ofTranslate(400, 0);
    //    ofPopMatrix();
  }
  
  
  ofPopMatrix();
}
