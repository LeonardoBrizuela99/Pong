#include "sl.h"
#include "Menu.h"
#include "Game.h"

MenuScenes menu;
Buttons Texto[4];
bool salir;

void InitializeTexts()
{
    Texto[0].text = "  JUGAR ";
    Texto[0].fontSize = 40;
    Texto[0].pos.x = slGetScreenWidth() / 2 - slMeasureText(Texto[0].text.c_str(), 50) / 2.0f + 12;
    Texto[0].pos.y = 50;

    Texto[0].backgroundBttn.x = slGetScreenWidth() / 2.0f - slMeasureText(Texto[0].text.c_str(), 50) / 2;
    Texto[0].backgroundBttn.y = 47;
    Texto[0].backgroundBttn.width = static_cast<float>(slMeasureText(Texto[0].text.c_str(), 50));
    Texto[0].backgroundBttn.height = 50;

    Texto[1].text = " REGLAS  ";
    Texto[1].fontSize = 40;
    Texto[1].pos.x = slGetScreenWidth() / 2 - slMeasureText(Texto[0].text.c_str(), 50) / 2.0f + 5;
    Texto[1].pos.y = 170;

    Texto[1].backgroundBttn.x = slGetScreenWidth() / 2.0f - slMeasureText(Texto[0].text.c_str(), 50) / 2;
    Texto[1].backgroundBttn.y = 163;
    Texto[1].backgroundBttn.width = static_cast<float>(slMeasureText(Texto[0].text.c_str(), 50));
    Texto[1].backgroundBttn.height = 50;

    Texto[2].text = "CRÉDITOS";
    Texto[2].fontSize = 40;
    Texto[2].pos.x = slGetScreenWidth() / 2 - slMeasureText(Texto[1].text.c_str(), 50) / 2.0f + 22;
    Texto[2].pos.y = 310;

    Texto[2].backgroundBttn.x = slGetScreenWidth() / 2.0f - slMeasureText(Texto[1].text.c_str(), 50) / 2;
    Texto[2].backgroundBttn.y = 303;
    Texto[2].backgroundBttn.width = static_cast<float>(slMeasureText(Texto[1].text.c_str(), 50));
    Texto[2].backgroundBttn.height = 50;

    Texto[3].text = "SALIR";
    Texto[3].fontSize = 40;
    Texto[3].pos.x = slGetScreenWidth() / 2 - slMeasureText(Texto[2].text.c_str(), 50) / 2.0f + 13;
    Texto[3].pos.y = 420;

    Texto[3].backgroundBttn.x = slGetScreenWidth() / 2.0f - slMeasureText(Texto[2].text.c_str(), 50) / 2;
    Texto[3].backgroundBttn.y = 415;
    Texto[3].backgroundBttn.width = static_cast<float>(slMeasureText(Texto[2].text.c_str(), 50));
    Texto[3].backgroundBttn.height = 50;
}

void DrawSinglePlayer()
{
    slRectangleFill(Texto[0].backgroundBttn.x, Texto[0].backgroundBttn.y, Texto[0].backgroundBttn.width, Texto[0].backgroundBttn.height, SL_BLACK);
    slText(Texto[0].text.c_str(), Texto[0].pos.x, Texto[0].pos.y, Texto[0].fontSize, SL_BLUE);

    if (slCheckCollisionPointRec(slGetMousePosition(), Texto[0].backgroundBttn))
    {
        slRectangle(Texto[0].backgroundBttn.x, Texto[0].backgroundBttn.y, Texto[0].backgroundBttn.width, Texto[0].backgroundBttn.height, SL_COLOR(SL_BLACK, 0.50f));
        slText(Texto[0].text.c_str(), Texto[0].pos.x, Texto[0].pos.y, Texto[0].fontSize, SL_RED);
    }
}

void CheckSinglePlayer()
{
    if (slGetMouseButtonDown(MOUSE_BUTTON_LEFT) && slCheckCollisionPointRec(slGetMousePosition(), Texto[0].backgroundBttn))
    {
        menu = MenuScenes::Play;
    }
}

