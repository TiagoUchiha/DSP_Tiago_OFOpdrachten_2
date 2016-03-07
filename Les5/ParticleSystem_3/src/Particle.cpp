#include "Particle.h"

Particle::Particle() {
	isAlive = false;

}

void Particle::setup(ofPoint start, float radius, float velocityRadius, float maxAge, float rotateSpeed) {
	position = startingPoint + randomPointOnCircle(radius);

}

void Particle::randomPointOnCircle(float maxRadius) {
	ofPoint pnt;
	float radius = ofRandom(0, maxRadius);
	float angle = ofRandom(0, M_TWO_PI);

	pnt.x = cos(angle) * radius;
	pnt.y = sin(angle) * radius;

}

void Particle::update(float elapsedTime) {

}

void Particle::draw() {

}