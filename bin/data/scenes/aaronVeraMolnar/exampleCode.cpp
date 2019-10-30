for (int j = 0; j < [[howManyXY]]; j++) {
    for (int i = 0; i < [[howManyXY]]; i++) {
        
        // iterate on repetitions
        for (int rep = 0; rep < [[howManyInside]]; rep++) {
            
            // padding percentage
            float paddingFactor = 1.0 - padding;
                
            ofRotateDeg([[rotation]]);
                
            // draw rectangle
            ofDrawRectangle(p, [[padding]], rep);
        }
    }
}
