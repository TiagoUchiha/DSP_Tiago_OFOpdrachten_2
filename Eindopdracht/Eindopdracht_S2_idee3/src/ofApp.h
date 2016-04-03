#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);

	ofVideoGrabber grabber;
	ofxCvHaarFinder haarFinder, haarFinder2, haarFinder3,haarFinder4;

	ofImage image, image2,image3,image4,video;
	bool drawBox = true;

};
