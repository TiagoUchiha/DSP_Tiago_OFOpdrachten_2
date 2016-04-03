#include "MyCircles.h"

MyCircles::MyCircles() {
	setup();
	image.load("bulb.png");
	image2.load("char.png");
	image3.load("squirtle.png");
}

void MyCircles::setup() {
	//color.r = ofRandom(20, 100);
	//color.g = ofRandom(60, 150);
	//color.b = ofRandom(200, 255);

	speedX = ofRandom(-3, 3);
	speedY = ofRandom(-3, 3);
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());
}

void MyCircles::update() {
	// links/ rechts tegen de rand aan? keer om!
	if (x < 0) {
		x = 0;
		speedX = -speedX;
	}
	else if (x > (ofGetWidth() -100)) {
		x = ofGetWidth() -100;
		speedX = -speedX;
	}

	// boven/onder tegen de rand aan? keer om!
	if (y < 0) {
		y = 0;
		speedY = -speedY;
	}
	else if (y > (ofGetHeight() -100)) {
		y = ofGetHeight() -100;
		speedY = -speedY;
	}
}

void MyCircles::draw() {
	float radius = getRadius();
	image.draw(x, y, 100, 100);
	
	
	
	/*
	ofFill();
	ofSetColor(color);
	ofDrawCircle(position.x, position.y, radius);

	ofSetColor(color,100);
	ofDrawCircle(position.x, position.y, radius*1.1);
	*/
}