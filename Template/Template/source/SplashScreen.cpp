/* This file is part of Evolution Saved Me NX!

Copyright (C) 2018/2019 Manuel Rodríguez Matesanz
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

#include "SplashScreen.hpp"
#include "SceneManager.hpp"
#include "Colors.h"
#include "Filepaths.h"

// * Constructor 
SplashScreen::SplashScreen() : Scene()
{
}

// * Destructor
SplashScreen::~SplashScreen()
{
	//m_SFX->stop();
	//delete m_SFX;
	//m_helper->SDL_DestroyTexture(m_splash);
}

// * Start - We initialize the variables
void SplashScreen::Start(SDL_Helper * helper)
{
	this->m_helper = helper;
	m_scTimer = 0;
	m_splashOpacity = 0;
	m_sfxSplash = false;
	m_changeScene = false;
	m_helper = helper;
	m_helper->SDL_LoadImage(&m_splash, IMG_SPLASHSCREEN);
	m_splashOpeningState = OPENING;
	//m_SFX = new sound(SND_SFX_SPLASH, 2, false);
}

// * Draw the images every frame
void SplashScreen::Draw()
{
	m_helper->SDL_DrawImageOpacity(m_splash, 0, 0, m_splashOpacity);
}

// * Update game stuff (SplashScreen opacity)
void SplashScreen::Update()
{
	switch (m_splashOpeningState)
	{
	case OPENING:

		m_splashOpacity += 3;

		if (m_splashOpacity >= 255)
		{
			m_splashOpacity = 255;
			m_splashOpeningState = STAY;

			if (!m_sfxSplash)
			{
				m_sfxSplash = true;
				//m_SFX->play();
			}
		}

		break;
	case STAY:

		m_scTimer += 5;

		if (m_scTimer >= 300)
		{
			m_splashOpeningState = ENDING;
		}

		break;
	case ENDING:

		m_splashOpacity -= 3;

		if (m_splashOpacity <= 0)
		{
			m_changeScene = true;
		}
		break;
	}

	if (m_changeScene)
	{
		NextScene();
	}

}

// * We go to the next scene = TitleScreen
void SplashScreen::NextScene()
{
	SceneManager::Instance()->setActualScene(SceneManager::TITLE);
	delete(this);
}

// * We check the inputs
void SplashScreen::CheckInputs(u64 kDown)
{
	if (kDown & KEY_A)
	{
		this->m_changeScene = true;
	}
}