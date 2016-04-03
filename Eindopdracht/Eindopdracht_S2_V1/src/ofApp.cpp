/*http://www.instructables.com/id/Ultrasonic-sensor-in-openFrameworks-using-Arduino/step3/OpenFrameworks-The-Final-Frontier/
 *http://www.cplusplus.com/reference/random/normal_distribution/normal_distirbution/
 *https://github.com/Flightphase/ofxImageSequence
*/
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
	fbo.begin();
	ofBackground(0);
	ofSetColor(255);
	fbo.end();
	time = ofGetElapsedTimef();

	//Addon ofxImageSequence setup
	Particle::image.load("Smoke_Transparent_Large_PNG_Image_v2.png");
	image2.load("background.png");
	image3.load("background.png");
	imgWidth = image2.getWidth() * 3;
	imgHeight = image2.getHeight() * 3;
	imgPos.x = (ofGetWidth() - imgWidth) / 2;
	imgPos.y = (ofGetHeight() - imgHeight) / 2;
	imgPos2.x = imgPos.x + imgWidth;
	imgPos2.y = imgPos.y;
	sequence.loadSequence("frame", "png", 1, 20, 2);
	sequence.preloadAllFrames();
	sequence.setFrameRate(60);
	playing = false;

	// Initialize Arduino
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	isArduinoInitialized = false;
	arduino.connect("COM4", 57600);
	arduino.sendFirmwareVersionRequest();


	/* GUI Configuration when necessary
		gui.setup("Settings", "settings.xml");
		gui.add(count.setup("Total particles", 1, 1, 40));
		gui.add(maxAge_GUI.setup("MaxAge", 1, 0.1, 6.0));
		gui.add(start_GUI.setup("StartPoint", 57.15, 57.15, 57.15));
		gui.add(color_GUI_MIN.setup("Color_HUE MIN", 1, 1, 360));
		gui.add(color_GUI_MAX.setup("Color_HUE MAX", 1, 1, 360));
		gui.add(max_Speed.setup("max_Speed", 300, 1, 1000));
		gui.add(rotate_particle.setup("rotate_particle", 45, 0, 360));
		gui.add(force_particle.setup("force_particle", 500, 1, 1000));
		gui.add(spinning_particle.setup("spinning_particle", 0, 0, 1000));
		gui.add(friction_particle.setup("friction_particle", 0.05, 0, 1));
		gui.add(speed_car.setup("speedCar", 60, 0, 100));
		gui.loadFromFile("setting.xml");
		tempcount = 0;
		newHueMin = 0;
		newHueMax = 0;
	*/
}

//--------------------------------------------------------------
void ofApp::update(){
	//Particle system update: Calculate tim eand Delete particles funtions
	float currentTime = ofGetElapsedTimef();
	float elapsedTime = ofClamp(currentTime - time, 0, 0.1); //clamp min max
	time = currentTime;
	int i = 0;
	while (i < particles.size()) {
		if (!particles[i].isAlive) {
			particles.erase(particles.begin() + i);
			//count = count - 1;
		}
		else {
			i++;
		}
	}
	//Particle system update: Add particles with time
	//	if (particles.size() < tempcount && tempcount != 0) {
	//	int newParticles = birthRate * elapsedTime;
	if (potValue != 0) {
		int newParticles = birthRate * elapsedTime;
		for (int i = 0; i < newParticles; i++) {
			Particle newParticle(&parameters);
			newParticle.setup(newHueMin, newHueMax, elapsedTime);
			particles.push_back(newParticle);
		}
	}

	//ofxImageSequence update over time, lets the car tires move and move background
	for (int i = 0; i < particles.size(); i++) {
		particles[i].update(elapsedTime);
	}
	sequence.setFrameRate(speed_frame);
	imgPos.x -= speed_frame;
	imgPos2.x -= speed_frame;

	//Update arduino
	arduino.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	//Draw background and calculate position
	ofBackground(ofColor::black);
	if (imgPos.x < -4500) {
		imgPos.x = 4500;
		imgPos2.x = 0;
	}
	else if (imgPos2.x < -4500) {
		imgPos2.x = 4500;
		imgPos.x = 0;
	}
	image2.draw(imgPos.x, imgPos.y, imgWidth, imgHeight);
	image3.draw(imgPos2.x, imgPos2.y, imgWidth, imgHeight);

	//Draw car and tires
	if (playing) {
		//get the frame based on the current time and draw it
		sequence.getFrameForTime(ofGetElapsedTimef())->draw(((ofGetWidth() / 2) - 80), ((ofGetHeight() / 2) + 20), 600, 273);
	}
	else {
		//get the sequence frame that maps to the mouseX position
		float percent = ofMap(mouseX, 0, ofGetWidth(), 0, 1.0, true);
		//draw it.
		sequence.getFrameAtPercent(percent)->draw(((ofGetWidth() / 2) - 80), ((ofGetHeight() / 2) + 20), 600, 273);
	}

	//Draw Particle system
	//gui.draw();
	fbo.begin();
	ofEnableAlphaBlending();
	ofSetColor(ofColor::black, 2);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofDisableAlphaBlending();
	ofFill();
	for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
	fbo.end();
	ofSetColor(ofColor::white);
	fbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//GUI for parameters
	if (key == ' ') {
		//tempcount = count;
		//parameters.lifeTime = maxAge_GUI;
		//parameters.radius = start_GUI;
		//parameters.maxSpeed = max_Speed;
		//parameters.rotate = rotate_particle;
		//speed_frame = speed_car;
		//parameters.force = force_particle;
		//parameters.spinning = spinning_particle;
		//parameters.friction = friction_particle;
		//newHueMin = color_GUI_MIN;
		//newHueMax = color_GUI_MAX;
	}

	//Button for car gif
	if (key == 'b') {
		playing = !playing;
	}
}
void ofApp::setupArduino(const int& version){
	// remove listener because we don't need it anymore
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
	// set flag: Arduino now ready for use
	isArduinoInitialized = true;

	//arduino.sendDigitalPinMode(7, ARD_OUTPUT);
	arduino.sendAnalogPinReporting(0, ARD_ANALOG);

	// set listeners for pin events
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

}
void ofApp::digitalPinChanged(const int& pinNum)
{
	// get value with arduino.getDigital(pinNum)
}

void ofApp::analogPinChanged(const int& pinNum){
	//Check potentialmeter's value and map it for the speed of the car & background and gas
	potValue = arduino.getAnalog(pinNum);
	changeSpeed = ofMap(potValue, 0, 1023, 0, 100);
	speed_frame = changeSpeed;
	parameters.maxSpeed = potValue;
	if (speed_frame != 0) {
		playing = true;
	}
	else {
		playing = false;
	}
	ofLog(OF_LOG_NOTICE, "potmeter works: " + ofToString(potValue));
}

