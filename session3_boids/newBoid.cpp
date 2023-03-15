#include "newBoid.h"
#include "ofMain.h"


newBoid::newBoid()
{
	separationWeight = 1.0f;      
	cohesionWeight = 0.2f;
	alignmentWeight = 0.1f;

	separationThreshold = 10;
	neighbourhoodSize = 100;

	//position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
	position = ofVec3f(500, 500);
	velocity = ofVec3f(ofRandom(-1, 1), ofRandom(-1, 1));
}

newBoid::newBoid(ofVec3f& pos, ofVec3f& vel)
{
	separationWeight = 1.0f;
	cohesionWeight = 0.2f;
	alignmentWeight = 0.1f;

	separationThreshold = 30;
	neighbourhoodSize = 100;

	position = pos;
	velocity = vel;
}

newBoid::~newBoid()
{

}


ofVec3f newBoid::notice(std::vector<Boid*> boids)	 // this should point to the original boids
{
    // this function works like the separation function to let the new vector of boids notice the original vector and avoid 
	for (int i = 0; i < boids.size(); i++)
	{
		if (position.distance(boids[i]->getPosition()) < 60)
		{
			ofVec3f v = position - boids[i]->getPosition();
			v.normalize();   // unitvector of distance -> distance between the normalised unit vector and normalised distance ????? 
			// can be a random direction instead of the opposite
			return v;
		}
	}
}


void newBoid::draw() {
	ofSetColor(144, 238, 144);
	ofDrawCircle(position.x, position.y, 5);
}