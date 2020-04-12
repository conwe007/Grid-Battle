#include "display.h"

// initialize SDL variables and create blank window
sdl_t* initializeSdl()
{
	// define sdl variables
	sdl_t* sdl = (sdl_t*)malloc(sizeof(sdl_t));
	sdl->window = NULL;
	sdl->surface = NULL;
	
	// set window name
	char window_name[WINDOW_NAME_SIZE];
	snprintf(window_name, sizeof(window_name), "Grid Battle");

	// initialize sdl
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "error: SDL could not initialize, SDL_Error: %s\n", SDL_GetError());
	} else
	{
		// create sdl window
		sdl->window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sdl->s_width, sdl->s_height, SDL_WINDOW_SHOWN);

		if(sdl->window == NULL)
		{
			fprintf(stderr, "error: window could not be created, SDL_Error: %s\n", SDL_GetError());
		} else
		{
			// get sdl surface and fill with black
			sdl->surface = SDL_GetWindowSurface(sdl->window);
			SDL_FillRect(sdl->surface, NULL, SDL_MapRGB(sdl->surface->format, 0x00, 0x00, 0x00));
		}
	}

	return sdl;
}