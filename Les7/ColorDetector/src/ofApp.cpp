#include "ofApp.h"
#define GRABBER_WIDTH 320
#define GRABBER_HEIGHT 240

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(ofColor::black);
	grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT, true);

	rgbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	hsbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	hue.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	saturation.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	brightness.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	filtered.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);

}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	if (grabber.isFrameNew()) {
		rgbImage.setFromPixels(grabber.getPixels().getData(), GRABBER_WIDTH, GRABBER_HEIGHT);
		rgbImage.mirror(false, true);
		hsbImage = rgbImage;
		hsbImage.convertRgbToHsv();
		hsbImage.convertToGrayscalePlanarImages(hue, saturation, brightness);

		for (int i = 0; i < GRABBER_WIDTH*GRABBER_HEIGHT; i++) {
			// Als de hue van mijn plaatje tussen de -5 en +5 zit dan zet je in de filtered die kleur op wit
			if (ofInRange(hue.getPixels()[i], findHue - 5, findHue + 5)) {
				filtered.getPixels()[i] = 255;
			}
			else {
				filtered.getPixels()[i] = 0;
			}
		}
		filtered.flagImageChanged(); //vertel dat de plaatje is veranderd
		contours.findContours(filtered, 50, GRABBER_WIDTH*GRABBER_HEIGHT/2, 1, false);  // 1 = hoevel blobs = contouren
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::white);
	rgbImage.draw(640, 0);
	hsbImage.draw(0, 0);
	hue.draw(0, 240);
	saturation.draw(320,240);
	brightness.draw(640,240);
	filtered.draw(0, 480);
	contours.draw(640,0);
	ofSetColor(ofColor::blue, 100);
	ofFill();
	for (int i = 0; i < contours.nBlobs; i++) {
		//centroid = de middelste
		ofDrawCircle(contours.blobs[i].centroid.x+640, contours.blobs[i].centroid.y, 20);
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	findHue = hue.getPixels()[y*GRABBER_WIDTH + x];
	// maak een lijst van de plaatsen van de pixels en pak er een uit met de berekening y*widht + x
}
