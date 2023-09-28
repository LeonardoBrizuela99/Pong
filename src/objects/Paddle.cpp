#include "sl.h"
#include "Paddle.h"
#include "Game.h"

Paddle CreatePaddle(float positionX, SL_Color color, SL_Color hitColor)
{
    Paddle paddle;
    paddle.x = positionX;
    paddle.y = slGetScreenHeight() / 2;
    paddle.width = 10;
    paddle.height = 100;
    paddle.speed = 500;
    paddle.lastHitTime = paddle.hitDuration;
    paddle.color = color;
    paddle.hitColor = hitColor;

    return paddle;
}

SL_Rectangle GetPaddleRect(Paddle paddle)
{
    return SL_Rectangle{ paddle.x - paddle.width / ((float)2), paddle.y - paddle.height / ((float)2), 10, 100 };
}

void MovePaddles(Paddle& leftPaddle, Paddle& rightPaddle)
{
    if (slGetKey('W') && leftPaddle.y > 50)
    {
        leftPaddle.y -= leftPaddle.speed * slGetDeltaTime();
    }
    if (slGetKey('S') && leftPaddle.y < slGetScreenHeight() - 50)
    {
        leftPaddle.y += leftPaddle.speed * slGetDeltaTime();
    }

    if (slGetKey(SL_KEY_UP) && rightPaddle.y > 50)
    {
        rightPaddle.y -= rightPaddle.speed * slGetDeltaTime();
    }
    if (slGetKey(SL_KEY_DOWN) && rightPaddle.y < slGetScreenHeight() - 50)
    {
        rightPaddle.y += rightPaddle.speed * slGetDeltaTime();
    }
}

void UpdatePaddle(Paddle& leftPaddle, Paddle& rightPaddle)
{
    MovePaddles(leftPaddle, rightPaddle);
    leftPaddle.lastHitTime += slGetDeltaTime();
    rightPaddle.lastHitTime += slGetDeltaTime();
}

void CheckInputs(Paddle& leftPaddle, Paddle& rightPaddle)
{
}

void DrawPaddle(Paddle paddle)
{
    slRectangleFill(GetPaddleRect(paddle).x, GetPaddleRect(paddle).y, GetPaddleRect(paddle).width, GetPaddleRect(paddle).height, SL_BLACK);

    if (paddle.lastHitTime < paddle.hitDuration)
    {
        slRectangleRoundedOutline(GetPaddleRect(paddle).x, GetPaddleRect(paddle).y, GetPaddleRect(paddle).width, GetPaddleRect(paddle).height, 3.0f, 4, 3.0f, SL_COLOR(paddle.hitColor, 0.4f));
    }
    else
    {
        slRectangleRoundedOutline(GetPaddleRect(paddle).x, GetPaddleRect(paddle).y, GetPaddleRect(paddle).width, GetPaddleRect(paddle).height, 3.0f, 4, 3.0f, SL_COLOR(paddle.color, 1.0f));
    }
}

//#include"raylib.h"
//#include"Paddle.h"
//#include"iostream"
//#include "../Game.h"
//
//using namespace std;
//
//Paddle CreatePaddle(float positionX, Color color, Color hitColor)
//{
//	Paddle paddle;
//	paddle.x = positionX;
//	paddle.y = GetScreenHeight() / 2;
//	paddle.width = 10;
//	paddle.height = 100;
//	paddle.speed = 500;
//	paddle.lastHitTime = paddle.hitDuration;
//	paddle.color = color;
//	paddle.hitColor = hitColor;
//
//	return paddle;
//}
//
//Rectangle GetPaddleRect(Paddle paddle)
//{
//	return Rectangle{ paddle.x - paddle.width / ((float)2), paddle.y - paddle.height / ((float)2), 10, 100 };
//}
//
//void MovePaddles(Paddle &leftPaddle, Paddle &rightPaddle)
//{
//	if (IsKeyDown(KEY_W) && leftPaddle.y > 50)
//	{
//		leftPaddle.y -= leftPaddle.speed * GetFrameTime();
//	}
//	if (IsKeyDown(KEY_S) && leftPaddle.y < GetScreenHeight() - 50 )
//	{
//		leftPaddle.y += leftPaddle.speed * GetFrameTime();
//	}
//
//	if (IsKeyDown(KEY_UP) && rightPaddle.y > 50 )
//	{
//		rightPaddle.y -= rightPaddle.speed * GetFrameTime();
//	}
//	if (IsKeyDown(KEY_DOWN) && rightPaddle.y < GetScreenHeight() - 50 )
//	{
//		rightPaddle.y += rightPaddle.speed * GetFrameTime();
//	}
//	
//}
//
//void UpdatePaddle(Paddle &leftPaddle, Paddle &rightPaddle)
//{
//	MovePaddles(leftPaddle, rightPaddle);
//	leftPaddle.lastHitTime += GetFrameTime();
//	rightPaddle.lastHitTime += GetFrameTime();
//
//}
//
//void CheckInputs(Paddle& leftPaddle, Paddle& rightPaddle)
//{
//}
//
//void DrawPaddle(Paddle paddle)
//{
//	DrawRectangleRec(GetPaddleRect(paddle), BLACK);
//
//	if (paddle.lastHitTime<paddle.hitDuration)
//	{
//		DrawRectangleRoundedLines(GetPaddleRect(paddle), 3.0f, 4, 3.0f, Fade(paddle.hitColor, 0.4f));
//	}
//	else
//	{
//		DrawRectangleRoundedLines(GetPaddleRect(paddle), 3.0f, 4, 3.0f, Fade(paddle.color, 1.0f));
//	}
//}
