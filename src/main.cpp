#include <iostream>

#include <SDL.h>

int main(int argc, char **argv)
{
	
	// intialize sdl subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialize the SDL2 library\n";

		return -1;
	}

	SDL_Window *window = SDL_CreateWindow(
		"title",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		600, 400,
		SDL_WINDOW_SHOWN
	);

    if(!window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        return -1;
    }

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);
	
	// SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	// SDL_SetRenderDrawColor(renderer, 0,255,0,255);

	// SDL_RenderClear(renderer);

	// SDL_RenderPresent(renderer);

	// SDL_Delay(3000);

	return 0;
}