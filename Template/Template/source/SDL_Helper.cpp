#include "SDL_Helper.hpp"
#include <iostream>

SDL_Helper::SDL_Helper()
{

}

SDL_Renderer * SDL_Helper::SDL_GetMainRenderer(void) 
{
	return this->m_renderer;
}

SDL_Window * SDL_Helper::SDL_GetMainWindow(void) 
{
	return this->m_window;
}

bool SDL_Helper::SDL_IsInitialized(void)
{
	return this->m_initialized;
}

FC_Font * SDL_Helper::GetFont(int size) 
{
	if (size == 20)
		return this->Roboto_small;
	else if (size == 25)
		return this->Roboto;
	else if (size == 30)
		return this->Roboto_large;
	else
		return this->Roboto_OSK;

	return this->Roboto;
}

Result SDL_Helper::SDL_HelperInit(void) 
{
	Result ret = 0;

	SDL_Init(SDL_INIT_EVERYTHING);
	this->m_window = SDL_CreateWindow("Homebrew-Template", 0, 0, 1280, 720, SDL_WINDOW_FULLSCREEN);
	this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(this->m_renderer, SDL_BLENDMODE_BLEND);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID);

	if (R_FAILED(ret = plGetSharedFontByType(&this->fontData, PlSharedFontType_Standard)))
		return ret;

	if (R_FAILED(ret = plGetSharedFontByType(&this->fontExtData, PlSharedFontType_NintendoExt)))
		return ret;

	this->Roboto = FC_CreateFont();
	FC_LoadFont_RW(this->Roboto, this->m_renderer, SDL_RWFromMem((void*)this->fontData.address, this->fontData.size), SDL_RWFromMem((void*)this->fontExtData.address, this->fontExtData.size), 1, 25, FC_MakeColor(0, 0, 0, 255), TTF_STYLE_NORMAL);

	this->Roboto_large = FC_CreateFont();
	FC_LoadFont_RW(this->Roboto_large, this->m_renderer, SDL_RWFromMem((void*)this->fontData.address, this->fontData.size), SDL_RWFromMem((void*)this->fontExtData.address, this->fontExtData.size), 1, 30, FC_MakeColor(0, 0, 0, 255), TTF_STYLE_NORMAL);

	this->Roboto_small = FC_CreateFont();
	FC_LoadFont_RW(this->Roboto_small, this->m_renderer, SDL_RWFromMem((void*)this->fontData.address, this->fontData.size), SDL_RWFromMem((void*)this->fontExtData.address, this->fontExtData.size), 1, 20, FC_MakeColor(0, 0, 0, 255), TTF_STYLE_NORMAL);

	this->Roboto_OSK = FC_CreateFont();
	FC_LoadFont_RW(this->Roboto_OSK, this->m_renderer, SDL_RWFromMem((void*)this->fontData.address, this->fontData.size), SDL_RWFromMem((void*)this->fontExtData.address, this->fontExtData.size), 1, 50, FC_MakeColor(0, 0, 0, 255), TTF_STYLE_NORMAL);
	
	this->m_initialized = true;
	
	return 0;
}

void SDL_Helper::SDL_Exit(void) 
{
	FC_FreeFont(this->Roboto_OSK);
	FC_FreeFont(this->Roboto_small);
	FC_FreeFont(this->Roboto_large);
	FC_FreeFont(this->Roboto);
	TTF_Quit();

	Mix_Quit();

	IMG_Quit();

	SDL_DestroyRenderer(this->m_renderer);
	SDL_DestroyWindow(this->m_window);
	SDL_Quit();
}


void SDL_Helper::SDL_ClearScreen(SDL_Color colour) 
{
	SDL_SetRenderDrawColor(this->m_renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderClear(this->m_renderer);
}

void SDL_Helper::SDL_DrawRect(int x, int y, int w, int h, SDL_Color colour) 
{
	SDL_Rect rect;
	rect.x = x; rect.y = y; rect.w = w; rect.h = h;
	SDL_SetRenderDrawColor(this->m_renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderFillRect(this->m_renderer, &rect);
}

void SDL_Helper::SDL_DrawCircle(int x, int y, int r, SDL_Color colour) 
{
	filledCircleRGBA(this->m_renderer, x, y, r, colour.r, colour.g, colour.b, colour.a);
	return;
}

void SDL_Helper::SDL_DrawText(int x, int y, int size, SDL_Color colour, const char *text) 
{
	FC_DrawColor(GetFont(size), this->m_renderer, x, y, colour, text);
}

void SDL_Helper::SDL_DrawTextf(int x, int y, int size, SDL_Color colour, const char* text, ...) 
{
	char buffer[256];
	va_list args;
	va_start(args, text);
	vsnprintf(buffer, 256, text, args);
	SDL_DrawText(x, y, size, colour, buffer);
	va_end(args);
}


void SDL_Helper::SDL_GetTextDimensions(int size, const char *text, u32 *width, u32 *height) 
{
	FC_Font *font = GetFont(size);

	if (width != NULL)
		*width = FC_GetWidth(font, text);
	if (height != NULL)
		*height = FC_GetHeight(font, text);
}


void SDL_Helper::SDL_LoadImage(SDL_Texture **texture, char *path) 
{
	SDL_Surface *loaded_surface = NULL;
	loaded_surface = IMG_Load(path);

	if (loaded_surface) {
		Uint32 colorkey = SDL_MapRGB(loaded_surface->format, 0, 0, 0);
		SDL_SetColorKey(loaded_surface, SDL_TRUE, colorkey);
		*texture = SDL_CreateTextureFromSurface(this->m_renderer, loaded_surface);
	}

	SDL_FreeSurface(loaded_surface);
}

void SDL_Helper::SDL_DrawImage(SDL_Texture *texture, int x, int y) 
{
	SDL_Rect position;
	position.x = x; position.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(this->m_renderer, texture, NULL, &position);
}

void SDL_Helper::SDL_DrawImageScale(SDL_Texture *texture, int x, int y, int w, int h) 
{
	SDL_Rect position;
	position.x = x; position.y = y; position.w = w; position.h = h;
	SDL_RenderCopy(this->m_renderer, texture, NULL, &position);
}

void SDL_Helper::SDL_Renderdisplay(void) 
{
	SDL_RenderPresent(this->m_renderer);
}

void SDL_Helper::SDL_DrawImageOpacity(SDL_Texture *texture, int x, int y, int opacity)
{
	SDL_SetTextureAlphaMod(texture, opacity);
	SDL_Rect position;
	position.x = x; position.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(this->m_renderer, texture, NULL, &position);
}

void SDL_Helper::SDL_DrawImageScaleOpacity(SDL_Texture *texture, int x, int y, int w, int h, int opacity)
{
	SDL_SetTextureAlphaMod(texture, opacity);
	SDL_Rect position;
	position.x = x; position.y = y; position.w = w; position.h = h;
	SDL_RenderCopy(this->m_renderer, texture, NULL, &position);
}

void SDL_Helper::SDL_DestroyTexture(SDL_Texture * texture)
{
	SDL_DestroyTexture(texture);
}

void SDL_Helper::SDL_DrawBG(SDL_Color clearColor, SDL_Color colour)
{
	SDL_ClearScreen(clearColor);
	SDL_DrawRect(0, 0, 1280, 720, colour);
}