#pragma once
#include "sl.h"
#include "Struct.h"

Vector2 getMousePosition();
void drawRectangle(Rectangle rectangle, Color color);
bool checkRecMouseCollision(Rectangle rec, Vector2 mouse);
void setColor(Color color);