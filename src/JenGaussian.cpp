//
//  JenGaussian.cpp
//  GenMax
//
//  Created by Mitchell Nordine on 22/09/13.
//
//

#include "JenGaussian.h"

//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
bool haveNextNextGaussian = false;
float nextNextGaussian;
//--------------------------------------------------------------------------------//
// GAUSSIAN FUNTION
//--------------------------------------------------------------------------------//

float JenGaussian() {
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        
        multiplier = v1 * multiplier;
        ofMap(multiplier, -2.0, 2.0, -1.0, 1.0);
        if (multiplier>1) {
            multiplier = multiplier - (multiplier-1)*2;
        }
        else if (multiplier<-1) {
            multiplier = multiplier + (multiplier+1)*2;
        }
        ofClamp(multiplier, -1.0, 1.0);
        
        return multiplier;
    }
}

//--------------------------------------------------------------------------------//
// ALTERNATE GAUSSIAN FUNCTION
//--------------------------------------------------------------------------------//
// This function is designed for applying gaussian randomness to "float original"
// (between 0. & 1.) with a level of randomness ("randomness") value (0 being no
// randomness, 1 being completely random).

float JenGaussianAlt(float original, float randomness) {
    
    float answer;
    
    answer = JenGaussian()*(randomness*0.5) + (original*2-1.0);
    answer = ofMap(answer, -1.0, 1.0, 0.0, 1.0);
    
    if (answer > 1){
        answer = answer - (answer-1)*2;
    }
    else if (answer < 0){
        answer = answer * -1.0;
    }
    
    return answer;
    
}