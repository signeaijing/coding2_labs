#include "ofMain.h"
#include "ofApp.h"
#include <random>
#include <stdlib.h>    // dette er for at kunne lave random numbers 

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
	using namespace std;
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
