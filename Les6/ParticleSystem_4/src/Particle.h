#pragma once

#include "ofMain.h"
#include "Parameters.h"

class Particle {
 public:
  Particle(Parameters* parameters);

  void setup(float newHue_MIN, float newHue_MAX);
  void update(float elapsedTime);
  void draw();
 // void updateSpeed(float speedXS, float speedYS);

  ofPoint randomPointOnCircle(float maxRadius);

  ofPoint position;
  ofVec3f speed;
  bool isAlive;
  float age;
  float maxAge;
  float hue_min, hue_max;

  Parameters* param;

};
