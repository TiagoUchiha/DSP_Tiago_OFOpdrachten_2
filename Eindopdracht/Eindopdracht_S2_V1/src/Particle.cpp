#include "Particle.h"
#include <random>

ofImage Particle::image = ofImage();

Particle::Particle(Parameters* parameters) {
	isAlive = false;
	param = parameters;
}

void Particle::setup(float newHueMin, float newHueMax, float elapsedTime) {
	position = param->startingPoint + param->radius; //+ randomPointOnCircle(param->radius);
	speed = randomPointOnCircle(param->maxSpeed);
	age = 0;
	maxAge = param->lifeTime;
	isAlive = true;
	hue_min = newHueMin;
	hue_max = newHueMax;
	alpha = 255;
	timealpha = elapsedTime;

}

void Particle::update(float elapsedTime) {
	if (!isAlive) return;
	//Turns the particle
	speed.rotate(0, 0, param->rotate* elapsedTime);

	ofVec3f acceleration;
	ofVec3f distance = position - param->startingPoint;
	//Checks if particle is inside the circle range
	if (ofInRange(distance.length(), 0, ofGetHeight())) {
		distance.normalize(); //Max 1 long, or else the particle would shoot really far away
		acceleration += distance * param->force;
		acceleration.x = -distance.y *param->spinning;
		acceleration.y = distance.x *param->spinning;
	}

	// Fade out effect
	speed += acceleration * elapsedTime;
	speed *= (1 - param->friction); //Bigger the friction, slower the speed

	position += speed* elapsedTime; // The position changes with by the time the app is started
	age += elapsedTime;
	if (age >= maxAge) isAlive = false;
}

void Particle::draw() {

	//Draw gas image with alpha that changes it's bightness overtime
	if (!isAlive) return;
	ofEnableAlphaBlending();
	if (timealpha > 0.08) {
		alpha = 20;
	}
	else if (timealpha > 0.6 && timealpha < 0.8) {
		alpha = 255;
	}
	else if (timealpha < .06) {
		alpha -= 10;
	}
	ofSetColor(ofColor::white, alpha);
	image.draw(position.x, position.y, 403,308);
	ofDisableAlphaBlending();

	/*basic particle
	ofColor color = ofColor::red;
	float hue = ofMap(age, 0, maxAge, hue_min, hue_max);
	color.setHue(hue);
	ofSetColor(color);
	float size = ofMap(maxAge - age, 0, maxAge, 3, 1);
	ofDrawCircle(position, size);
	*/

}

ofPoint Particle::randomPointOnCircle(float maxRadius) {
	//Normal distribution for the particle, so that the particle goes to a random place
	//in a certain angle, but not too random


	ofPoint point;
	float radius = ofRandom(0, maxRadius);
	float angle;
	//angle = ofRandom(0, M_TWO_PI);
	//angle = ofRandom(1.5*1.57, 2.5*1.57);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //Time changes everytime
	std::default_random_engine generator(seed); // Send the time to the generator
	std::normal_distribution<float> distribution(PI, 0.2); //Calculate the normal distribution with the mean and standard deviation
	//send the calculated distribution as a angle to the position of the particle
	angle = distribution(generator);
	point.x = cos(angle) * radius;
	point.y = sin(angle) * radius;

	return point;
}