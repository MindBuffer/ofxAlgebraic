#pragma once

#include "ofMain.h"
#include "Algebraic.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

        Algebraic osc;
        float signal;
        float phase;
        int shape;
		
};
