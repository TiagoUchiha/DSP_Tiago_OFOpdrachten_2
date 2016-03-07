#include "ofApp.h"
#include "Ball.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(30, 30, 30);
	drawGrid = false;
	drawLight = false;

	ball.setup();
	ball2.setup();

	light.setPointLight();
	light.setPosition(200, 200, 20);
}

//--------------------------------------------------------------
void ofApp::update(){
	ball.update();
	ball2.update();

	// Collision!
	if (ball.position.distance(ball2.position)<ball.radius * 2) {
		ball.speed *= -1;
		//ball2.speed *=-1;
	}
	if (ball2.position.distance(ball.position)<ball2.radius * 2) {
		ball2.speed *= -1;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();
	cam.begin();
	light.enable();

	if (drawGrid) ofDrawGrid(200);
	if (drawBox) {
		ofNoFill();
		ofSetColor(ofColor::white); //voor RGB haal of color weg
		ofDrawBox(800, 800, 800);
		ofFill();
	}
	ball.draw();
	ball2.draw();

	light.disable();
	cam.end();
	ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'g') {
		drawGrid = !drawGrid;
	}
	else if (key == 'b') {
		drawBox = !drawBox;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
