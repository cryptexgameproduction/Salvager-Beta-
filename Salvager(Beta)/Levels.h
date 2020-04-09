#pragma once

#include "Hazard.h"
#include "Asteroid.h"
#include "Timer.h"
#include "Font.h"

#define levels 5
#define totalHazards 30
#define totalAsteroids 50

class Levels {

public:

	Hazard hazards[levels][totalHazards];
	Asteroid Asteroids[levels][totalAsteroids];
	Levels();


private:

};