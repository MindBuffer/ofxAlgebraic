#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    shape = 2;
    phase = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){

    float speed = ofMap(mouseX, 0, ofGetWidth(), 0.0, 4.0);
    phase = ofGetElapsedTimef() * speed;
    
    osc.setAmplitude(ofMap(mouseY, 0, ofGetHeight(), 0.0, 1.0));
    osc.setFrequency(phase);
    
    switch (shape) {
        case 0:
            signal = ofClamp(osc.getSine(),-1.0,1.0);
            break;
        case 1:
            signal = ofClamp(osc.getTriangle(),-1.0,1.0);
            break;
        case 2:
            signal = ofClamp(osc.getRamp(),-1.0,1.0);
            break;
        case 3:
            signal = ofClamp(osc.getSaw(),-1.0,1.0);
            break;
        case 4:
            signal = ofClamp(osc.getSquare(),-1.0,1.0);
            break;
        case 5:
            signal = ofClamp(osc.getRandom(),-1.0,1.0);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    ofLine(ofGetWidth()/2, (ofGetHeight()/2)+signal, ofGetWidth()/2, (ofGetHeight()/2)+signal*200);
    ofEllipse(ofGetWidth()/2,(ofGetHeight()/2)+signal*200,8,8);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case '1': shape = 0; break;
        case '2': shape = 1; break;
        case '3': shape = 2; break;
        case '4': shape = 3; break;
        case '5': shape = 4; break;
        default:
            break;
    }
}
