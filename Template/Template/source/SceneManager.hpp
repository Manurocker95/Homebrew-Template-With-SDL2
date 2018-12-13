#pragma once
#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include <fstream>
#include <sstream>

#include "SplashScreen.hpp"
#include "TitleScreen.hpp"
#include "GameScreen.hpp"

class SceneManager
{
public:

	enum SCENES { SPLASH, TITLE, GAME };	// Scenes: Splashcreen, TitleScreen, Gamescreen

	static SceneManager * Instance();		// Property to get the singleton instance

	void setActualScene(SCENES _scene);		// Method to set a new scene (E.G: SplashScreen -> GameScreen)
	void Start(SDL_Helper * helper);		// Method for initialization
	void Update();							// Method called every frame. It calls to scene Draw, Update and CheckInput functions
	void Draw();							// Method called every frame. It calls to scene Draw, Update and CheckInput functions
	void CheckInputs();							// Method called every frame. It calls to scene Draw, Update and CheckInput functions
	bool IsOut();							// Method that returns if we are exiting the game from scene (normal exiting)
	void ExitGame();						// Method to exit the game (Out = true)
	void ReadData();						// Method for reading data from our save
	void SaveDataAndExit();					// Method that saves our data to the .sav and exits
	void Exit();
private:

	SceneManager() {};						// Private so that it can  not be called
	static SceneManager * instance;			// Singleton Instance

	int m_times_we_have_run_the_program;	// Variable saved in our .sav
	bool m_out;								// if we ended or not the program
	Scene * m_actualScene;					// Scene running
	SDL_Helper * m_helper;
};

#endif