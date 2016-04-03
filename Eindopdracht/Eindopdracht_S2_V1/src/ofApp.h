#pragma once

#include "ofMain.h"
#include "Parameters.h"
#include "Particle.h"
#include "ofxGui.h"
#include "ofxImageSequence.h"
#include "ofEvents.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		//Arduino
		ofArduino	arduino;
		bool	isArduinoInitialized;
		void setupArduino(const int & version);
		void digitalPinChanged(const int & pinNum);
		void analogPinChanged(const int & pinNum);
		float potValue;
		float changeSpeed;

		/*	GUI
			ofxPanel gui;
			ofxIntSlider count;
			ofxFloatSlider maxAge_GUI;
			ofxFloatSlider start_GUI;
			ofxFloatSlider color_GUI_MIN;
			ofxFloatSlider color_GUI_MAX;
			ofxFloatSlider max_Speed;
			ofxFloatSlider rotate_particle;
			ofxFloatSlider force_particle;
			ofxFloatSlider spinning_particle;
			ofxFloatSlider friction_particle;
			ofxFloatSlider speed_car;
		*/
		
		//Particles system & ofxImageSequence
		Parameters parameters;
		float time;
		ofFbo fbo;
		vector<Particle> particles;
		int tempcount,imgWidth,imgHeight;
		float newHueMin, newHueMax, speed_frame;
		float birthRate = 500;
		ofImage image2,image3;
		ofPoint imgPos,imgPos2;
		ofxImageSequence sequence;
		bool playing;

};
