
#include "karstenFaceMirror.h"

void karstenFaceMirror::setup(){
  
    // setup parameters
    // if your original code use an ofxPanel instance dont use it here, instead
    // add your parameters to the "parameters" instance as follows.
    // param was declared in karstenFaceMirror.h
    // parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Karsten Schuhl");
    setOriginalArtist("no reference - inspired by Jason Salavon");

    loadCode("scenes/karstenFaceMirror/exampleCode.cpp");
    
    tracker.setup();
        //Loading all images into images vector
        ofDirectory dir;
        dir.listDir("50smallFaces");
        maxImgNumber = dir.size();
        
        for(int i = 0; i < dir.size(); i++){
            ofImage temp;
            images.push_back(temp);
            images.back().load(dir.getPath(i));
        }
        
        //average loaded images into one image
        
        int w = images[0].getWidth();
        int h = images[0].getHeight();

        average.allocate(images[0].getWidth(),
                         images[0].getHeight(),
                         OF_IMAGE_COLOR);

        for (int i = 0; i < w; i++){
            for (int j = 0; j < h; j++){
                int r = 0;
                int g = 0;
                int b = 0;

                for (int k = 0; k < images.size(); k++){
                    ofColor col = images[k].getColor(i,j);

                    r += col.r;
                    g += col.g;
                    b += col.b;
                }
                r /= images.size();
                g /= images.size();
                b /= images.size();
                average.setColor(i,j, ofColor(r,g,b));
            }
        }
        average.update();
        averageLeft.allocate(images[0].getWidth(),
                             images[0].getHeight(),
                             OF_IMAGE_COLOR);
        
        averageRight.allocate(images[0].getWidth(),
                             images[0].getHeight(),
                             OF_IMAGE_COLOR);
    
        parameters.add(imgNumber.set("imgNumber", 0, 0, maxImgNumber-1));
        parameters.add(side.set("side", 0, 0, 2));
     
}

void karstenFaceMirror::update(){
    
    tracker.update(images[imgNumber]);
    int w = images[imgNumber].getWidth();
    int h = images[imgNumber].getHeight();
    
    if (tracker.size() > 0){
        ofPolyline leftEye = tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE);
            
        for (int i = 0; i < leftEye.size(); i++){
            leftAvg += leftEye[i];
        }
        leftAvg /= leftEye.size();
    
        ofPolyline rightEye = tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE);
        
        for (int i = 0; i < rightEye.size(); i++){
            rightAvg += rightEye[i];
        }
        rightAvg /= rightEye.size();
        
        diff = rightAvg - leftAvg;
        float angle = atan2(diff.y, diff.x);
        
        ofPoint midline;
        midline = leftAvg + diff/2 - padding;
        int cut = int(midline.x);
        averageLeft.cropFrom(images[imgNumber], 0, 0, cut, h);
        ofImage temp;
        temp.allocate(w-cut,h,OF_IMAGE_COLOR);
        temp.cropFrom(images[imgNumber], 0, 0, w, h);

        for (int i = 0; i < w; i++){
               for (int j = 0; j < h; j++){
                   if(i <= cut){
                       averageRight.setColor(i,j, ofColor(255,255,255));
                   } else {
                       int r = 0;
                       int g = 0;
                       int b = 0;
                       ofColor col = temp.getColor(i,j);
                       r += col.r;
                       g += col.g;
                       b += col.b;
                       averageRight.setColor(i,j, ofColor(r,g,b));
                   }
               }
           }
        }
    averageLeft.update();
    averageRight.update();
}

void karstenFaceMirror::draw(){
    
    int imgWidth = images[0].getWidth();
    int imgHeight = images[0].getHeight();
    
    ofSetColor(240);
    ofDrawRectangle(0, 0, dimensions.getWidth(), dimensions.getHeight());
    ofSetColor(255);
    ofPoint center;
    center = leftAvg + diff/2;
    ofPushMatrix();
    float scaleFactor = dimensions.getWidth()/(imgWidth+(padding*2));
    ofScale(scaleFactor, scaleFactor);
    if(side == 0){
        images[imgNumber].draw(padding, padding);
    } else if (side == 1) {
        ofSetColor(255);
        averageLeft.draw(padding,padding);
        averageLeft.mirror(false, true);
        averageLeft.draw(images[imgNumber].getWidth()/2+padding,padding);
    } else if (side == 2){
        averageRight.draw(padding,padding);
        ofImage temp;
        temp.allocate(imgWidth-center.x, imgHeight, OF_IMAGE_COLOR);
        averageRight.mirror(false, true);
        temp.cropFrom(averageRight, 0, 0, imgWidth-int(center.x-padding), imgHeight);
        temp.draw(padding,padding);
        
    }
    ofPopMatrix();
    
}
