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
#include "Circle.hpp"
#include "Settings.h"

Circle::Circle(CIRCLE_TYPE _type, int _x, int _y, SDL_Helper * _helper, char * _sprite, int _sizePerFrameX, int _sizePerFrameY) : Sprite (_x, _y, _helper, _sprite, 1, _sizePerFrameX, _sizePerFrameY, 0, 0, false, false)
{
	this->m_type = _type;
	this->m_dragging = false;
	this->m_falling = false;
	this->m_speed = CIRCLE_DISPLACEMENT;
}


Circle::~Circle()
{

}

void Circle::UpdateDrag(touchPosition * _pos)
{
	if (!this->m_active)
	{
		return;
	}
	this->m_x = _pos->px - (m_sizePerFrameX / 2);
	this->m_y = _pos->py - (m_sizePerFrameY / 2);
}

void Circle::OnDrag(touchPosition  *_pos)
{
	if (!this->m_active)
	{
		return;
	}
	this->m_x = _pos->px - (m_sizePerFrameX / 2);
	this->m_y = _pos->py - (m_sizePerFrameX / 2);
}

void  Circle::OnDrop()
{
	if (!this->m_active)
	{
		return;
	}
	this->m_dragging = false;
}

void Circle::Update()
{
	if (!this->m_active)
	{
		return;
	}

	Sprite::Update();

	if (!this->m_dragging && this->m_falling)
	{
		this->m_y += m_speed;
	}	
	
}

void Circle::SetSpeed(float _value)
{
	this->m_speed = _value;
}

bool Circle::GetFalling()
{
	return this->m_falling;
}

void Circle::SetFalling(bool _value)
{
	this->m_falling = _value;
}