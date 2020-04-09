#pragma once

#include "Sprite.h"

class MainMenu : public Sprite
{

public:

	MainMenu();
private:
};

class Paused : public Sprite
{
public:
	Paused();
private:

};

class Win : public Sprite
{
public:
	Win();
private:
};

class Lose : public Sprite
{
public:
	Lose();
private:
};

class GroupLogo : public Sprite
{
public:
	GroupLogo();
private:
};