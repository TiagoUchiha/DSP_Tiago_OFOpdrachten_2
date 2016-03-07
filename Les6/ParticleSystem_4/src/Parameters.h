#pragma once

#include "ofMain.h"

class Parameters {
 public:
  Parameters();

  ofPoint startingPoint;
  float radius = 60;
  float maxSpeed = 300;
  float lifeTime = 1.0;
  float rotate = 90;

  float force = 1000;
  float spinning = 1000;
  float friction = 0.05;
};
