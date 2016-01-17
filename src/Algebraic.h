//
//  Algebraic.h
//  jenMax
//
//  Created by Mitchell Nordine on 5/08/13.
//
//

#ifndef __jenMax__Algebraic__
#define __jenMax__Algebraic__

/* Header Includes */

#include "ofMain.h"
#include "JenGaussian.h"

/* Class */

class Algebraic {
    
public:
    
    /* Constructors & Destructors */
    
    Algebraic(){
        isDMXMode = false;
        value = 1.0f;
        originalValue = 1.0f;
        pointX = 1.0f;
        pointY = 0.0f;
        gradient = 1.0f;
        bezierDepth = 0.0f;
        frequency = 1.0f;
        amplitude = 1.0f;
        min = -1.0f;
        max = 1.0f;
        bezier = 0.0f;
    }
    
    ~Algebraic(){
        
    }
    
    /* Functions */
    void setup(float value);
    float setGradient(float pointX, float pointY);
    float setMin(float _min);
    float setMax(float _max);
    float setMinMax(float _min, float _max);
    void setDMXMode(bool val);
    bool getIsDMXMode();
    
    float getSine();
    float getTriangle();
    float getSaw();
    float getRamp();
    float getSquare();
    float getRandom();
    float getNoiseWalk();
    float getGaussian();
    
    float getSignal(float value);
    float getSignal();
    
    float getBezier();
    float getBezierPt(float n1, float n2, float perc);
    float setBezierDepth(float _depth);
    
    float setFrequency(float _frequency);
    float setAmplitude(float _amplitude);
    float getWithAmplitude(float value);
    
    /* Variable Declaration */
    
    float value;
    float originalValue;
    float pointX;
    float pointY;
    float min;
    float max;
    
    float gradient;
    
    float bezier;
    float bezierDepth;
    
    float frequency;
    float amplitude;
    
    bool isDMXMode; // If false then osc = -1. 1. ; // else osc mid point is determined by amplitude.
    
    /* Class Instances */
    
};


#endif /* defined(__jenMax__Algebraic__) */
