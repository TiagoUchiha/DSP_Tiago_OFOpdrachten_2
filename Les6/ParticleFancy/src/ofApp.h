#pragma once

#include "ofMain.h"
#include "Parameters.h"
#include "Particle.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	Parameters parameters;
	float time;
	ofFbo fbo;
	vector<Particle> particles;
};
