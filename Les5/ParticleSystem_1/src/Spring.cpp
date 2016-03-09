#include "Spring.h"

Spring::Spring(Particle* firstParticle, Particle* secondParticle) {
	first = firstParticle;
	second = secondParticle;
}

void Spring::draw() {
	ofSetColor(ofColor::white);
	ofDrawLine(first->position, second->position);
}

void Spring::update() {
	float distance = first->position.distance(second->position);
	ofVec3f direction = second->position - first->position;
	direction.normalize(); // terug brengt tot de lengte maar 1 is
	direction *= (distance - 100) / 100;  //(distance - length)/ length; weggehaald
	first->speed += direction;
	second->speed -= direction;
}