#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    
    //Initialize the drawing variables
    for (int i = 0; i < ofGetWidth(); ++i) {
        waveform[i] = 0;
    }
    waveIndex = 0;
    
    // Maximilian audio stuff
    int sampleRate = 44100;  /* Sampling Rate */
    int bufferSize= 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    ofSoundPlayer mySound;          // create to multiplay in draw / audio out 

    myClock.setTempo(myTempo);
    myClock.setTicksPerBeat(ticks);

    // LOAD IN MY FILES connected to the variable vi lige har declared i header file -> definerer her 
    dababyBass.load(ofToDataPath("dababy_bass.wav")); //oftodatapath tells the maxisample where the file is located if it is in the data folder! 
    megaBass.load(ofToDataPath("kick_mega_bass.wav"));    // skal stå op tappe hurtigt i baggrunden 
    metroBass.load(ofToDataPath("metro-bass.wav"));    // ret ofte men ikke hele tiden
    straightBass.load(ofToDataPath("straight-bass.wav"));
    lighter.load(ofToDataPath("lighter.wav"));
    cling.load(ofToDataPath("snare-cling.wav"));
    ping.load(ofToDataPath("sonar-ping.wav"));

        // Setup ofSound
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){               
    /////////////// waveform
    ofTranslate(0, ofGetHeight()/2);
    ofSetColor(150, 0, 150);
    ofFill();
    ofDrawBezier(0, 0, waveform[1] * ofGetHeight()/2.,myFreq,5,3,2,1); //first line
    for(int i = 1; i < (ofGetWidth() - 1); ++i) {
        ofDrawLine(i, waveform[i] * ofGetHeight()/2., i + 1, waveform[i+1] * ofGetHeight()/2.);
    }
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer& input){
    std::size_t nChannels = input.getNumChannels();
    for (size_t i = 0; i < input.getNumFrames(); i++)
    {
    }
}
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer& output){      // this is the main thing -> har sætter vi de ting sammen som skal komme ud    
    std::size_t outChannels = output.getNumChannels();
    for (int i = 0; i < output.getNumFrames(); ++i){   // everything needs to go in this for loop
        
        myClock.ticker();
        //myFreq += 1   // -> kan kontrollere at snare.trigger ikke bliver trigget hele tiden fordi den ene operator for modulo ændrer sig  

        // setting up random num generator
        int random_num;
        int k;
        srand(time(0));
        for (k = 1; k <= 10; k++) {
            //int val = 0;
           // int random_val = ofClamp(val, 1, 100);
          
           random_num = rand() % 100;
        }
        
        if (myClock.tick && myClock.playHead % 15 == 0) {
            straightBass.trigger();
            counter += 1;     
            // triggerGain = 7;
        }

        if (myClock.tick && myClock.playHead % 20 == 0) {
            dababyBass.trigger();
        }

        // one case with this and one where metrobass is random
        if (myClock.tick && myClock.playHead % 100 == 10) {
            metroBass.trigger();
        }

        if (myClock.tick && myClock.playHead % myFreq == 0) {
            lighter.trigger();
        }

        if (random_num >= 10 && myClock.playHead % -240 == 0) {
            ping.trigger();
        }

         // putter play i variabele 
        double megaBass_out = megaBass.playOnce();
        double straightBass_out = straightBass.playOnce();
        double metroBass_out = metroBass.playOnce();
        double dababyBass_out = dababyBass.playOnce();
        double lighter_out = lighter.playOnce();
        double cling_out = cling.playOnce();
        double ping_out = ping.playOnce();

        // to play samples use. drum.play() 


        // switch state where all the basses always is playing and based on them -> the others come in

     
     
       // output[i * outChannels] = drum_out + megaBass + myOsc1.sinewave(220 + myOsc2.sinewave(50)*100) * 0.5;
      
       output[i * outChannels] = straightBass_out + dababyBass_out + metroBass_out  + ping_out*5 + cling_out + myOsc1.sinewave(0.7)*lighter_out;
       output[i * outChannels + 1] = output[i * outChannels];

        //Hold the values so the draw method can draw them
        waveform[waveIndex] =  output[i * outChannels];
        if (waveIndex < (ofGetWidth() - 1)) {
            ++waveIndex;
        } else {
            waveIndex = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
