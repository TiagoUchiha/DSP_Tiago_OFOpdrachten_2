#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	grabber.setup(1920, 1080, true);

	image.load("eyes.png");
	image2.load("Grrrr_Mouth.png");

	//haarFinder2.setup("haarcascade_frontalface_default.xml");
	haarFinder.setup("haarcascade_eyes.xml");
	haarFinder2.setup("haarcascade_mouth.xml");


}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();

	if (grabber.isFrameNew()) {
		haarFinder.findHaarObjects(grabber.getPixels(), 100, 100); //gezicht komt niet meer voor dan bij 100 : 100 pixels
		haarFinder2.findHaarObjects(grabber.getPixels(), 150, 50);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	grabber.draw(0,0);
	ofNoFill();
	for (int i = 0; i < haarFinder2.blobs.size(); i++) {
		ofRectangle blobBoundingRect2 = haarFinder2.blobs[i].boundingRect;
		if (drawBox) {
			ofDrawRectangle(blobBoundingRect2.x, blobBoundingRect2.y, blobBoundingRect2.width, blobBoundingRect2.height);
		}
		image2.draw(blobBoundingRect2.x, blobBoundingRect2.y, blobBoundingRect2.width, blobBoundingRect2.height);
	}
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