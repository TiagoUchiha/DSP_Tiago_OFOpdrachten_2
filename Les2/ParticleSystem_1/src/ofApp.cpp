#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	//ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < springs.size(); i++) {
		springs[i]->update();
	}
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 0) + "FPS");
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->draw();
	}
	for (int i = 0; i < springs.size(); i++) {
		springs[i]->draw();
	}

	if (addingSpring) {
		ofSetColor(ofColor::white);
		ofDrawLine(firstParticle->position, ofPoint(mouseX, mouseY));
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	Particle* insideParticle = findParticle(x, y);
	if (insideParticle != NULL) {
		if (addingSpring) {
			Particle* secondParticle = insideParticle;
			Spring* spring = new Spring(firstParticle, secondParticle);
			springs.push_back(spring);
			addingSpring = false;
		}
		else {
			firstParticle = insideParticle;
			addingSpring = true;
		}
	}
	else {
		addParticle(x, y);
	}
}

void ofApp::addParticle(int x, int y) {
	Particle* particle = new Particle(x, y);
	particles.push_back(particle);
}


Particle* ofApp::findParticle(int x, int y) {
	for (int i = 0; i < particles.size(); i++) {
		Particle* particle = particles[i];
		if (particle->position.distance(ofPoint(x, y)) < particle->radius) {
			return particle;
		}
	}
	return NULL;
}