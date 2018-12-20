/* This file is part of Manurocker95's Template!

this is made for my tutorial: https://gbatemp.net/threads/tutorial-setting-up-visual-studio-2017-environment-for-nintendo-switch-homebrew-development.525977/#post-8439059

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

#include "LoadingScreen.hpp"

#include "Filepaths.h"
#include "Settings.h"
#include "Colors.h"

LoadingScreen::LoadingScreen(SceneManager::SCENES  _nextScene) : Scene()
{
	this->m_nextScene = _nextScene;
	this->m_loading = true;
	this->m_lastTime = 0;
	this->m_currentTime = 0;
	this->m_delay = 0;
	this->m_changeScene = false;
}

LoadingScreen::~LoadingScreen()
{
	m_helper->SDL_DestroyTexture(m_loadingBG);
	delete(this->m_loadingText);
}

void LoadingScreen::Start(SDL_Helper * helper)
{
	this->m_helper = helper;
	this->m_loadingText = new Text(helper, "Loading...", 1100, 670, 15, false, "", BLACK);	// We wanna use roboto instead of custom font here
	this->m_helper->SDL_LoadImage(&this->m_loadingBG, IMG_BG_LOADING);
	this->m_helper->SDL_PauseMusic();
}

void LoadingScreen::Draw()
{
	this->m_helper->SDL_DrawImage(this->m_loadingBG, 0, 0);
	this->m_loadingText->Draw(m_helper);
}

void LoadingScreen::Update()
{
	if (this->m_loading)
	{
		this->m_currentTime = SDL_GetTicks();

		if (this->m_currentTime > m_lastTime + 1000)
		{
			++this->m_delay;
			if (this->m_delay >= LOADING_DELAY)
			{
				this->m_loading = false;
				this->m_changeScene = true;
			}
			else
			{
				this->m_lastTime = this->m_currentTime;
			}				
		}
	}

	if (this->m_changeScene)
		NextScene();
}

void LoadingScreen::CheckInputs(u64 kDown, u64 kHeld, u64 kUp)
{
	// While we are in Loading Screen we DON'T need any input 
	//if (kDown & KEY_A)
	//	SceneManager::Instance()->SetActualScene(m_nextScene);
}

// * We go to the next scene = GameScreen
void LoadingScreen::NextScene()
{
	m_helper->SDL_SetMusicVolume(MIX_MAX_VOLUME);
	SceneManager::Instance()->SetActualScene(this->m_nextScene);
}

