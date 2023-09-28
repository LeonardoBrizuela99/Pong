#pragma once
#pragma once
#include <string>

struct Vector2
{
	float x;
	float y;
};
struct Color
{
	double r;
	double g;
	double b;
	double a;
};
struct Rectangle
{
	float x;
	float y;
	int width;
	int height;
	int rightEdge;
	int leftEdge;
	int upEdge;
	int downEdge;
};
void updatePadParts(Rectangle& rec);

struct Button
{
	bool isOver;
	Rectangle rec;
	Color color;
	std::string buttonTittle;

};
Button createButton(float x, float y, int width, int height, std::string buttonTitle, Color color);

extern int screenSize;
const Color RED = { 1, 0, 0, 1 };
const Color BLUE = { 0, 0, 1, 1 };
const Color GREEN = { 0, 1, 0, 1 };
const Color LIGHTBLUE = { 0, 1, 1, 1 };
const Color PINK = { 1, 0, 1, 1 };
const Color ORANGE = { 1, 0.5, 0, 1 };
const Color YELLOW = { 1, 1,0 , 1 };
const Color VIOLET = { 0.5, 0,1 , 1 };
const Color WHITE = { 1, 1,1 , 1 };
const Color BLACK = { 0, 0,0 , 1 };