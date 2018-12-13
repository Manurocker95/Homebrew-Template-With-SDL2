/* This file is part of Manurocker's Template!

Copyright (C) 2017 Manuel Rodríguez Matesanz
>    This program is free software: you can redistribute it and/or modify
>    it under the terms of the GNU General Public License as published by
>    the Free Software Foundation, either version 3 of the License, or
>    (at your option) any later version.
>
>    This program is distributed in the hope that it will be useful,
>    but WITHOUT ANY WARRANTY; without even the implied warranty of
>    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
>    GNU General Public License for more details.
>
>    You should have received a copy of the GNU General Public License
>    along with this program.  If not, see <http://www.gnu.org/licenses/>.
>    See LICENSE for information.
*/

#pragma once
#ifndef _SPLASH_SCREEN_H_
#define _SPLASH_SCREEN_H_

#include "Scene.hpp"

class SplashScreen : public Scene
{

public:

	enum SPLASH_STATE { OPENING, STAY, ENDING };

	SplashScreen();						// Constructor
	~SplashScreen();

	void Start(SDL_Helper * helper) override;
	void Draw() override;
	void CheckInputs(u64 kDown) override;
	void Update() override;
	void NextScene() override;
private:

	int m_splashOpacity, m_scTimer;
	bool m_sfxSplash;
	
private:
	SDL_Texture * m_splash;
	//sound * m_SFX;
	SPLASH_STATE m_splashOpeningState;
};

#endif