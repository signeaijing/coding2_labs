#pragma once
#ifndef _NEWBOID
#define _NEWBOID
#include <vector>
#include <boid.h>
#include "ofMain.h"

// CREATES NEW CHILD CLASS THAT INHERITS FROM CLASS BOID
class newBoid : public Boid {        
public:	
    void draw();       // this overrides the draw() function in parent class

	newBoid();
	newBoid(ofVec3f& pos, ofVec3f& vel);

	~newBoid();
	ofVec3f notice(std::vector<Boid*> boids);        // notice the other flock
};



#endif