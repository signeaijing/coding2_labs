#include "testApp.h"

testApp::~testApp()     // this is the destructor - here we delete all the boids - could be done delete [] boids; 
{
	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
	// remember to delete the NEW BOIDS HERE!!! 
	for (int k = 0; k < newBoids.size(); k++)
		delete newBoids[k];
    // delete [] BoidNew;      
}

//--------------------------------------------------------------
void testApp::setup(){
	
	
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	ofBackground(255, 255, 102);
	
	// set up the boids
	for (int i = 0; i < 50; i++) {
		boids.push_back(new Boid());
		//¤¤boids.push_back(new newBoid());
	}

	for (int k = 0; k < 50; k++)  
		newBoids.push_back(new newBoid());


	// you can do this instead of creating a new boid and then add the syntax above instead of creating a new for loop ¤¤
	//Boid* myNewBoid = new newBoid();
}


//--------------------------------------------------------------
void testApp::update(){
	
    ofVec3f min(0, 0);
	ofVec3f max(ofGetWidth(), ofGetHeight());
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids, min, max);   // we have to use -> because the object boid is a pointer 
	}

	for (int k = 0; k < newBoids.size(); k++) {
		newBoids[k]->update(newBoids, min, max);
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
	}
	// make new for loop to draw the new flock

	for (int k = 0; k < newBoids.size(); k++)
		newBoids[k]->draw();
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
 
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}
