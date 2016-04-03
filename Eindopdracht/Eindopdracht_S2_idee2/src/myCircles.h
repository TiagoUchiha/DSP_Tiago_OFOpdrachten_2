#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"

class MyCircles : public ofxBox2dCircle {
public:
	MyCircles();

	void setup();
	void draw();
	void update();

	ofColor color;
	ofImage image, image2, image3;
	int speedX, speedY, x, y;

};