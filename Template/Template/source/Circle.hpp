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

#pragma once
#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include "Sprite.hpp"
#include "Settings.hpp"

class Circle : public Sprite
{
public:

	enum CIRCLE_TYPE
	{
		RED,
		BLUE
	};

private:

	CIRCLE_TYPE m_type;
	bool m_dragging;
	bool m_falling;
	float m_speed;

public:

	Circle(CIRCLE_TYPE _type, int _x, int _y, SDL_Helper * _helper, char * _sprite, int _sizePerFrameX, int _sizePerFrameY, Settings * _settings);
	~Circle();

	void Update() override;
	bool GetFalling();
	void SetFalling(bool _value);
	void SetSpeed(float _value);
};

#endif
