#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		ofxAssimpModelLoader loader;
		ofEasyCam camera;
		
		ofMesh mesh;
		vector<ofPoint> origVertices;
};
