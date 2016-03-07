#include "Spring.h"

Spring::Spring(Particle* first, Particle* second) {
	this->first = first;
	this->second = second;
}

void Spring::draw() {
	ofSetColor(ofColor::white);
	ofDrawLine(first->position, second->position);
}

void Spring::update() {
	float distance = first->position.distance(second->position);
	ofVec3f direction = second->position - first->position;
	direction.normalize(); // terug brengt tot de lengte maar 1 is
	direction *= (distance - length) / 100;
	first->speed += direction;
	second->speed -= direction;
}