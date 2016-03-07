#pragma once

#include "ofMain.h"
#include "Parameters.h"
#include "Particle.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	ofxPanel gui;
	ofxIntSlider count;
	ofxFloatSlider maxAge_GUI;
	ofxFloatSlider start_GUI;
	ofxFloatSlider color_GUI_MIN;
	ofxFloatSlider color_GUI_MAX;
	ofxFloatSlider speedX;
	ofxFloatSlider speedY;

	void keyPressed(int key);

	Parameters parameters;
	float time;
	ofFbo fbo;
	vector<Particle> particles;
	int tempcount;
	float newHueMin, newHueMax;
	float birthRate = 1500;
};
