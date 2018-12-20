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
#include "SDL_FontCache.h"

#define WHITE                 FC_MakeColor(255, 255, 255, 255)
#define C_RED                 FC_MakeColor(255, 0, 0, 128)
#define RAY_RED                 FC_MakeColor(255, 0, 0, 0)
#define BLACK_BG              FC_MakeColor(48, 48, 48, 255)
#define STATUS_BAR_LIGHT      FC_MakeColor(37, 79, 174, 255)
#define STATUS_BAR_DARK       FC_MakeColor(38, 50, 56, 255)
#define MENU_BAR_LIGHT        FC_MakeColor(51, 103, 214, 255)
#define MENU_BAR_DARK         FC_MakeColor(55, 71, 79, 255)
#define BLACK                 FC_MakeColor(0, 0, 0, 255)
#define SELECTOR_COLOUR_LIGHT FC_MakeColor(241, 241, 241, 255)
#define SELECTOR_COLOUR_DARK  FC_MakeColor(76, 76, 76, 255)
#define TITLE_COLOUR          FC_MakeColor(30, 136, 229, 255)
#define TITLE_COLOUR_DARK     FC_MakeColor(0, 150, 136, 255)
#define TEXT_MIN_COLOUR_LIGHT FC_MakeColor(32, 32, 32, 255)
#define TEXT_MIN_COLOUR_DARK  FC_MakeColor(185, 185, 185, 255)
#define BAR_COLOUR            FC_MakeColor(200, 200, 200, 255)