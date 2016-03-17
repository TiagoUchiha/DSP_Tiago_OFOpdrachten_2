#include "MyCircle.h"

MyCircle::MyCircle() {
	setup();
	image.load("bulb.png");
	image2.load("char.png");
	image3.load("squirtle.png");
}

void MyCircle::setup() {
	color.r = ofRandom(20, 100);
	color.g = ofRandom(60, 150);
	color.b = ofRandom(200, 255);
}

void MyCircle::draw() {
	float radius = getRadius();
	ofPoint position = getPosition();
	image.draw(position.x, position.y, 100, 100);
	/*
	ofFill();
	ofSetColor(color);
	ofDrawCircle(position.x, position.y, radius);

	ofSetColor(color,100);
	ofDrawCircle(position.x, position.y, radius*1.1);
	*/
}