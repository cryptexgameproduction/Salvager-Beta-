#pragma once

#include "Sprite.h"

class Asteroid: public Sprite
{

public:

	Asteroid();
	~Asteroid();
	void animation();

	Asteroid(int x, int y, int w, int h);

private:

};
