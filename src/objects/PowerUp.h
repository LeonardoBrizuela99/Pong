#pragma once
#include "raylib.h"
#include "../objects/Ball.h"

struct PowerUp
{ 
	float x;
	float y;
	float width;
	float height;
	bool active;
};

void CalculateRandomPos(PowerUp& poweUp);
PowerUp CreatePowerUp();
Rectangle GetRecPowerUp(PowerUp& powerUp);
void DrawPowerUp(PowerUp& powerUp);