void DrawInstruction()
{
    slRectangle(Texto[1].backgroundBttn.x, Texto[1].backgroundBttn.y, Texto[1].backgroundBttn.width, Texto[1].backgroundBttn.height, SL_WHITE);
    slRectangleFill(Texto[1].backgroundBttn.x, Texto[1].backgroundBttn.y, Texto[1].backgroundBttn.width, Texto[1].backgroundBttn.height, SL_BLACK);
    slText(Texto[1].text.c_str(), Texto[1].pos.x, Texto[1].pos.y, Texto[1].fontSize, SL_COLOR(SL_DARK_BLUE));

    if (slCheckCollisionPointRec(slGetMousePosition(), Texto[1].backgroundBttn))
    {
        slRectangleOutline(Texto[1].backgroundBttn.x - 1, Texto[1].backgroundBttn.y - 1, Texto[1].backgroundBttn.width + 2, Texto[1].backgroundBttn.height + 2, SL_RED);
        slRectangle(Texto[1].backgroundBttn.x, Texto[1].backgroundBttn.y, Texto[1].backgroundBttn.width, Texto[1].backgroundBttn.height, SL_BLACK);
        slText(Texto[1].text.c_str(), Texto[1].pos.x, Texto[1].pos.y, Texto[1].fontSize, SL_RED);
    }
}

void CheckInstructions()
{
    if (slGetMouseButtonDown(MOUSE_BUTTON_LEFT) && slCheckCollisionPointRec(slGetMousePosition(), Texto[1].backgroundBttn))
    {
        menu = MenuScenes::Instructions;
    }
}

void DrawCredits()
{
    slRectangleFill(Texto[2].backgroundBttn.x, Texto[2].backgroundBttn.y, Texto[2].backgroundBttn.width, Texto[2].backgroundBttn.height, SL_BLACK);
    slText(Texto[2].text.c_str(), Texto[2].pos.x, Texto[2].pos.y, Texto[2].fontSize, SL_BLUE);

    if (slCheckCollisionPointRec(slGetMousePosition(), Texto[2].backgroundBttn))
    {
        slRectangle(Texto[2].backgroundBttn.x, Texto[2].backgroundBttn.y, Texto[2].backgroundBttn.width, Texto[2].backgroundBttn.height, SL_BLACK);
        slText(Texto[2].text.c_str(), Texto[2].pos.x, Texto[2].pos.y, Texto[2].fontSize, SL_RED);
    }
}

void CheckCredits()
{
    if (slGetMouseButtonDown(MOUSE_BUTTON_LEFT) && slCheckCollisionPointRec(slGetMousePosition(), Texto[2].backgroundBttn))
    {
        menu = MenuScenes::Credits;
    }
}

void DrawQuit()
{
    slRectangleFill(Texto[3].backgroundBttn.x, Texto[3].backgroundBttn.y, Texto[3].backgroundBttn.width, Texto[3].backgroundBttn.height, SL_BLACK);
    slText(Texto[3].text.c_str(), Texto[2].pos.x, Texto[3].pos.y, Texto[3].fontSize, SL_RED);

    if (slCheckCollisionPointRec(slGetMousePosition(), Texto[3].backgroundBttn))
    {
        slRectangle(Texto[3].backgroundBttn.x, Texto[3].backgroundBttn.y, Texto[3].backgroundBttn.width, Texto[3].backgroundBttn.height, SL_BLACK);
        slText(Texto[3].text.c_str(), Texto[2].pos.x, Texto[3].pos.y, Texto[3].fontSize, SL_RED);
    }
}

void CheckQuit()
{
    if (slGetMouseButtonDown(MOUSE_BUTTON_LEFT) && slCheckCollisionPointRec(slGetMousePosition(), Texto[3].backgroundBttn))
    {
        menu = MenuScenes::Quit;
    }
}

void DrawButtons()
{
    slRenderBegin();
    slRectangleFill(slGetScreenWidth() / 2 - 400, slGetScreenHeight() / 2 - 300, 850, 600, SL_BEIGE);
    DrawSinglePlayer();
    DrawInstruction();
    DrawCredits();
    DrawQuit();
    slRenderEnd();
}

void ScenesSwitch()
{
    switch (menu)
    {
    case MenuScenes::MainMenu:

        UpdateMenu();
        DrawButtons();

        break;

    case MenuScenes::Play:

        GameLoop();

        break;

    case MenuScenes::Instructions:

        WindowInstructions();
        break;

    case MenuScenes::Credits:

        CreditsWindow();

        break;

    case MenuScenes::Quit:

        salir = true;
        break;
    }
}


