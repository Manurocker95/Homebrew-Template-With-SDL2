#pragma once
#ifndef _TITLE_SCREEN_HPP_
#define _TITLE_SCREEN_HPP_

#include "Scene.hpp"

class TitleScreen : public Scene
{
public:

	TitleScreen();				// Constructor
	~TitleScreen();				// Destructor
	void Start(SDL_Helper * helper) override;				// initialize
	void Draw() override;				// Draw
	void CheckInputs(u64 kDown) override;			// CheckInput
	void Update() override;				// Update
	void NextScene() override;
private:
	SDL_Texture * m_background;
	SDL_Texture * m_logo;
};

#endif