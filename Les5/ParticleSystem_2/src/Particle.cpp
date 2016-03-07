#include "Particle.h"

Particle::Particle(int x, int y) {
	position.set(x, y);
	radius = 40;

}

void Particle::update() {
	position += speed;

}

void Particle::draw() {
	ofSetColor(0, 0, 150, 150);
	ofDrawCircle(position, radius);

}