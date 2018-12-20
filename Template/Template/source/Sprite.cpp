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

#include "Sprite.hpp"
#include "Filepaths.h"
#include "Settings.h"

Sprite::Sprite(int _x, int _y, SDL_Helper * _helper, char * _sprite, int m_numFrames, int _sizePerFrameX, int _sizePerFrameY, int _currentFrameX, int _currentFrameY, bool _multipleFrames, bool _animated)
{
	this->m_active = true;
	this->m_x = _x;
	this->m_y = _y;
	this->m_animated = _animated;
	this->m_sizePerFrameX = _sizePerFrameX;
	this->m_sizePerFrameY = _sizePerFrameY;
	this->m_multipleFrames = _multipleFrames;
	this->m_currentFrameX = _currentFrameX;
	this->m_currentFrameY = _currentFrameY;
	this->m_numFrames = m_numFrames;

	_helper->SDL_LoadImage(&this->m_sprite, _sprite);
}

void Sprite::Draw(SDL_Helper * _helper)
{
	if (this->m_active)
	{
		if (this->m_multipleFrames)
			_helper->SDL_DrawImageRect(this->m_sprite, this->m_x, this->m_y, this->m_currentFrameX * this->m_sizePerFrameX, this->m_currentFrameY * this->m_sizePerFrameY, this->m_sizePerFrameX, this->m_sizePerFrameY);
		else
			_helper->SDL_DrawImage(this->m_sprite, this->m_x, this->m_y);
	}
}

void Sprite::Update()
{
	if (this->m_active)
	{
		if (this->m_animated && this->m_multipleFrames)
		{
			Uint32 ticks = SDL_GetTicks();
			this->m_currentFrameX = (ticks / (100 * DELTA_TIME_REDUCTION)) % this->m_numFrames;
		}
	}
}

void Sprite::MoveToCoord(int _x, int _y)
{
	this->m_x = _x;
	this->m_y = _y;
}

void Sprite::MoveX(int _value)
{
	if ((_value > 0 && m_x + _value <= SWITCH_SCREEN_WIDTH) || (_value < 0 && m_x + _value >= 0))
		this->m_x += _value;
}

void Sprite::MoveY(int _value)
{
	if ((_value > 0 && this->m_y + _value <= SWITCH_SCREEN_HEIGHT) || (_value < 0 && this->m_y + _value >= 0))
		this->m_y += _value;
}

SDL_Texture * Sprite::GetSprite()
{
	return this->m_sprite;
}

void Sprite::SetSprite(SDL_Texture * _sprite)
{
	this->m_sprite = _sprite;
}


void Sprite::SetX(int _value)
{
	this->m_x = _value;
}

int Sprite::GetX()
{
	return this->m_x;
}

void Sprite::SetY(int _value)
{
	this->m_y = _value;
}

int Sprite::GetY()
{
	return this->m_y;
}

void Sprite::End(SDL_Helper * _helper)
{
	if (this->m_sprite != NULL)
		_helper->SDL_DestroyTexture(this->m_sprite);
}


void Sprite::SetNumFrames(int _value)
{
	this->m_numFrames = _value;
	this->m_currentFrameX = 0;
}

int Sprite::GetNumFrames()
{
	return this->m_numFrames;
}

void Sprite::SetFrameSize(int _value, bool _xAxis)
{
	if (_xAxis)
		this->m_sizePerFrameX = _value;
	else
		this->m_sizePerFrameY = _value;
}

int Sprite::GetFrameSize(bool _xAxis)
{
	if (_xAxis)
		return this->m_sizePerFrameX;
	else
		return this->m_sizePerFrameY;
}

bool Sprite::Touched(touchPosition * _touch)
{
	return (_touch->px > this->m_x && _touch->px < this->m_x + this->m_sizePerFrameX) && (_touch->py > this->m_y && _touch->py < this->m_y + this->m_sizePerFrameY);
}


bool Sprite::IsActive()
{
	return this->m_active;
}

void Sprite::SetActive(bool _value)
{
	this->m_active = _value;
}