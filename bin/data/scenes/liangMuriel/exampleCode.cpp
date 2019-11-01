//art work by Muriel Cooper
//recoded by Liang Zhipeng
for (int i = -0.8*center_x; i < 0.6 * center_x+[[Size]]; i+=[[Size]]){
    int w=0;
    for (int j = -0.4*center_y; j < (2*[[Size]]-i - 0.4* center_y); j+=[[Size]]){
        ofDrawLine(i, j, i+[[Distance]]*[[Size]]+[[Wind]]ofRandom(-1,1), j-[[Distance]][[Size]]+[[Wind]]*ofRandom(-1,1));
        if(w==((2*[[Size]]-i)/[[Size]])){
            ofDrawLine(i+[[Size]], j+[[Size]], i+[[Size]]+[[Distance]]*[[Size]]+[[Wind]]ofRandom(-1,1), j+[[Size]]-[[Distance]][[Size]]+[[Wind]]*ofRandom(-1,1));
}}}
ofTranslate(center_x+[[Distance]]*[[Size]]+[[Wind]]*0.1*ofRandom([[Wind]]*0.01,[[Wind]]0.1), center_y-[[Distance]][[Size]]-[[Wind]]*0.1*ofRandom([[Wind]]*0.01,[[Wind]]*0.1));
        for (int i = -0.8*center_x; i < 0.6 * center_x; i+=[[Size]]){
            for (int j = -0.4*center_y; j < ([[Size]]-i - 0.4* center_y); j+=[[Size]]){
ofSetColor([[Wind]]*ofRandom(0,1),[[Wind]]*ofRandom(0,1),[[Wind]]*ofRandom(0,1));
                ofDrawRectangle(i, j, [[Size]], [[Size]]);
                }}
for (int i = -0.8*center_x; i < 0.6 * center_x; i+=[[Size]]){
        for (int j = -0.4*center_y; j < ([[Size]]-i - 0.4* center_y); j+=[[Size]]){
            ofSetColor([[Wind]]*ofRandom(0,1),[[Wind]]*ofRandom(0,1),[[Wind]]*ofRandom(0,1));
            ofSetLineWidth(5);
            ofNoFill();
            ofDrawRectangle(i, j, [[Size]], [[Size]]);
            }
    }
