/**********************************************************************************
 
 THIS SOFTWARE IS FREE AS IN FREEDOM
 
 2014 Mitchell Nordine (www.mitchellnordine.com)
 
 **********************************************************************************/


#include "ofxAlgebraic.h"

//------------------------------

template<typename T> ofxAlgebraic_<T>::ofxAlgebraic_(T _value)
: value(_value)
, pointX(1.f)
, pointY(0.f)
, gradient(1.f)
, bezierDepth(0.f)
, frequency(1.f)
, amplitude(1.f)
, min(0.f)
, max(0.f)
, bezier(0.f)
{
    assert(std::tr1::is_floating_point<T>::value && "ERROR: ofxAlgebraic_ MUST BE either float, double or long double! you NUGGET!");
}

//------------------------------

template<typename T> void ofxAlgebraic_<T>::setup(T _value)
{
    value = _value;
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getSine()
{
    return getSignal(sin(TWO_PI * value * frequency / pointX));
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getCosine()
{
    return getSignal(cos(TWO_PI * value * frequency / pointX));
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getTri()
{
    float phase = sin(TWO_PI * value * frequency / pointX);
    
    if(phase>0.0){
        return getSignal(fmod(value * (frequency*-1) / pointX, 1.0f) * 4 + 1);
    } else if(phase<0.0){
        return getSignal(fmod(value * frequency / pointX, 1.0f) * 4 - 3.0);
    }
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getSaw()
{
    return getSignal(fmod(value * frequency / pointX, 1.0f) * 2 - 1);
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getRamp()
{
    return getSignal(fmod(value * (frequency*-1) / pointX, 1.0f) * 2 + 1);
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getSquare()
{
    return getSignal((sin(TWO_PI * value * frequency / pointX) >= 0) ? 1.f : -1.f);
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getRandom()
{
    return getSignal(ofRandom(-1.0f, 1.0f));
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getNoiseWalk()
{
    return getSignal(ofSignedNoise(value * frequency / pointX));
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::setAmplitude(T _amplitude)
{
    return amplitude = _amplitude;
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::setFrequency(T _frequency)
{
    return frequency = _frequency;
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getWithAmplitude(T value)
{
    return value * amplitude;
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::setGradient(T _pointX, T _pointY)
{
    pointX = _pointX;
    pointY = _pointY;
    if (!max) max = pointX; // If no max, assign pointX
    return gradient = (float)pointY / (float)pointX;
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getSignal(T _value)
{
    return getWithAmplitude(_value) + getBezier();
}

template<typename T> T ofxAlgebraic_<T>::getSignal()
{
    return getBezier();
}

//------------------------------
/* This function uses the point used to determine the gradient, to instead
   interpolate along a bezier curve. The "x" value for the point influencing
   the curve is always halfway between 0.0f & pointX. It's "y" value is determined
   by the "BezierDepth" variable.
 */

template<typename T> T ofxAlgebraic_<T>::getBezier()
{
    /* Points needed for Bezier:
     T x1 = 0.0
     T x2 = pointX/2.0f
     T x3 = pointX
     T y1 = 0.0 */
     T y2 = (pointY/(T)2.f) + bezierDepth*(pointY/(T)2.f); /*
     float y3 = pointY */
    
    T valueRelative = value / pointX;
    
    /* Re-adjust linear trajectory for each step */
    //float xa = getBezierPt(0.0f, x2, value);
    T ya = getBezierPt((T)0.f, y2, valueRelative);
    //float xb = getBezierPt(x2, pointX, value);
    T yb = getBezierPt(y2, pointY, valueRelative);
    
    return getBezierPt(ya, yb, valueRelative);
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::getBezierPt(T n1, T n2, T perc)
{
    float difference = n2 - n1;
    return n1 + (difference * perc);
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::setBezierDepth(T _depth)
{
    return bezierDepth = _depth;
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::setMin(T _min)
{
    return min = _min;
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::setMax(T _max)
{
    return max = _max;
}

//------------------------------

template<typename T> T ofxAlgebraic_<T>::setMinMax(T _min, T _max)
{
    min = _min;
    max = _max;
    return max - min;
}

//------------------------------

template class ofxAlgebraic_<float>;
template class ofxAlgebraic_<double>;
template class ofxAlgebraic_<long double>;
