#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"  
#include "ofMath.h"

class ofApp : public ofBaseApp{
    
public:
    void setup() override;
    void update() override;
    void draw() override;
    
    void keyPressed(int key) override;
    void keyReleased(int key) override;
    void mouseMoved(int x, int y ) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
    void mouseEntered(int x, int y) override;
    void mouseExited(int x, int y) override;
    void windowResized(int w, int h) override;
    void dragEvent(ofDragInfo dragInfo) override;
    void gotMessage(ofMessage msg) override;
    
    // For drawing
    float waveform[4096]; //make this bigger, just in case
    int waveIndex;
    
    ofSoundStream soundStream;
    
    /* ofxMaxi*/ //DECLARED HERE // these are member functions. IF they are in the HEADER FILE they NEED to be DEFINE them in the cpp.file. 
    void audioIn(ofSoundBuffer& input) override; // not used in this example
    void audioOut(ofSoundBuffer& output) override;   

    // my oscillators 
    maxiOsc myOsc1;
    maxiOsc myOsc2;
    maxiOsc myOsc3;
    maxiOsc myOsc4;
    maxiClock myClock;
   // maxiDelayLine myDelay;

    // my variables 
    int myFreq = 80;
    float myTempo = 120;   // sets BPM - beats per minute 
    float ticks = 10;    // set divisions per beat
    float triggerGain = 0;
    int counter = 0;

    // my sound samples -> LOAD IN SETUP! 
    maxiSample metroBass;
    maxiSample dababyBass;
    maxiSample megaBass; 
    maxiSample straightBass;
    maxiSample lighter;
    maxiSample cling;
    maxiSample ping;
};
