ofxAlgebraic
============

ofxAlgebraic will return f(value) where value is passed in through either
the constructor or setup(T _value). It's made to semantically simplify basic
trigonometry and bezier functions over two dimensions.

Without any input, ofxAlgebraic will return 1.0f.

ofxAlgebraic will take into account any information you give it.

It includes methods for retrieving values over:
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
modulated with the results of another "ofxAlgebraic" object):
   * Amplitude
   * Frequency

The "gradient" is added to the result (determined by entering the x & y
co-ordinates).
 
EXAMPLE
-------

Each of the types are as follows:

        ofxAlgebraic_<T>(T _value);
        ofxAlgebraic(float _value);
        ofxAlgebraicFloat(float _value);
	ofxAlgebraicDouble(double _value);
	ofxAlgebraicLongDouble(long double _value);

You can use it like this:
    
        float answer = ofxAlgebraic(0.5f).getSine();

Or include gradient, bezier, frequency and amplitude as well:

        ofxAlgebraic_<float> algebraic(0.3f);
        algebraic.setGradient(1.f, 4.f);
        algebraic.setAmplitude(0.8f);
        algebraic.setFrequency(3.f);
        algebraic.setBezierDepth(-0.5f);
        float answer = algebraic.getSine() * algebraic.getSaw();

This is an Adventure-Time-inspired ofx template by Mitchell Nordine.