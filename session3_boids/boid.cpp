/*
 *  boid.cpp
 *  boids
 *
 *  Created by Marco Gillies on 05/10/2010.
 *  Copyright 2010 Goldsmiths, University of London. All rights reserved.
 *
 */

#include "boid.h"
#include "ofMain.h"

Boid::Boid()
{
	separationWeight = 1.0f;
	cohesionWeight = 0.2f;
	alignmentWeight = 0.1f;
	
	separationThreshold = 15;
	neighbourhoodSize = 100;
	
	//position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
	position = ofVec3f(500, 500);
	velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
}

Boid::Boid(ofVec3f &pos, ofVec3f &vel)
{
	separationWeight = 1.0f;
	cohesionWeight = 0.2f;
	alignmentWeight = 0.1f;
	
	separationThreshold = 15;
	neighbourhoodSize = 100;
	
	position = pos;
	velocity = vel;
}

Boid::~Boid()
{
	
}

float Boid::getSeparationWeight()
{
	return separationWeight;
}
float Boid::getCohesionWeight()
{
	return cohesionWeight;
}

float Boid::getAlignmentWeight()
{
	return alignmentWeight;
}


float Boid::getSeparationThreshold()
{
	return separationThreshold;
}

float Boid::getNeighbourhoodSize()
{
	return neighbourhoodSize;
}


void Boid::setSeparationWeight(float f)
{
	separationWeight = f;
}
void Boid::setCohesionWeight(float f)
{
	cohesionWeight = f;
}

void Boid::setAlignmentWeight(float f)
{
	alignmentWeight = f;
}


void Boid::setSeparationThreshold(float f)
{
	separationThreshold = f;
}

void Boid::setNeighbourhoodSize(float f)
{
	neighbourhoodSize = f;
}


ofVec3f Boid::getPosition()
{
	return position;
}

ofVec3f Boid::getVelocity()
{
	return velocity;
}


ofVec3f Boid::notice(std::vector<Boid*>newBoids)	  // this points to the new boids
{
	 //should probably find the nearest one
		// can you figure out how to do that?
		// if a boid gets within a certain threshold distance of another boid it moves away    
		// uses the unit vector 
		// we pass the array of boids into the boids and each one look for the threshold by getting the position of all the other boids
	for (int i = 0; i < newBoids.size(); i++)
	{
		if (position.distance(newBoids[i]->getPosition()) < 60)
		{
			ofVec3f v = position - newBoids[i]->getPosition();
			v.normalize();   // unitvector of distance -> distance between the normalised unit vector and normalised distance ????? 
		    //can be a random direction instead of the opposite
		return v;
		}
	}
}

ofVec3f Boid::separation(std::vector<Boid *> &otherBoids)
{
	// finds the first collision and avoids that
	// should probably find the nearest one
	// can you figure out how to do that?
	// if a boid gets within a certain threshold distance of another boid it moves away 
	// uses the unit vector 
	// we pass the array of boids into the boids and each one look for the threshold by getting the position of all the other boids
	for (int i = 0; i < otherBoids.size(); i++)
	{	
		if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
		{
			ofVec3f v = position -  otherBoids[i]->getPosition();
			v.normalize();   // unitvector of distance -> distance between the normalised unit vector and normalised distance ????? 
			// can be a random direction instead of the opposite
			return v;
		}
	}
}

// keeps it in the flock 
// moving towards the center of mass. getting the position of all the boids and getting the average 
ofVec3f Boid::cohesion(std::vector<Boid *> &otherBoids)
{
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getPosition();
			count += 1;
		}
	}
	
	average /= count;
	ofVec3f v =  average - position;
	v.normalize();
	return v;
}

// create a new flock - the second looks different but should inherit everything from the other class 
// get the two flocks to notice each other 

// how we decide which direction to head the flock in 
// steer toward the average heading 
ofVec3f Boid::alignment(std::vector<Boid *> &otherBoids)
{
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getVelocity();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v =  average - velocity;
	v.normalize();
	return v;
}
// we add a direction to the current direction that represents the direction of every other boid -> calculating the average heading / the average normalised vector

void Boid::update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max)
{
	velocity += separationWeight*separation(otherBoids);
	velocity += cohesionWeight*cohesion(otherBoids);
	velocity += alignmentWeight*alignment(otherBoids);
	
	walls(min, max);
	position += velocity;
}

void Boid::walls(ofVec3f &min, ofVec3f &max)
{
	if (position.x < min.x){
		position.x = min.x;
		velocity.x *= -1;
	} else if (position.x > max.x){
		position.x = max.x;
		velocity.x *= -1;
	}
	
	if (position.y < min.y){
		position.y = min.y;
		velocity.y *= -1;
	} else if (position.y > max.y){
		position.y = max.y;
		velocity.y *= -1;
	}
	
	
}

void Boid::draw()   // do we want this in private because the new boids should be different ? we could but don't have to because we use virtual
{
	ofSetColor(186,85,211);
	ofDrawCircle(position.x, position.y, 7);
}
