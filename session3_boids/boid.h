/*

 *
 */

#ifndef _BOID
#define _BOID
#include <vector>
#include "ofMain.h"

class Boid
{
	// all the methods and variables after the
	// private keyword can only be used inside
	// the class

	// each boid is an instance of the same class
    // all the methods and variables after the
	// public keyword can only be used by anyone
public:
	ofVec3f position;
	ofVec3f velocity;

	float separationWeight;
	float cohesionWeight;
	float alignmentWeight;

	float separationThreshold;
	float neighbourhoodSize;

	virtual ofVec3f notice(std::vector<Boid*> newBoids);

	// of vector functions that takes a vector of pointers to boids as an input. return a vector of free float 
	ofVec3f separation(std::vector<Boid*>& otherBoids);
	ofVec3f cohesion(std::vector<Boid*>& otherBoids);
	ofVec3f alignment(std::vector<Boid*>& otherBoids);

	Boid();
	Boid(ofVec3f& pos, ofVec3f& vel);

	~Boid();

	ofVec3f getPosition();
	ofVec3f getVelocity();


	float getSeparationWeight();
	float getCohesionWeight();
	float getAlignmentWeight();

	float getSeparationThreshold();
	float getNeighbourhoodSize();

	void setSeparationWeight(float f);
	void setCohesionWeight(float f);
	void setAlignmentWeight(float f);

	void setSeparationThreshold(float f);
	void setNeighbourhoodSize(float f);

	void update(std::vector<Boid*>& otherBoids, ofVec3f& min, ofVec3f& max);

	void walls(ofVec3f& min, ofVec3f& max);

	virtual void draw();	// virtual makes it possible to override this function 
};


#endif

