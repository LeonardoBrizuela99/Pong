#include"raylib.h"
#include"../objects/Ball.h"
#include"PowerUp.h"
#include<iostream>
#include<ctime>

using namespace std;

void CalculateRandomPos(PowerUp& poweUp)
{
	int randomPos = GetRandomValue(10, 100);
	int direction = GetRandomValue(0, 1);

	poweUp.x = direction == 0 ? randomPos : randomPos;

	randomPos = GetRandomValue(10, 100);
	direction = GetRandomValue(0, 1);

	poweUp.y = direction == 0 ? randomPos : randomPos;
	cout << "powerUPX: "<<poweUp.x<< " powerUpY: " << poweUp.y << endl;
}

PowerUp CreatePowerUp()
{
	PowerUp powerUp;

	CalculateRandomPos(powerUp);

	/*powerUp.x = GetScreenHeight() / 2;
	powerUp.y = GetScreenHeight() / 2;*/
	powerUp.height = 55;
	powerUp.width = 55;
	return powerUp;
}

Rectangle GetRecPowerUp(PowerUp& powerUp)
{
	return Rectangle{ powerUp.x ,powerUp.y, powerUp.width,powerUp.height };
}

void DrawPowerUp(PowerUp& powerUp)
{
	DrawRectangleRec(GetRecPowerUp(powerUp), BLUE);
}

//void SpawnPowerUp(PowerUp& powerUp, Paddle& leftPaddle, Paddle& rightPaddle) {
//	int minDistanceFromPaddle = 100; // Distancia m�nima desde la paleta
//
//	do {
//		powerUp.x = GetRandomValue(minDistanceFromPaddle, GetScreenWidth() - minDistanceFromPaddle);
//		powerUp.y = GetRandomValue(0, GetScreenHeight());
//		powerUp.width = 20; // Ancho del power-up
//		powerUp.height = 20; // Alto del power-up
//
//		// Verificar que la posici�n est� lo suficientemente lejos de las paletas
//	} while (CheckCollisionRecs(Rectangle{ powerUp.x, powerUp.y, powerUp.width, powerUp.height }, GetPaddleRect(leftPaddle)) ||
//		CheckCollisionRecs(Rectangle{ powerUp.x, powerUp.y, powerUp.width, powerUp.height }, GetPaddleRect(rightPaddle)));
//
//	powerUp.active = true; // Activar el power-up
//
//	 //if (powerUp.active && CheckCollisionRecs(Rectangle{ ballPosition.x - ballRadius, ballPosition.y - ballRadius, ballRadius * 2, ballRadius * 2 },
//		//Rectangle{ powerUp.x, powerUp.y, powerUp.width, powerUp.height })) {
//		//	// Colisi�n con el power-up
//		//	ballRadius += 5.0f; // Aumentar el tama�o de la pelota
//		//	powerUp.active = false; // Desactivar el power-up
//		//	}
//}

