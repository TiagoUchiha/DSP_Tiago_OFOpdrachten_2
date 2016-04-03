#pragma once

#include "ofMain.h"
#include "Parameters.h"

class Particle {
public:
	Particle(Parameters* parameters);
	static ofImage image;

	void setup(float newHue_MIN, float newHue_MAX, float elapsedTime);
	void update(float elapsedTime);
	void draw();

	ofPoint randomPointOnCircle(float maxRadius);

	ofPoint position;
	ofVec3f speed;
	bool isAlive;
	int alpha;
	float age;
	float maxAge;

	float hue_min, hue_max, timealpha;

	Parameters* param;

};
