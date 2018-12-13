// Include cout library
#include <iostream>

// Include the main libnx system header, for Switch development
#include <switch.h>
#include "SDL_Helper.hpp"
#include "Colors.h"
#include "Settings.h"
#include "SceneManager.hpp"

// Main program entrypoint
int main(int argc, char* argv[])
{
	consoleInit(NULL);
	plInitialize();
	romfsInit();
	SDL_Helper * helper = new SDL_Helper();
	helper->SDL_HelperInit();
	
	SceneManager::Instance()->Start(helper);

	// Main loop
	while (appletMainLoop())
	{
		helper->SDL_ClearScreen(BLACK);
		helper->SDL_DrawRect(0, 0, SWITCH_SCREEN_WIDTH, SWITCH_SCREEN_HEIGHT, WHITE);
		
		SceneManager::Instance()->Update();

		if (SceneManager::Instance()->IsOut())
			break; // break in order to return to hbmenu

		helper->SDL_Renderdisplay();
	}

	plExit();
	romfsExit();
	helper->SDL_Exit();
	delete(helper);

	return 0;
}