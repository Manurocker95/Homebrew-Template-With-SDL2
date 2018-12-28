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

#include "GameScreen.hpp"
#include "SceneManager.hpp"
#include "Filepaths.h"
#include "Colors.h"

GameScreen::GameScreen(Settings * _settings) : Scene(_settings)
{
	this->m_settings = _settings;
	this->m_changeScene = false;
	this->m_dragging = false;
	this->m_circleDisplacement = _settings->m_circleDisplacement;
}

GameScreen::~GameScreen()
{
	this->m_music->End(this->m_helper);
	delete(this->m_music);

	this->m_buttonTapSFX->End(this->m_helper);
	delete(this->m_buttonTapSFX);

	this->m_circle->End(this->m_helper);
	delete(this->m_circle);

	this->m_background->End(this->m_helper);
	delete(this->m_background);

	this->m_text->End(this->m_helper);
	delete(this->m_text);
}

void GameScreen::Start(SDL_Helper * helper)
{

	this->m_helper = helper;
	this->m_background = new Sprite(0, 0, helper, IMG_BACKGROUND, 1, 1, SWITCH_SCREEN_WIDTH, SWITCH_SCREEN_HEIGHT, 0, 0, false, false, 1);

	this->m_text = new Text(helper, "Game screen!", 525, 670, 15, true, FONT_NORMAL, C_BLACK);

	this->m_circle = new Circle(Circle::CIRCLE_TYPE::BLUE, 200, 200, this->m_helper, IMG_BLUE_CIRCLE, 94, 94, this->m_settings);
	
	this->m_buttonTapSFX = new SfxSound(this->m_helper, SND_SFX_TAP, false, 2);
	this->m_music = new MusicSound(this->m_helper, SND_BGM_TITLE, true, 1);
	this->m_music->Play(this->m_helper);

	if (this->m_settings->m_muted)
		this->m_helper->SDL_PauseMusic();

}

void GameScreen::Draw()
{
	this->m_background->Draw(this->m_helper);

	this->m_circle->Draw(this->m_helper);

	this->m_text->Draw(this->m_helper);
}

void GameScreen::Update()
{
	this->m_circle->Update();

	if (this->m_changeScene)
		NextScene();
}

void GameScreen::CheckInputs(u64 kDown, u64 kHeld, u64 kUp)
{
	if (kHeld & KEY_TOUCH)
	{
		u32 i;
		hidTouchRead(&this->touch, i);

		if (this->m_dragging)
		{
			this->m_circle->UpdateDrag(&this->touch);
		}
		else
		{
			if (this->m_circle->Touched(&this->touch))
			{
				this->m_buttonTapSFX->Play(this->m_helper);
				this->m_dragging = true;
				this->m_circle->OnDrag(&this->touch);
			}
		}
	}
	else if (kUp & KEY_TOUCH)
	{
		u32 i;
		hidTouchRead(&this->touch, i);

		if (this->m_dragging)
		{
			this->m_circle->OnDrop();
		}

		this->m_dragging = false;
	}

	if (!this->m_dragging)
	{
		if (kHeld & KEY_RIGHT)
			this->m_circle->MoveX(this->m_circleDisplacement);

		if (kHeld & KEY_LEFT)
			this->m_circle->MoveX(-this->m_circleDisplacement);

		if (kHeld & KEY_UP)
			this->m_circle->MoveY(-this->m_circleDisplacement);

		if (kHeld & KEY_DOWN)
			this->m_circle->MoveY(this->m_circleDisplacement);

		if (kDown & KEY_R)
			this->m_circle->SetFalling(true);

		if (kDown & KEY_L)
			this->m_circle->SetFalling(false);
	}

	if (kDown & KEY_PLUS)
	{
		m_changeScene = true;
	}
}

// * We go to the next scene = GameScreen
void GameScreen::NextScene()
{
	SceneManager::Instance()->LoadScene(SceneManager::TITLE);
}

