#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::cloudCollision(Player *m_Player, Levels *m_Levels, int &m_currLvl, Music* m_Music)
{
	for (int i = 0; i < totalAsteroids; i++) {
		if (circleCollision(m_Player->m_rDst.x, m_Levels->Asteroids[m_currLvl][i].m_rDst.x, m_Player->m_rDst.y, m_Levels->Asteroids[m_currLvl][i].m_rDst.y, m_Player->m_iRad, m_Levels->Asteroids[m_currLvl][i].m_iRad)) {
			//m_Player->m_rDst.x = 0;
			m_Player->m_rDst.x = m_Player->getSavedX();
			m_Player->m_rDst.y = m_Player->getSavedY();
			m_Music->hurtSound();
		}
	}
}



bool Collision::hazardCollision(Player *m_Player, Levels *m_Levels, int &m_currLvl, Music *m_Music, Timer *m_Timer)
{
	for (int i = 0; i < totalHazards; i++)
	{

		if (m_Levels->hazards[m_currLvl][i].alive == true)
		{

			m_Levels->hazards[m_currLvl][i].animation();

			if (circleCollision(m_Player->m_rDst.x, m_Levels->hazards[m_currLvl][i].m_rDst.x, m_Player->m_rDst.y, m_Levels->hazards[m_currLvl][i].m_rDst.y, m_Player->m_iRad, m_Levels->hazards[m_currLvl][i].m_iRad))
			{

				m_Levels->hazards[m_currLvl][i].alive = false;
				m_Music->hit();
				m_Player->setLife();

				if (m_Player->returnLife() == 0)
				{
					m_Timer->stop();
					return true;

				}
				m_Player->m_rDst.x = m_Player->getSavedX();
				m_Player->m_rDst.y = m_Player->getSavedY();
			}
		}
	}
	return false;
}

bool Collision::circleCollision(double x1, double x2, double y1, double y2, double r1, double r2)
{
	return (sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)) < r1 + r2);
}
