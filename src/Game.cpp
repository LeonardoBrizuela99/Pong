#include "sl.h"
#include "menu/Menu.h"
#include"Game.h"

const float SCREEN_WIDTH = 800.0f;
const float SCREEN_HEIGHT = 600.0f;
const int maxPointsToWin = 5;

Ball ball;
Paddle leftPaddle, rightPaddle;

bool exitWindow = false;
bool endedMatch = false;
bool keyPress = false;
bool winnerPlayer = false;
bool pause = false;
int scoreRight = 0;
int scoreLeft = 0;

void RunGame();
void Init();
void MainLoop();
void Reset();
void CheckInput();
void Update();
void Draw();
void UpdateMenu();
void CreditsWindow();
void WindowInstructions();
void backMenu();
void GetScore(int& scoreRight, int& scoreLeft);
void initBall();
void GetWinner(int& scoreRight, int& scoreLeft, bool& winnerPlayer);
void DrawWinner(int& scoreRight, int& scoreLeft);
void DrawScore(int& scoreRight, int& scoreLeft);
void DrawCredit();
void GameLoop();
void Close();
void CollisionBall(Ball& ball);
void PaddleBallCollisionLeft(Ball& ball, Paddle& leftPaddle);
void PaddleBallCollisionRight(Ball& ball, Paddle& rightPaddle);
void DrawField();

int main(int, char**)
{
    RunGame();
    return 0;
}

void RunGame()
{
    Init();
    MainLoop();
    Close();
}

void Init()
{
    slWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "PONG", false);
    slSetKey(SL_KEY_NULL);
    InitializeTexts();
    ball = CreateBall();
    rightPaddle = CreatePaddle(slGetScreenWidth(SCREEN_WIDTH) - 50, SL_RED, SL_RED);
    leftPaddle = CreatePaddle(50, SL_BLUE, SL_BLUE);
}

void MainLoop()
{
    while (!exitWindow)
    {
        while (!slShouldClose() && !salir)
        {
            ScenesSwitch();
            exitWindow = true;
        }
    }
}

void Reset()
{
    scoreRight = 0;
    scoreLeft = 0;
}

void CheckInput()
{
    MovePaddles(leftPaddle, rightPaddle);
}

void Update()
{
    if (slGetKey('P') || slGetKey(SL_KEY_ESCAPE))
    {
        pause = !pause;
    }

    if (!pause)
    {
        MovePaddles(leftPaddle, rightPaddle);
        UpdateBall(ball);
        UpdatePaddle(leftPaddle, rightPaddle);
        CollisionBall(ball);
        PaddleBallCollisionLeft(ball, leftPaddle);
        PaddleBallCollisionRight(ball, rightPaddle);
        GetScore(scoreRight, scoreLeft);
        GetWinner(scoreRight, scoreLeft, winnerPlayer);
    }
}

void Draw()
{
    slRenderBegin();
    slClearScreen(SL_BEIGE);
    slRectangleFill(0, 0, 5, slGetScreenHeight(SCREEN_HEIGHT), SL_WHITE);
    slRectangleFill(slGetScreenWidth(SCREEN_WIDTH) - 5, 0, 5, slGetScreenHeight(SCREEN_HEIGHT), SL_WHITE);

    DrawField();
    DrawBall(ball);
    DrawPaddle(leftPaddle);
    DrawPaddle(rightPaddle);
    DrawScore(scoreRight, scoreLeft);

    if (pause)
    {
        slRectangleFill(slGetScreenWidth(SCREEN_WIDTH) / 2 - 400, slGetScreenHeight(SCREEN_HEIGHT) / 2 - 300, 850, 600, SL_BEIGE);
        slSetTextSize(100);
        slText(slGetScreenWidth(SCREEN_WIDTH) / 2 - 140, slGetScreenHeight(SCREEN_HEIGHT) / 2 - 250, "Pause", SL_WHITE);
        slSetTextSize(38);
        slText(slGetScreenWidth(SCREEN_WIDTH) / 2 - 360, slGetScreenHeight(SCREEN_HEIGHT) / 2, "Press (P) (ESC) to continue the game", SL_WHITE);
        DrawCredit();
    }

    if (endedMatch)
    {
        slRectangleFill(slGetScreenWidth(SCREEN_WIDTH) / 2 - 400, slGetScreenHeight(SCREEN_HEIGHT) / 2 - 300, 850, 600, SL_BEIGE);
        DrawWinner(scoreRight, scoreLeft);
        slText(50, 250, "Press Space to play again or Esc to Exit", 35, SL_WHITE);
    }

    slRenderEnd();
}

void UpdateMenu()
{
    CheckSinglePlayer();
    CheckInstructions();
    CheckCredits();
    CheckQuit();
}

void CreditsWindow()
{
    slRenderBegin();
    slRectangleFill(slGetScreenWidth() / 2 - 400, slGetScreenHeight() / 2 - 300, 850, 600, SL_BEIGE);
    slSetTextSize(40);
    slText(slGetScreenWidth() / 2 - 300, slGetScreenHeight() / 2 - 10, "Code by: Leonardo Brizuela", SL_WHITE);
    slText(slGetScreenWidth() / 2 - 350, slGetScreenHeight() / 2 + 200, "(ESC) Back", SL_WHITE);
    slRenderEnd();

    if (slGetKey(SL_KEY_ESCAPE))
    {
        menu = MenuScenes::MainMenu;
    }
}

