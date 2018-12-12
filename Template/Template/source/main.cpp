// Include cout library
#include <iostream>

// Include the main libnx system header, for Switch development
#include <switch.h>
#include "SDL_Helper.hpp"
#include "Colors.h"

// Main program entrypoint
int main(int argc, char* argv[])
{
	consoleInit(NULL);
	plInitialize();
	romfsInit();
	SDL_Helper * helper = new SDL_Helper();
	helper->SDL_HelperInit();
	
	SDL_Texture * myTexture;
	helper->SDL_LoadImage(&myTexture, "romfs:/ballnormal.png");

	if (helper->SDL_IsInitialized())
	{
		// Other initialization goes here. As a demonstration, we print hello world.
		std::cout << "SDL WAS INITIALIZED\n" << std::endl;
	}
	else
	{
		std::cout << "SDL NOT INITIALIZED\n" << std::endl;
	}
	
	helper->SDL_ClearScreen(WHITE);

	int _x = 20;
	int _y = 20;

	// Main loop
	while (appletMainLoop())
	{
		helper->SDL_ClearScreen(BLACK);
		helper->SDL_DrawRect(0, 0, 1280, 720, WHITE);

		// Scan all the inputs. This should be done once for each frame
		hidScanInput();

		// hidKeysDown returns information about which buttons have been
		// just pressed in this frame compared to the previous one
		u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

		helper->SDL_DrawText(600, 20, 16, BLACK, "HOMEBREW TEMPLATE\n");

		if (kDown & KEY_RIGHT)
			_x+=10;

		if (kDown & KEY_LEFT)
			_x-=10;

		if (kDown & KEY_DOWN)
			_y+=10;

		if (kDown & KEY_UP)
			_y-=10;

		if (kDown & KEY_PLUS)
			break; // break in order to return to hbmenu

		if (kDown & KEY_A)
		{
			helper->SDL_DrawText(20, 20, 16, BLACK, "PRESSED A\n");
			//std::cout << "Pressed A\n" << std::endl;
		}
			
		
		helper->SDL_DrawImage(myTexture, _x, _y);
		helper->SDL_Renderdisplay();

	}

	plExit();
	romfsExit();
	helper->SDL_Exit();
	delete(helper);

	return 0;
}
