#ifndef __DISPLAY_H
#define __DISPLAY_H

#include "constants.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	SDL_Window* window;
	SDL_Surface* surface;
	int s_width;
	int s_height;
} sdl_t;

sdl_t* initializeSdl(); // initialize SDL variables and create blank window

#endif