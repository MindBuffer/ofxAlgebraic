ABOUT ALGEBRAIC
===============

ofxAlgebraic will return f(value) where value is passed in through
setup(float _value). It's made to semantically simplify basic
trigonometry and bezier functions over two dimensions.

Without any input, ofxAlgebraic_ will return 1.0f.

ofxAlgebraic_ will take into account any information you give it.

It includes support for:
   * Sine
   * Cosine
   * Sawtooth
   * Square
   * RandomWalk
   * Random
   * Triangle (not yet implemented)

Over any of the following:
   * Gradient
   * Bezier
   * Exponential (not yet implemented)

The signal is modulated by the following (REMEMBER, each of these can be
modulated with the results of another "ofxAlgebraic_" object):
   * Amplitude
   * Frequency 

The "gradient" is added to the result (determined by entering the x & y
co-ordinates).
 
EXAMPLE:
--------
    
        float answer = ofxAlgebraic_<>(0.5f).getSine();

Or include gradient, bezier, frequency and amplitude as well:

        ofxAlgebraic_<float> algebraic(0.3f);
        algebraic.setGradient(1.f, 4.f);
        algebraic.setAmplitude(0.8f);
        algebraic.setFrequency(3.f);
        algebraic.setBezierDepth(-0.5f);
        float answer = algebraic.getSine() * algebraic.getSaw();

This is an Adventure-Time-inspired ofx template by Mitchell Nordine.