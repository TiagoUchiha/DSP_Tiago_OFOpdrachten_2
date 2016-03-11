#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void mousePressed(int x, int y, int button);
	void keyPressed(int key);

	ofVideoGrabber grabber;

	ofxCvColorImage rgbImage;
	ofxCvColorImage hsbImage;
	ofxCvGrayscaleImage hue;
	ofxCvGrayscaleImage saturation;
	ofxCvGrayscaleImage brightness;
	ofxCvGrayscaleImage filtered, filtered2;
	ofxCvContourFinder contours;
	ofxCvContourFinder contours2;

	int findHue, findHue_2;
	bool firstHue, secondHue;
};
