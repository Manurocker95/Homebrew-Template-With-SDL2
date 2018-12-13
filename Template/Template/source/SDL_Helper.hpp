#pragma once

#include <switch.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h> 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "SDL_FontCache.h"

class SDL_Helper
{
private:
	bool m_initialized;
	SDL_Renderer * m_renderer;
	SDL_Window * m_window;
	FC_Font * Roboto, * Roboto_large, * Roboto_small, * Roboto_OSK;
	PlFontData fontData, fontExtData;

public:
	SDL_Helper();
	SDL_Renderer *SDL_GetMainRenderer(void);
	SDL_Window *SDL_GetMainWindow(void);
	Result SDL_HelperInit(void);
	FC_Font * GetFont(int size);
	void SDL_Exit(void);
	void SDL_ClearScreen(SDL_Color colour);
	void SDL_DrawRect(int x, int y, int w, int h, SDL_Color colour);
	void SDL_DrawCircle(int x, int y, int r, SDL_Color colour);
	void SDL_DrawText(int x, int y, int size, SDL_Color colour, const char *text);
	void SDL_DrawTextf(int x, int y, int size, SDL_Color colour, const char* text, ...);
	void SDL_GetTextDimensions(int size, const char *text, u32 *width, u32 *height);
	void SDL_LoadImage(SDL_Texture **texture, char *path);
	void SDL_LoadImageBuf(SDL_Texture **texture, void *mem, int size);
	void SDL_DrawImageOpacity(SDL_Texture *texture, int x, int y, int alpha);
	void SDL_DrawImageScaleOpacity(SDL_Texture *texture, int x, int y, int w, int h, int alpha);
	void SDL_DrawImage(SDL_Texture *texture, int x, int y);
	void SDL_DrawImageScale(SDL_Texture *texture, int x, int y, int w, int h);
	void SDL_Renderdisplay(void);
	void SDL_DestroyTexture(SDL_Texture * texture);
	void SDL_DrawBG(SDL_Color clearColor, SDL_Color colour);
	bool SDL_IsInitialized(void);
};
