#pragma once
#include "SDL_mixer.h"

class Music
{
public:
	Mix_Music* bgm;
	Mix_Chunk* hurt;
	Mix_Chunk* mouseOver; Mix_Chunk* mouseClick;
	bool IsMusicOn = false;
	Music() {}
	~Music() {}

	void BaseMusic()
	{
		//SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // Initializes Mixer to use Music
		bgm = Mix_LoadMUS("Assets/Music/bmsc.mp3"); // Loads Music File
		Mix_PlayMusic(bgm, -1); // Loops the Music so it constantly plays
		Mix_VolumeMusic(10); // Volume for Music
	}

	void hurtSound()
	{
		hurt = Mix_LoadWAV("Assets/Music/porta.ogg");
		Mix_PlayChannel(1, hurt, 0);
		Mix_VolumeChunk(hurt, 10);
	}
	void hit()
	{
		hurt = Mix_LoadWAV("Assets/Music/hit.wav");
		Mix_PlayChannel(1, hurt, 0);
		Mix_VolumeChunk(hurt, 10);
	}
	void MouseOver()
	{
		mouseOver = Mix_LoadWAV("Assets/Music/MouseOver.wav");
		Mix_PlayChannel(1, mouseOver, 0);
		Mix_VolumeChunk(mouseOver, 10);
	}
	void MouseSelect()
	{
		mouseClick = Mix_LoadWAV("Assets/Music/MouseSelect.wav");
		Mix_PlayChannel(2, mouseClick, 0);
		Mix_VolumeChunk(mouseClick, 10);
	}

	void MuteMusic()
	{
		if (IsMusicOn == false)
		{
			Mix_VolumeMusic(0);
			IsMusicOn = true;
		}
		else if (IsMusicOn)
		{
			Mix_VolumeMusic(10);
			IsMusicOn = false;
		}
	}

	void ExitMusic()
	{
		bgm = nullptr;
		Mix_Quit(); // Stops Music as game is closed
	}
};