#include "Particle.h"

Particle::Particle(Parameters* parameters) {
  isAlive = false;
  param = parameters;
}

void Particle::setup(float newHueMin, float newHueMax) {
  position = param->startingPoint + randomPointOnCircle(param->radius);
  speed = randomPointOnCircle(param->maxSpeed);
  age = 0;
  maxAge = param->lifeTime;
  isAlive = true;
  hue_min = newHueMin;
  hue_max = newHueMax;
}

void Particle::update(float elapsedTime) {
	if (!isAlive) return;
	speed.rotate(0, 0, param->rotate* elapsedTime);

	ofVec3f acceleration;
	ofVec3f distance = position - param->startingPoint;
	//bekijk of de particles ergens in de cirkel bevindt
	if (ofInRange(distance.length(), 0, param->radius)) {
		distance.normalize(); //max 1 lang, of anders schieten de deeltjes heel ver
		acceleration += distance * param->force;
		acceleration.x = -distance.y * param->spinning;
		acceleration.y = distance.x * param->spinning;
	}

	speed += acceleration * elapsedTime;
	speed *= (1 - param->friction); //hoe groter de friction, hoe langzamer die gaat

	position += speed* elapsedTime;
	age += elapsedTime;
	if (age >= maxAge) isAlive = false;
}

void Particle::draw() {
	ofColor color = ofColor::red;
	float hue = ofMap(age, 0, maxAge, hue_min, hue_max);
	color.setHue(hue);
	ofSetColor(color);
	float size = ofMap(maxAge - age, 0, maxAge, 3, 1);
	ofDrawCircle(position, size);
}

ofPoint Particle::randomPointOnCircle(float maxRadius) {
  ofPoint point;
  float radius = ofRandom(0, maxRadius);
  float angle = ofRandom(0, M_TWO_PI);

  point.x = cos(angle) * radius;
  point.y = sin(angle) * radius;

  return point;
}
/*
void Particle::updateSpeed(float speedXS, float speedYS) {
	speed.set(speedXS, speedYS, 0);
}
*/