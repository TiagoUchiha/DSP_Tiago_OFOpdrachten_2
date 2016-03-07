#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
	fbo.begin();
	ofBackground(ofColor::black);
	fbo.end();
	//lalalalalllllllllllaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	time = ofGetElapsedTimef();

	gui.setup("Settings", "settings.xml");
	gui.add(count.setup("Total particles", 0, 0, 2000));
	gui.add(maxAge_GUI.setup("MaxAge", 1, 0.1, 2.0));
	gui.add(start_GUI.setup("StartPoint", 1, 1, 200));
	gui.add(color_GUI_MIN.setup("Color_HUE MIN", 1, 1, 360));
	gui.add(color_GUI_MAX.setup("Color_HUE MAX", 1, 1, 360));
	//gui.add(speedX.setup("SpeedX", 1, 1, 200));
	//gui.add(speedY.setup("SpeedY", 1, 1, 200));
	gui.loadFromFile("setting.xml");
	tempcount = 0;

}

void ofApp::update() {
	float currentTIme = ofGetElapsedTimef();
	float elapsedTime = ofClamp(currentTIme - time, 0, 0.1);
	time = currentTIme;
	int i = 0;
	while (i < particles.size()) {
		if (!particles[i].isAlive) {
			particles.erase(particles.begin() + i);
		//	count = count - 1;
		//	tempcount = tempcount - 1;
		}
		else {
			i++;
		}
	}

//	if (particles.size() < tempcount && tempcount != 0) {
//	int newParticles = birthRate * elapsedTime;
	int newParticles = count * elapsedTime;
	for (int i = 0; i < newParticles; i++){
		Particle newParticle(&parameters);
		newParticle.setup(newHueMin, newHueMax);
		particles.push_back(newParticle);
	}

	for (int i = 0; i < particles.size(); i++) {
		particles[i].update(elapsedTime);

	}
}

void ofApp::draw() {
	ofBackground(ofColor::black);
	gui.draw();
	fbo.begin();
	ofEnableAlphaBlending();
	ofSetColor(ofColor::black, 2);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofDisableAlphaBlending();
	ofFill();
	for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
	fbo.end();

	ofSetColor(ofColor::white);
	fbo.draw(0, 0);
}

void ofApp::keyPressed(int key) {
	if (key == ' ') {
		//tempcount = count;
		parameters.lifeTime = maxAge_GUI;
		parameters.radius = start_GUI;
		newHueMin = color_GUI_MIN;
		newHueMax = color_GUI_MAX;
	}

}