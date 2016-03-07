#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "Spring.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);

private:
	void addParticle(int x, int y);
	Particle* findParticle(int x, int y);
	vector<Particle*> particles;
	vector<Spring*> springs;
	Particle* firstParticle;
	bool addingSpring;

	ofFbo fbo;
	int fadeAmount = 20;

	bool drawParticle = true;
	bool drawSpring = true;
};