void WindowInstructions()
{
    slRenderBegin();
    slRectangleFill(slGetScreenWidth() / 2 - 400, slGetScreenHeight() / 2 - 300, 850, 600, SL_BEIGE);
    slSetTextSize(40);
    slText(slGetScreenWidth() / 2 - 350, slGetScreenHeight() / 2 - 10, "Use Up/Down to move right paddles", SL_WHITE);
    slText(slGetScreenWidth() / 2 - 300, slGetScreenHeight() / 2 - 100, "Use W/S to move left paddles", SL_WHITE);
    slText(slGetScreenWidth() / 2 - 350, slGetScreenHeight() / 2 + 200, "(ESC) Back", SL_WHITE);
    slRenderEnd();

    if (slGetKey(SL_KEY_ESCAPE))
    {
        menu = MenuScenes::MainMenu;
    }
}

int slGetScreenWidth(int w)
{
    return w;
}

int slGetScreenHeight(int h)
{
    return h;
}

void backMenu()
{
    if (slGetKey(SL_KEY_ESCAPE))
    {
        menu = MenuScenes::MainMenu;
    }
}

void GetScore(int& scoreRight, int& scoreLeft)
{
    if (ball.x < 0)
    {
        scoreRight++;
        initBall();
    }

    if (ball.x > slGetScreenWidth())
    {
        scoreLeft++;
        initBall();
    }
}

void initBall()
{
    CalculateRandom(ball);

    ball.x = slGetScreenWidth() / 2;
    ball.y = slGetScreenHeight() / 2;
}

void GetWinner(int& scoreRight, int& scoreLeft, bool& winnerPlayer)
{
    if (scoreRight >= maxPointsToWin)
    {
        winnerPlayer = true;
        endedMatch = true;
    }
    else if (scoreLeft >= maxPointsToWin)
    {
        winnerPlayer = true;
        endedMatch = true;
    }
}

void DrawWinner(int& scoreRight, int& scoreLeft)
{
    if (scoreRight >= maxPointsToWin)
    {
        slSetTextSize(35);
        slText(slGetScreenWidth() / 2 - 125, slGetScreenHeight() / 2, "Right Player Win", SL_RED);
    }
    else if (scoreLeft >= maxPointsToWin)
    {
        slSetTextSize(35);
        slText(slGetScreenWidth() / 2 - 125, slGetScreenHeight() / 2, "Left Player Win", SL_BLUE);
    }
}

void DrawScore(int& scoreRight, int& scoreLeft)
{
    slSetTextSize(40);
    slText(slGetScreenWidth() - 180, 10, TextFormat("  %02i", scoreRight), SL_RED);
    slText(70, 10, TextFormat("  %02i", scoreLeft), SL_BLUE);
}

void DrawCredit()
{
    slSetTextSize(40);
    slText(slGetScreenWidth() / 2 - 300, slGetScreenHeight() / 2 + 100, "Credit: Leonardo Brizuela", SL_WHITE);
}

void GameLoop()
{
    if (endedMatch)
    {
        if (slGetKey(SL_KEY_ENTER))
        {
            endedMatch = false;
            Reset();
        }
        if (slGetKey(SL_KEY_ESCAPE))
        {
            salir = true;
        }
    }
    else
    {
        CheckInput();
        Update();
    }
    Draw();
}

void Close()
{
    slClose();
}

void CollisionBall(Ball& ball)
{
    if (ball.y < 0)
    {
        if (ball.speedY < 0)
        {
            ball.y += ball.height;
            ball.speedY *= -1;
        }
    }

    if (ball.y > slGetScreenHeight())
    {
        if (ball.speedY > 0)
        {
            ball.y -= ball.height;
            ball.speedY *= -1;
        }
    }
}

void PaddleBallCollisionLeft(Ball& ball, Paddle& leftPaddle)
{
    if (slCheckCollisionRecs(SL_Rectangle{ GetRectBall(ball) }, SL_Rectangle{ GetPaddleRect(leftPaddle) }))
    {
        if (ball.speedX < 0)
        {
            ball.x += ball.width;
            ball.speedX *= -1.10f;
            leftPaddle.lastHitTime = 0;

            if (ball.speedX > ball.maxSpeed)
            {
                ball.speedX = ball.maxSpeed;
            }
        }
    }
}

void PaddleBallCollisionRight(Ball& ball, Paddle& rightPaddle)
{
    if (slCheckCollisionRecs(SL_Rectangle{ GetRectBall(ball) }, SL_Rectangle{ GetPaddleRect(rightPaddle) }))
    {
        if (ball.speedX > 0)
        {
            ball.x -= ball.width;
            ball.speedX *= -1.10f;
            rightPaddle.lastHitTime = 0;

            if (ball.speedX < -ball.maxSpeed)
            {
                ball.speedX = -ball.maxSpeed;
            }
        }
    }
}

void DrawField()
{
    slRenderBegin();
    slLine(slGetScreenWidth() / 2, 0, slGetScreenWidth() / 2, slGetScreenHeight(), SL_WHITE);
    slCircleOutline(slGetScreenWidth() / 2, slGetScreenHeight() / 2, 70, SL_WHITE);
    slCircleFill(slGetScreenWidth() / 2, slGetScreenHeight() / 2, 10, SL_WHITE);
    slRenderEnd();
}




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