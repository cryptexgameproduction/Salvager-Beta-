#pragma once

#include "Sprite.h"

class Hazard : public Sprite
{

public:

	bool up, down, alive;
	int downLimit;
	int upLimit;
	int resetX, resetY;
	Hazard();
	~Hazard();
	Hazard(int x, int y, int dL);

	void animation();
	void frameAnimation();
	void reset();

private:

	int speed;
	int frameCtr = 0;
	int frameMax = 4;
	int delayCtr = 0;
	int delayMax = 8;
};
