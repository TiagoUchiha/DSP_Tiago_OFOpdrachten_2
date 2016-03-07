#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);

private:
	void addParticle(int x, int y);
	vector<Particle*> particles;
	Particle* firstParticle;

	ofFbo fbo;
	int fadeAmount = 20;

	bool drawParticle = true;
	bool drawSpring = true;
};
