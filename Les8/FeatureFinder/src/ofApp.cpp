#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	grabber.setup(1920, 1080, true);

	image.load("eyes.png");

	//haarFinder.setup("haarcascade_frontalface_default.xml");
	haarFinder.setup("haarcascade_eyes.xml");


}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();

	if (grabber.isFrameNew()) {
		haarFinder.findHaarObjects(grabber.getPixels(), 100, 100); //gezicht komt niet meer voor dan bij 100 : 100 pixels

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	grabber.draw(0,0);
	ofNoFill();
	for (int i = 0; i < haarFinder.blobs.size(); i++) {
		//blob een plaats op de scherm die hij heeft gevonden
		ofRectangle blobBoundingRect = haarFinder.blobs[i].boundingRect;
		// binnen dit gedeelte van scherm heb ik de hoofden gevonden
		if (drawBox) {
			ofDrawRectangle(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
		}
		image.draw(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'b') {
		drawBox = !drawBox;
	}
}