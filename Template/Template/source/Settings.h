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
#ifndef _SETTINGS_HPP_
#define _SETTINGS_HPP_

#define PROJECT_NAME "Whats In The Box"

// Screen size: 1280x720
#define SWITCH_SCREEN_WIDTH 1280
#define SWITCH_SCREEN_HEIGHT 720

// Version of our Homebrew and if we want to set a debugmode for us. 
// We can disable it from here.
#define VERSION "1.0"
#define DEBUG_MODE false

// Time wait in loading screen in seconds
#define LOADING_DELAY 2 

#define DELTA_TIME_REDUCTION 2 // HALF TIME -> SDL_TICKS/(100*reduction)

#define MIN_POS_RED 40
#define MIN_POS_BLUE 1150

#define CIRCLE_DISPLACEMENT 10
#endif