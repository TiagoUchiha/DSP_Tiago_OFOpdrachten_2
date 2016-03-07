#pragma once

#include "Particle.h"

class Spring {
	public:
		Spring(Particle* first, Particle* second);
		void draw();
	
	private:
		Particle* first;
		Particle* second;
		int length;
};