//#include <String>
//#include"raylib.h"
//#include"Menu.h"
//#include"../Game.h"
//using namespace std;
//
//MenuScenes menu;
//Buttons Texto[4];
//bool salir;
//
//void InitializeTexts()
//{
//	Texto[0].text = "  PLAY ";
//	Texto[0].fontSize = 40;
//	Texto[0].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[0].text.c_str(), 50) / 2.0f + 12;
//	Texto[0].pos.y = 50;
//
//	Texto[0].backgroundBttn.x = GetScreenWidth() / 2.0f - MeasureText(Texto[0].text.c_str(), 50) / 2;
//	Texto[0].backgroundBttn.y = 47;
//	Texto[0].backgroundBttn.width = static_cast<float>(MeasureText(Texto[0].text.c_str(), 50));
//	Texto[0].backgroundBttn.height = 50;
//
//	Texto[1].text = " RULES  ";
//	Texto[1].fontSize = 40;
//	Texto[1].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[0].text.c_str(), 50) / 2.0f + 5;
//	Texto[1].pos.y = 170;
//
//	Texto[1].backgroundBttn.x = GetScreenWidth() / 2.0f - MeasureText(Texto[0].text.c_str(), 50) / 2;
//	Texto[1].backgroundBttn.y = 163;
//	Texto[1].backgroundBttn.width = static_cast<float>(MeasureText(Texto[0].text.c_str(), 50));
//	Texto[1].backgroundBttn.height = 50;
//
//	Texto[2].text = "CREDITS";
//	Texto[2].fontSize = 40;
//	Texto[2].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[1].text.c_str(), 50) / 2.0f + 22;
//	Texto[2].pos.y = 310;
//
//	Texto[2].backgroundBttn.x = GetScreenWidth() / 2.0f - MeasureText(Texto[1].text.c_str(), 50) / 2;
//	Texto[2].backgroundBttn.y = 303;
//	Texto[2].backgroundBttn.width = static_cast<float>(MeasureText(Texto[1].text.c_str(), 50));
//	Texto[2].backgroundBttn.height = 50;
//
//
//	Texto[3].text = "QUIT";
//	Texto[3].fontSize = 40;
//	Texto[3].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[2].text.c_str(), 50) / 2.0f + 13;
//	Texto[3].pos.y = 420;
//
//	Texto[3].backgroundBttn.x = GetScreenWidth() / 2.0f - MeasureText(Texto[2].text.c_str(), 50) / 2;
//	Texto[3].backgroundBttn.y = 415;
//	Texto[3].backgroundBttn.width = static_cast<float>(MeasureText(Texto[2].text.c_str(), 50));
//	Texto[3].backgroundBttn.height = 50;
//}
//
//void DrawSinglePlayer()
//{
//	DrawRectangleGradientV(static_cast<int>(Texto[0].backgroundBttn.x), static_cast<int>(Texto[0].backgroundBttn.y), static_cast<int>(Texto[0].backgroundBttn.width), static_cast<int>(Texto[0].backgroundBttn.height), BLACK, Fade(DARKPURPLE, 0.5f));
//	DrawText(Texto[0].text.c_str(), static_cast<int> (Texto[0].pos.x), static_cast<int>(Texto[0].pos.y), static_cast<int> (Texto[0].fontSize), BLUE);
//
//	if (CheckCollisionPointRec(GetMousePosition(), Texto[0].backgroundBttn))
//	{
//		DrawRectangle(static_cast<int>(Texto[0].backgroundBttn.x), static_cast<int>(Texto[0].backgroundBttn.y), static_cast<int>(Texto[0].backgroundBttn.width), static_cast<int>(Texto[0].backgroundBttn.height), Fade(BLACK,0.50f));
//		DrawText(Texto[0].text.c_str(), static_cast<int> (Texto[0].pos.x), static_cast<int>(Texto[0].pos.y), static_cast<int> (Texto[0].fontSize), RED);
//	}
//}
//
//void CheckSinglePlayer()
//{
//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[0].backgroundBttn))
//	{
//		menu = MenuScenes::Play;
//	}
//}
//
//void DrawInstruction()
//{
//	DrawRectangle(static_cast<int>(Texto[1].backgroundBttn.x), static_cast<int>(Texto[1].backgroundBttn.y), static_cast<int>(Texto[1].backgroundBttn.width), static_cast<int>(Texto[1].backgroundBttn.height), WHITE);
//	DrawRectangleGradientV(static_cast<int>(Texto[1].backgroundBttn.x), static_cast<int>(Texto[1].backgroundBttn.y), static_cast<int>(Texto[1].backgroundBttn.width), static_cast<int>(Texto[1].backgroundBttn.height), BLACK, Fade(DARKPURPLE, 0.5f));
//	DrawText(Texto[1].text.c_str(), static_cast<int> (Texto[1].pos.x), static_cast<int>(Texto[1].pos.y), static_cast<int> (Texto[1].fontSize), DARKBLUE);
//
//	if (CheckCollisionPointRec(GetMousePosition(), Texto[1].backgroundBttn))
//	{
//		DrawRectangleLines(static_cast<int>(Texto[1].backgroundBttn.x-1), static_cast<int>(Texto[1].backgroundBttn.y-1), static_cast<int>(Texto[1].backgroundBttn.width+2), static_cast<int>(Texto[1].backgroundBttn.height+2), RED);
//		DrawRectangle(static_cast<int>(Texto[1].backgroundBttn.x), static_cast<int>(Texto[1].backgroundBttn.y), static_cast<int>(Texto[1].backgroundBttn.width), static_cast<int>(Texto[1].backgroundBttn.height), BLACK);
//		DrawText(Texto[1].text.c_str(), static_cast<int> (Texto[1].pos.x), static_cast<int>(Texto[1].pos.y), static_cast<int> (Texto[1].fontSize), RED);
//	}
//}
//
//void CheckInstructions()
//{
//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[1].backgroundBttn))
//	{
//		menu = MenuScenes::Instructions;
//	}
//}
//
//void DrawCredits()
//{
//	
//	DrawRectangleGradientV(static_cast<int>(Texto[2].backgroundBttn.x), static_cast<int>(Texto[2].backgroundBttn.y), static_cast<int>(Texto[2].backgroundBttn.width), static_cast<int>(Texto[2].backgroundBttn.height), BLACK, Fade(DARKPURPLE, 0.5f));
//	DrawText(Texto[2].text.c_str(), static_cast<int>(Texto[2].pos.x), static_cast<int>(Texto[2].pos.y), static_cast<int>(Texto[2].fontSize), BLUE);
//
//	if (CheckCollisionPointRec(GetMousePosition(), Texto[2].backgroundBttn))
//	{
//		DrawRectangle(static_cast<int>(Texto[2].backgroundBttn.x), static_cast<int>(Texto[2].backgroundBttn.y), static_cast<int>(Texto[2].backgroundBttn.width), static_cast<int>(Texto[2].backgroundBttn.height), BLACK);
//		DrawText(Texto[2].text.c_str(), static_cast<int>(Texto[2].pos.x), static_cast<int>(Texto[2].pos.y), static_cast<int>(Texto[2].fontSize), RED);
//	}
//}
//
//void CheckCredits()
//{
//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[2].backgroundBttn))
//	{
//		menu = MenuScenes::Credits;
//	}
//}
//
//void DrawQuit()
//{
//	DrawRectangleGradientV(static_cast<int>(Texto[3].backgroundBttn.x), static_cast<int>(Texto[3].backgroundBttn.y), static_cast<int>(Texto[3].backgroundBttn.width), static_cast<int>(Texto[3].backgroundBttn.height), BLACK, Fade(DARKPURPLE, 0.5f));
//	DrawText(Texto[3].text.c_str(), static_cast<int>(Texto[2].pos.x), static_cast<int>(Texto[3].pos.y), static_cast<int>(Texto[3].fontSize), RED);
//
//	if (CheckCollisionPointRec(GetMousePosition(), Texto[3].backgroundBttn))
//	{
//		DrawRectangle(static_cast<int>(Texto[3].backgroundBttn.x), static_cast<int>(Texto[3].backgroundBttn.y), static_cast<int>(Texto[3].backgroundBttn.width), static_cast<int>(Texto[3].backgroundBttn.height), BLACK);
//		DrawText(Texto[3].text.c_str(), static_cast<int>(Texto[2].pos.x), static_cast<int>(Texto[3].pos.y), static_cast<int>(Texto[3].fontSize), RED);
//	}
//}
//
//void CheckQuit()
//{
//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[3].backgroundBttn))
//	{
//		menu = MenuScenes::Quit;
//	}
//}
//
//void DrawButtons()
//{
//	BeginDrawing();
//	DrawRectangleGradientV(GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 300, 850, 600, BEIGE, Fade(RED, 1.0f));
//	DrawSinglePlayer();
//	DrawInstruction();
//	DrawCredits();
//	DrawQuit();
//	EndDrawing();
//}
//
//void ScenesSwitch()
//{
//	switch (menu)
//	{
//	case MenuScenes::MainMenu:
//
//		UpdateMenu();
//		DrawButtons();
//
//		break;
//
//	case MenuScenes::Play:
//
//		GameLoop();
//
//		break;
//
//	case MenuScenes::Instructions:
//
//		
//		WindowInstructions();
//		break;
//
//	case MenuScenes::Credits:
//
//		CreditsWindow();
//
//		break;
//
//	case MenuScenes::Quit:
//
//		salir = true;
//		break;
//	}
//}