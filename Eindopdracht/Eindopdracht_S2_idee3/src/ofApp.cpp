//https://opencvlibrary.svn.sourceforge.net/svnroot/opencvlibrary/tags/latest_tested_snapshot/opencv/data/haarcascades/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	grabber.setup(1920, 1080, true);
	image.load("eyes.png");
	image2.load("Grrrr_Mouth.png");
	image3.load("nose-clipart-for-kids-free-clipart-images.png");
	image4.load("rTLnbyrMc.png");



	//haarFinder2.setup("haarcascade_frontalface_default.xml");
	haarFinder.setup("haarcascade_eyes.xml");
	haarFinder2.setup("haarcascade_mouth.xml");
	haarFinder3.setup("Nariz.xml");
	haarFinder4.setup("haarcascade_frontalface_default.xml");


}

//--------------------------------------------------------------
void ofApp::update() {
	grabber.update();
	video = grabber.getPixels();
	video.mirror(false, true);

	if (grabber.isFrameNew()) {
		haarFinder.findHaarObjects(grabber.getPixels(), 100, 100); //gezicht komt niet meer voor dan bij 100 : 100 pixels
		haarFinder2.findHaarObjects(grabber.getPixels(), 150, 50);
		haarFinder3.findHaarObjects(grabber.getPixels(), 200, 200);
		haarFinder4.findHaarObjects(grabber.getPixels(), 300, 300);



	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	video.draw(0, 0);
	ofNoFill();

	for (int i = 0; i < haarFinder.blobs.size(); i++) {
		//blob een plaats op de scherm die hij heeft gevonden
		ofRectangle blobBoundingRect = haarFinder.blobs[i].boundingRect;
		// binnen dit gedeelte van scherm heb ik de hoofden gevonden
		if (drawBox) {
			ofDrawRectangle(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
		}
		image.draw(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
		image3.draw((blobBoundingRect.x + 20), (blobBoundingRect.y + 160), (blobBoundingRect.width + 20), (blobBoundingRect.height + 20));


		//Draw mouths, but check if it is beneath eyes
		for (int i = 0; i < haarFinder2.blobs.size(); i++) {
			ofRectangle blobBoundingRect2 = haarFinder2.blobs[i].boundingRect;
			if (blobBoundingRect2.y > (blobBoundingRect.y + 100) && blobBoundingRect2.y < (blobBoundingRect.y + 350)) {
				if (drawBox) {
					ofDrawRectangle(blobBoundingRect2.x, blobBoundingRect2.y, blobBoundingRect2.width, blobBoundingRect2.height);
				}
				image2.draw(blobBoundingRect2.x, blobBoundingRect2.y, blobBoundingRect2.width, blobBoundingRect2.height);
			}
		}
	}


		for (int i = 0; i < haarFinder4.blobs.size(); i++) {
			ofRectangle blobBoundingRect3 = haarFinder4.blobs[i].boundingRect;
				if (drawBox) {
					ofDrawRectangle(blobBoundingRect3.x, blobBoundingRect3.y, blobBoundingRect3.width, blobBoundingRect3.height);
				}
				image4.draw((blobBoundingRect3.x-150), (blobBoundingRect3.y-200), (blobBoundingRect3.width*1.5), (blobBoundingRect3.height*1.5));
		}


	/*	if (!drawBox) {
			image4.draw((blobBoundingRect.x-175), (blobBoundingRect.y - 200), 600, 579);
		}
	}*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'b') {
		drawBox = !drawBox;
	}
}