#pragma once
#ifndef _SCENE_HPP_
#define _SCENE_HPP_
		
#include "SDL_Helper.hpp"
#include <switch.h>

// Base Class.
class Scene
{

protected:
	SDL_Helper * m_helper;
	bool m_changeScene;

public:
	Scene() {};																	// Constructor
	~Scene() { };																// Destructor
	virtual void Start(SDL_Helper * m_helper) {};													// initialize
	virtual void Draw() { };		// Draw
	virtual void CheckInputs(u64 kDown) {};												// CheckInput
	virtual void Update() {};													// Update
	virtual void NextScene() {};													// Update
};

#endif