//#include"raylib.h"
//#include"Ball.h"
//#include"Paddle.h"
//#include<iostream>
//#include<ctime>
//
//using namespace std;
//
//void MoveBall(Ball& ball);
//void DrawBall(Ball& ball);
//void CollisionBall(Ball& ball);
//void PaddleBallCollisionLeft(Ball& ball, Paddle& leftPaddle);
//void PaddleBallCollisionRight(Ball& ball, Paddle& rightPaddle);
//
//void CalculateRandom(Ball& ball)
//{
//	int randomSpeed = GetRandomValue(100, 200);
//	int direction = GetRandomValue(0, 1);
//
//	ball.speedX = direction == 0 ? -randomSpeed : randomSpeed;
//
//	randomSpeed = GetRandomValue(100, 200);
//	direction = GetRandomValue(0, 1);
//
//	ball.speedY = direction == 0 ? -randomSpeed : randomSpeed;
//
//}
//
//Ball CreateBall()
//{
//	Ball ball;
//
//	CalculateRandom(ball);
//
//	ball.x = GetScreenWidth() / 2;
//	ball.y = GetScreenHeight() / 2;
//	ball.width = 10;
//	ball.height = 10;
//	ball.win = false;
//	ball.maxSpeed = 1000.0f;
//
//	return ball;
//};
//
//Rectangle GetRectBall(Ball& ball)
//{
//	return Rectangle{ ball.x ,ball.y, ball.width,ball.height };
//}
//
//void DrawBall(Ball& ball)
//{
//	DrawRectangleRec(GetRectBall(ball), BLACK);
//	DrawRectangleRoundedLines(GetRectBall(ball), 15.0f, 10, 5.0f, Fade(BLACK, 1.0f));
//	
//}
//
//void UpdateBall(Ball& ball)
//{
//	MoveBall(ball);
//}
//
//void MoveBall(Ball& ball)
//{
//	ball.x += ball.speedX * GetFrameTime();
//	ball.y += ball.speedY * GetFrameTime();
//}
