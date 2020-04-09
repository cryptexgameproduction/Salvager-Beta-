#include "Images.h"

MainMenu::MainMenu()
{


	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 796;
	m_rSrc.h = 597;

	m_rDst.x = 574 / 2;
	m_rDst.y = 386 / 2;
	m_rDst.w = 450;
	m_rDst.h = 382;

}

Paused::Paused()
{

	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 796;
	m_rSrc.h = 597;

	m_rDst.x = 781;
	m_rDst.y = 25;
	m_rDst.w = 446 / 2;
	m_rDst.h = 165 / 2;
}

Win::Win()
{
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 815;
	m_rSrc.h = 611;

	m_rDst.x = 564 / 2;
	m_rDst.y = 391 / 2;
	m_rDst.w = 460;
	m_rDst.h = 373;
}

Lose::Lose() 
{

	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 815;
	m_rSrc.h = 611;

	m_rDst.x = 564 / 2;
	m_rDst.y = 391 / 2;
	m_rDst.w = 460;
	m_rDst.h = 373;
}

GroupLogo::GroupLogo()
{
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 850;
	m_rSrc.h = 500;

	m_rDst.x = 750;
	m_rDst.y = 620;
	m_rDst.w = 300;
	m_rDst.h = 150;
}
