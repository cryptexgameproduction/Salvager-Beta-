#include "Levels.h"

Levels::Levels()
{
	//Enemy Ships
	for (int i = 0; i < 30; i++)
	{

		int v1 = rand() % 900;
		int v2 = rand() % 760 - 760;
		int v3 = rand() % 2500;
		hazards[0][i] = Hazard(v1, v2, v3);
		hazards[1][i] = Hazard(v1, v2, v3);
		hazards[2][i] = Hazard(v1, v2, v3);
		hazards[3][i] = Hazard(v1, v2, v3);
		//hazards[4][i] = Hazard(v1, v2, v3);
	}


	//Asteroids for first level

	Asteroids[0][0] = Asteroid(450, 200, 70, 70);
	Asteroids[0][1] = Asteroid(400, 300, 50, 50);
	Asteroids[0][2] = Asteroid(450, 500, 70, 70);
	Asteroids[0][3] = Asteroid(400, 600, 50, 50);
	
	//Asteroids for second level

	Asteroids[1][0] = Asteroid(450, 0, 70, 70);
	Asteroids[1][1] = Asteroid(400, 150, 50, 50);
	Asteroids[1][2] = Asteroid(450, 250, 70, 70);
	Asteroids[1][3] = Asteroid(400, 350, 50, 50);
	Asteroids[1][4] = Asteroid(850, 0, 70, 70);
	Asteroids[1][5] = Asteroid(400, 550, 50, 50);
	Asteroids[1][6] = Asteroid(450, 600, 70, 70);
	Asteroids[1][7] = Asteroid(300, 500, 70, 70);
	Asteroids[1][8] = Asteroid(550, 100, 60, 60);
	Asteroids[1][9] = Asteroid(600, 200, 70, 70);
	Asteroids[1][10] = Asteroid(100, 550, 60, 60);
	Asteroids[1][11] = Asteroid(200, 450, 70, 70);
	Asteroids[1][12] = Asteroid(80, 400, 80, 80);
	Asteroids[1][13] = Asteroid(200, 350, 50, 50);
	Asteroids[1][14] = Asteroid(100, 250, 60, 60);
	Asteroids[1][15] = Asteroid(200, 150, 100, 100);
	Asteroids[1][16] = Asteroid(0, 0, 100, 100);


	Asteroids[1][17] = Asteroid(650, 550, 70, 70);
	Asteroids[1][18] = Asteroid(600, 450, 50, 50);
	Asteroids[1][19] = Asteroid(700, 300, 100, 100);
	Asteroids[1][20] = Asteroid(750, 200, 60, 60);
	Asteroids[1][21] = Asteroid(850, 400, 60, 60);
	Asteroids[1][22] = Asteroid(850, 300, 60, 60);
	Asteroids[1][23] = Asteroid(550, 550, 60, 60);
	Asteroids[1][24] = Asteroid(850, 600, 100, 100);
	Asteroids[1][25] = Asteroid(800, 500, 70, 70);

	//Asteroids for third level

	Asteroids[2][0] = Asteroid(0, 100, 70, 70);
	Asteroids[2][1] = Asteroid(100, 100, 70, 70);
	Asteroids[2][2] = Asteroid(200, 100, 50, 50);
	Asteroids[2][3] = Asteroid(300, 100, 60, 60);
	Asteroids[2][4] = Asteroid(850, 0, 70, 70);
	Asteroids[2][5] = Asteroid(900, 100, 80, 80);
	Asteroids[2][6] = Asteroid(800, 500, 90, 90);
	Asteroids[2][7] = Asteroid(900, 400, 60, 60);
	Asteroids[2][8] = Asteroid(500, 200, 100, 100);
	Asteroids[2][9] = Asteroid(300, 600, 50, 50);
	Asteroids[2][10] = Asteroid(700, 700, 60, 60);
	Asteroids[2][11] = Asteroid(400, 400, 80, 80);	  
	Asteroids[2][12] = Asteroid(700, 600, 60, 60);
	Asteroids[2][13] = Asteroid(500, 200, 100, 100);
	Asteroids[2][14] = Asteroid(300, 0, 100, 100);
	Asteroids[2][15] = Asteroid(400, 0, 60, 60);
	Asteroids[2][16] = Asteroid(300, 200, 80, 80);

	Asteroids[2][17] = Asteroid(300, 400, 50, 50);
	Asteroids[2][18] = Asteroid(800, 0, 100, 100);
	Asteroids[2][19] = Asteroid(700, 50, 80, 80);
	Asteroids[2][20] = Asteroid(500, 100, 100, 100);
	Asteroids[2][21] = Asteroid(600, 100, 100, 100);
	Asteroids[2][22] = Asteroid(700, 100, 100, 100);
	Asteroids[2][23] = Asteroid(800, 100, 100, 100);
	Asteroids[2][24] = Asteroid(900, 100, 100, 100);
	Asteroids[2][25] = Asteroid(0, 450, 100, 100);
	Asteroids[2][26] = Asteroid(100, 450, 100, 100);
	Asteroids[2][27] = Asteroid(200, 450, 100, 100);
	Asteroids[2][28] = Asteroid(300, 450, 100, 100);
	Asteroids[2][29] = Asteroid(400, 500, 80, 80);
	Asteroids[2][30] = Asteroid(650, 500, 70, 70);
	Asteroids[2][31] = Asteroid(450, 80, 80, 80);
	Asteroids[2][32] = Asteroid(450, 300, 50, 50);


	
	//Asteroids for fourth level


	Asteroids[3][0] = Asteroid(0, 100, 100, 100);
	Asteroids[3][1] = Asteroid(100, 165, 100, 100);
	Asteroids[3][2] = Asteroid(200, 220, 100, 100);
	Asteroids[3][3] = Asteroid(300, 0, 100, 100);
	Asteroids[3][4] = Asteroid(400, 0, 100, 100);
	Asteroids[3][5] = Asteroid(500, 190, 100, 100);
	Asteroids[3][6] = Asteroid(600, 100, 100, 100);
	Asteroids[3][7] = Asteroid(700, 490, 100, 100); 
	Asteroids[3][8] = Asteroid(800, 490, 100, 100); 
	Asteroids[3][9] = Asteroid(900, 100, 100, 100);
			  
	Asteroids[3][10] = Asteroid(0, 450, 100, 50);
	Asteroids[3][11] = Asteroid(100, 650, 100, 100);
	Asteroids[3][12] = Asteroid(200, 375, 100, 100);
	Asteroids[3][13] = Asteroid(300, 600, 100, 100);
	Asteroids[3][14] = Asteroid(400, 525, 100, 100);
	Asteroids[3][15] = Asteroid(500, 450, 100, 100);
	Asteroids[3][16] = Asteroid(600, 300, 100, 100);
	Asteroids[3][17] = Asteroid(700, 450, 100, 100);
	Asteroids[3][18] = Asteroid(800, 450, 100, 100);
	Asteroids[3][19] = Asteroid(900, 450, 100, 100);



	//hazards[4][0] = Hazard(100, 10, 600);
	//hazards[4][1] = Hazard(300, 0, 560);
	//hazards[4][2] = Hazard(400, 0, 500);
	//hazards[4][3] = Hazard(600, 0, 700);
	//hazards[4][4] = Hazard(800, 0, 650);

	/*Asteroids[4][0] = Asteroid(120, 400, 100, 100);
	Asteroids[4][1] = Asteroid(100, 165, 100, 100);
	Asteroids[4][2] = Asteroid(200, 165, 100, 100);
	Asteroids[4][3] = Asteroid(300, 0, 100, 65);
	Asteroids[4][4] = Asteroid(400, 0, 100, 65);
	Asteroids[4][5] = Asteroid(500, 190, 100, 100);
	Asteroids[4][6] = Asteroid(500, 100, 100, 100);
	Asteroids[4][7] = Asteroid(900, 200, 100, 100);
	Asteroids[4][8] = Asteroid(900, 325, 100, 100);
	Asteroids[4][9] = Asteroid(900, 100, 100, 50);

	Asteroids[4][10] = Asteroid(0, 450, 100, 50);
	Asteroids[4][11] = Asteroid(100, 650, 100, 100);
	Asteroids[4][12] = Asteroid(200, 325, 100, 100);
	Asteroids[4][13] = Asteroid(350, 570, 100, 100);
	Asteroids[4][14] = Asteroid(400, 525, 100, 100);
	Asteroids[4][15] = Asteroid(500, 450, 100, 100);
	Asteroids[4][16] = Asteroid(500, 300, 100, 100);
	Asteroids[4][17] = Asteroid(900, 550, 100, 100);
	Asteroids[4][18] = Asteroid(900, 650, 100, 100);
	Asteroids[4][19] = Asteroid(900, 450, 100, 100);*/
}