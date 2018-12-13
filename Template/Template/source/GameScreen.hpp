#pragma once
#ifndef _GAME_SCREEN_HPP_
#define _GAME_SCREEN_HPP_

#include "Scene.hpp"

class GameScreen : public Scene
{
public:

	GameScreen();								// Constructor
	~GameScreen();								// Destructor
	void Start(SDL_Helper * helper) override;	// initialize
	void Draw() override;						// Draw
	void CheckInputs(u64 kDown) override;		// CheckInput
	void Update() override;						// Update
	void NextScene() override;
private:
	SDL_Texture * m_background;
	SDL_Texture * m_logo;
};

#endif