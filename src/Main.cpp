//#include "Game.h"
////Hecho por: Leonardo Brizuela
//
//int main()
//{
//	RunGame();
//	return 0;
//}
#include "sl.h"

int main()
{
	const int width = 800;
	const int height = 600;

	slWindow(width, height, "Simple SIGIL Example", false);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		slSetBackColor(0.5, 0.75, 1.0);

		slSetForeColor(0, 1, 0, 1);
		slRectangleFill(width * 0.5, height * 0.5, 100, 100);
		if (slGetKey(SL_KEY_UP))
		{
			slRectangleFill(width * 0.5, height * (0.5+1), 100, 100);
		}
		

		slRender();
	}

	slClose();

	return 0;
}
