#pragma once
#include"Struct.h"
void updatePadParts(Rectangle& rec)
{
	rec.rightEdge = rec.x + rec.width / 2;
	rec.leftEdge = rec.x - rec.width / 2;
	rec.upEdge = rec.y + rec.height / 2;
	rec.downEdge = rec.y - rec.height / 2;
}

Button createButton(float x, float y, int width, int height, std::string buttonTitle, Color color)
{
	Button button;
	button.isOver = false;
	button.rec = { x,y, width, height };
	button.buttonTittle = buttonTitle;
	button.color = color;
	return button;
}