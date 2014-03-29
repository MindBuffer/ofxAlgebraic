/**********************************************************************************
 
 THIS SOFTWARE IS FREE AS IN FREEDOM
 
 Copyright (C) 2014 Mitchell Nordine (www.mitchellnordine.com)
 
 **********************************************************************************/


#ifndef __ofxAlgebraic___
#define __ofxAlgebraic___

#include "ofMain.h"

template <typename T = float> class ofxAlgebraic_ {
    
public:
    
    ofxAlgebraic_(T _value = 1); // You can pass your value in here if you want.
    
    /* Functions */
    void setup(T value); // Otherwise just pass it in here.
    T setGradient(T pointX, T pointY);
    T setMin(T _min);
    T setMax(T _max);
    T setMinMax(T _min, T _max);
    
    T getSine();
    T getCosine();
    T getSaw();
    T getSquare();
    T getRandom();
    T getNoiseWalk();
    
    T getSignal(T value);
    T getSignal();
    
    T getBezier();
    T getBezierPt(T n1, T n2, T perc);
    T setBezierDepth(T _depth);
    
    T setFrequency(T _frequency);
    T setAmplitude(T _amplitude);
    T getWithAmplitude(T value);
    
private:
    
    T value;
    T pointX;
    T pointY;
    T min;
    T max;
    T gradient;
    T bezier;
    T bezierDepth;
    T frequency;
    T amplitude;
    
};

typedef ofxAlgebraic_<float> ofxAlgebraic;
typedef ofxAlgebraic_<float> ofxAlgebraicFloat;
typedef ofxAlgebraic_<double> ofxAlgebraicDouble;
typedef ofxAlgebraic_<long double> ofxAlgebraicLongDouble;

#endif /* defined(__ofxAlgebraic___) */
