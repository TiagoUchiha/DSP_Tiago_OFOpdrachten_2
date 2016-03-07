#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);

	ofSetBackgroundAuto(false);
	ofBackground(ofColor::black);
	ofEnableAlphaBlending(); //rekening houden met de alpha van dingen, aka transparantie

	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
	fbo.begin();
	ofClear(0, 0, 0, 0);
	fbo.end();
}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 0) + "FPS");

	fbo.begin();
	ofSetColor(0, 0, 0, fadeAmount);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->draw();
	}

	if (addingSpring) {
		ofSetColor(ofColor::white);
		ofDrawLine(firstParticle->position, ofPoint(mouseX, mouseY));
	}

	fbo.end();
	fbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
		addParticle(x, y);
}

void ofApp::addParticle(int x, int y) {
	Particle* particle = new Particle(x, y);
	particles.push_back(particle);
}