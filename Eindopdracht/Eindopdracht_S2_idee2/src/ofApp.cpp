#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(ofColor::black);
	box2d.init();
	box2d.setFPS(30);
	//box2d.createGround();
	//box2d.createBounds(0,0, ofGetWidth(), ofGetHeight());
	//box2d.setGravity(0, 0);
	//box2d.setGravity(0, -10);
	box2d.registerGrabbing();

}

//--------------------------------------------------------------
void ofApp::update() {
	box2d.update();
	for (int i = 0; i < circles.size(); i++) {
		circles[i]->update();

	}

	if (circles.size() < 1) {
		ofxBox2dCircle* circle = new MyCircles(); //in de classes zit er al heel veel kennis, dus daarom gebruik je de classes
		circle->setPhysics(3.0, 0.5, 0.1);
		circle->setup(box2d.getWorld(), 200, 100, ofRandom(20, 60));
		circle->addForce(ofVec2f(ofRandom(-10, 10), ofRandom(-20, 0)), 100);
		circles.push_back(circle);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < circles.size(); i++) {
		circles[i]->draw();

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ') {
	/*	ofxBox2dCircle* circle = new MyCircles(); //in de classes zit er al heel veel kennis, dus daarom gebruik je de classes
		circle->setPhysics(3.0, 0.5, 0.1);
		circle->setup(box2d.getWorld(), mouseX, mouseY, ofRandom(20, 60));
		circle->addForce(ofVec2f(ofRandom(-10, 10), ofRandom(-20, 0)), 100);
		circles.push_back(circle); */
	}
	else if (key == OF_KEY_RETURN) {
		box2d.setGravity(0, 0);
	}
	else if (key == OF_KEY_UP) {
		box2d.setGravity(0, -15);
	}
	else if (key == OF_KEY_DOWN) {
		box2d.setGravity(0, 15);
	}
}

//--------------------------------------------------------------

void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}
