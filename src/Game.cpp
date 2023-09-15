//#include "Game.h"
//#include"menu/Menu.h"
//
//using namespace std;
//
//const float SCREEN_WIDTH = 800.0f;
//const float SCREEN_HEIGHT = 600.0f;
//const int maxPointsToWin = 5;
//
//Ball ball;
//Paddle leftPaddle, rightPaddle;
//
//bool exitWindow = false;
//bool endedMatch = false;
//bool keyPress = false;
//bool winnerPlayer = false;
//bool pause = false;
//int scoreRight = 0;
//int scoreLeft = 0;
//
//void RunGame()
//{
//	Init();
//	MainLoop();
//	Close();
//}
//
//void Init()
//{
//	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "PONG");
//	SetExitKey(KEY_NULL);
//	InitializeTexts();
//	ball = CreateBall();
//	rightPaddle = CreatePaddle(GetScreenWidth() - 50,RED, RED);
//	leftPaddle = CreatePaddle(50, BLUE, BLUE);
//}
//
//void MainLoop()
//{
//	while (!exitWindow)
//	{
//		while (!WindowShouldClose() && !salir)
//		{	
//			ScenesSwitch();
//			exitWindow = true;
//		}
//	}
//}
//
//void Reset()
//{
//	scoreRight = 0;
//	scoreLeft = 0;
//}
//
//void CheckInput()
//{
//	MovePaddles(leftPaddle, rightPaddle);
//}
//
//void Update()
//{
//	if (IsKeyPressed('P') || IsKeyPressed('p') || IsKeyPressed(KEY_ESCAPE))
//	{
//		pause = !pause;
//	}
//
//	if (!pause)
//	{
//		MovePaddles(leftPaddle, rightPaddle);
//		UpdateBall(ball);
//		UpdatePaddle(leftPaddle, rightPaddle);
//		CollisionBall(ball);
//		PaddleBallCollisionLeft(ball, leftPaddle);
//		PaddleBallCollisionRight(ball, rightPaddle);
//		GetScore(scoreRight, scoreLeft);
//		GetWinner(scoreRight, scoreLeft, winnerPlayer);
//	}
//}
//
//void Draw()
//{
//	BeginDrawing();
//	ClearBackground(Fade(BEIGE, 0.3f));
//	DrawRectangle(0, 0, 5, GetScreenHeight(), Fade(WHITE,1.0f));
//	DrawRectangle(GetScreenWidth() - 5, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));
//	
//	DrawField();
//	DrawBall(ball);
//	DrawPaddle(leftPaddle);
//	DrawPaddle(rightPaddle);
//	DrawScore(scoreRight, scoreLeft);
//
//	if (pause)
//	{
//		DrawRectangleGradientV(GetScreenWidth() / 2-400 , GetScreenHeight() / 2-300, 850, 600, BEIGE, Fade(RED,1.0f));
//		DrawText("Pause", GetScreenWidth() / 2 - 140, GetScreenHeight() / 2 - 250, 100, WHITE);
//		DrawText("Press (P) (ESC) to continue the game ", GetScreenWidth() / 2 - 360, GetScreenHeight() / 2, 38, WHITE);
//		DrawCredit();
//	}
//
//	if (endedMatch)
//	{
//		DrawRectangleGradientV(GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 300, 850, 600, BEIGE, Fade(RED, 1.0f));
//		DrawWinner(scoreRight, scoreLeft);
//		DrawText(TextFormat("Press Space to play again or Esc to Exit"), 50, 250, 35, WHITE);
//	}
//	EndDrawing();
//}
//
//void UpdateMenu()
//{
//	CheckSinglePlayer();
//	CheckInstructions();
//	CheckCredits();
//	CheckQuit();
//}
//
//void CreditsWindow()
//{
//	BeginDrawing();
//
//	DrawRectangleGradientV(GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 300, 850, 600, BEIGE, Fade(RED, 1.0f));
//	DrawText("Code by: Leonardo Brizuela", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 -10, 40, WHITE);
//	DrawText("(ESC) Back", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 + 200, 40, WHITE);
//	EndDrawing();
//
//	if (IsKeyPressed(KEY_ESCAPE))
//	{
//		menu = MenuScenes::MainMenu;
//	}
//}
//
//void WindowInstructions()
//{
//		BeginDrawing();
//
//		DrawRectangleGradientV(GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 300, 850, 600, BEIGE, Fade(RED, 1.0f));
//		DrawText("Use Up/Down to move rigth paddles", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 10, 40, WHITE);
//		DrawText("Use W/S to move left paddles", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 100, 40, WHITE);
//		DrawText("(ESC) Back", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 + 200, 40, WHITE);
//
//		EndDrawing();
//
//		if (IsKeyPressed(KEY_ESCAPE))
//		{
//			menu = MenuScenes::MainMenu;
//		}
//}
//
//void backMenu()
//{
//	if (IsKeyPressed(KEY_ESCAPE))
//	{
//		menu = MenuScenes::MainMenu;
//	}
//}
//
//void GetScore(int& scoreRight, int& scoreLeft)
//{
//	if (ball.x < 0)
//	{
//		scoreRight++;
//		initBall();
//	}
//
//	if (ball.x > GetScreenWidth())
//	{
//		scoreLeft++;
//		initBall();
//	}
//}
//
//void initBall()
//{
//	CalculateRandom(ball);
//
//	ball.x = GetScreenWidth() / 2;
//	ball.y = GetScreenHeight() / 2;
//}
//
//void GetWinner(int& scoreRight, int& scoreLeft, bool& winnerPlayer)
//{
//	if (scoreRight >= maxPointsToWin)
//	{
//		winnerPlayer = true;
//		endedMatch = true;
//	}
//	else if (scoreLeft >= maxPointsToWin)
//	{
//		winnerPlayer = true;
//		endedMatch = true;
//	}
//}
//
//void DrawWinner(int& scoreRight, int& scoreLeft)
//{
//	if (scoreRight >= maxPointsToWin)
//	{
//		DrawText(TextFormat("Right Player Win"), GetScreenWidth() / 2-125, GetScreenHeight() / 2, 35, RED);
//	}
//	else if (scoreLeft >= maxPointsToWin)
//	{
//		DrawText(TextFormat("Left Player Win"), GetScreenWidth()/2-125, GetScreenHeight()/2, 35, BLUE);
//	}
//}
//
//void DrawScore(int& scoreRight, int& scoreLeft)
//{
//	DrawText(TextFormat("  %02i", scoreRight), 620, 10, 40, RED);
//	DrawText(TextFormat("  %02i", scoreLeft), 70, 10, 40, BLUE);
//}
//
//void DrawCredit()
//{
//	DrawText(TextFormat("Credit: Leonardo Brizuela"), GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 + 100, 40, WHITE);
//}
//
//void GameLoop()
//{
//	if (endedMatch)
//	{
//		if (IsKeyPressed(KEY_SPACE))
//		{
//			endedMatch = false;
//			Reset();
//		}
//		if (IsKeyPressed(KEY_ESCAPE))
//		{
//			salir = true; 
//
//		}
//	}
//	else
//	{
//		CheckInput();
//		Update();
//	}
//	Draw();
//}
//
//void Close()
//{
//	CloseWindow();
//}
//
//void CollisionBall(Ball& ball)
//{
//	if (ball.y < 0)
//	{
//		if (ball.speedY < 0)
//		{
//			ball.y += ball.height;
//			ball.speedY *= -1;
//		}
//	}
//
//	if (ball.y > GetScreenHeight())
//	{
//		if (ball.speedY > 0)
//		{
//			ball.y -= ball.height;
//			ball.speedY *= -1;
//		}
//	}
//}
//
//void PaddleBallCollisionLeft(Ball& ball, Paddle& leftPaddle)
//{
//	if (CheckCollisionRecs(Rectangle{ GetRectBall(ball) }, Rectangle{ GetPaddleRect(leftPaddle) }))
//	{
//		if (ball.speedX < 0)
//		{
//			ball.x += ball.width;
//			ball.speedX *= -1.10f;
//			leftPaddle.lastHitTime = 0;
//
//			if (ball.speedX > ball.maxSpeed)
//			{
//				ball.speedX = ball.maxSpeed;
//			}
//		}
//	}
//}
//
//void PaddleBallCollisionRight(Ball& ball, Paddle& rightPaddle)
//{
//	if (CheckCollisionRecs(Rectangle{ GetRectBall(ball) }, Rectangle{ GetPaddleRect(rightPaddle) }))
//	{
//		if (ball.speedX > 0)
//		{
//			ball.x -= ball.width;
//			ball.speedX *= -1.10f;
//			rightPaddle.lastHitTime = 0;
//
//			if (ball.speedX < -ball.maxSpeed)
//			{
//				ball.speedX = -ball.maxSpeed;
//			}
//		}
//	}
//}
//
//void DrawField()
//{
//	DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), Fade(WHITE, 1.0f));
//	DrawCircleLines(GetScreenWidth() / 2, GetScreenHeight() / 2, 70, Fade(WHITE,1.0f));
//	DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 10, Fade(WHITE, 1.0f));
//}