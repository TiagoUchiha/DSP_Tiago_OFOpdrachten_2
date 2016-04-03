#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//loader.loadModel("dragon.dae");
	//loader.loadModel("dwarf.x");
	//loader.playAllAnimations();
	//loader.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
	loader.loadModel("lee.dae");
	mesh = loader.getMesh(0);
	origVertices = mesh.getVertices();		// wij willen de originele mesh behouden dus geen pointer
	for (int y = 0; y<height - 1; y++) {
		for (int x = 0; x<width - 1; x++) {
			mesh.addIndex(x + y*width);               // 0
			mesh.addIndex((x + 1) + y*width);           // 1
			mesh.addIndex(x + (y + 1)*width);           // 10

			mesh.addIndex((x + 1) + y*width);           // 1
			mesh.addIndex((x + 1) + (y + 1)*width);       // 11
			mesh.addIndex(x + (y + 1)*width);           // 10
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	//loader.update();

	vector<ofPoint> vertices = mesh.getVertices();
	for (int i = 0; i < origVertices.size(); i += 4) {
		ofPoint newVertex = origVertices[i] * ofMap(sin(ofGetElapsedTimef()), -1, 1, 0.9, 1.4);
		mesh.setVertex(i, newVertex);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor(64), ofColor::black);
	camera.setScale(1,-1,1);
	camera.begin();
	ofEnableDepthTest();			//rekening houden met de diepte, waardoor je geen halve mesh krijgt
	ofPushMatrix();
	//loader.drawWireframe();
	//loader.drawFaces();
	ofMultMatrix(loader.getModelMatrix());
	mesh.drawWireframe();
	ofPopMatrix();
	ofDisableDepthTest();
	camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}