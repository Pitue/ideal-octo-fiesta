#ifndef SDL_UTILITY_H
#define SDL_UTILITY_H

#include <SDL.h>

#include "Vector.h"

namespace mh {
	struct SDL_Container {
		SDL_Window* window;
		SDL_Renderer* renderer;
		int err;

		SDL_Container(const char* window_title, Rect window_dimension, Uint32 window_flags, Uint32 renderer_flags)
			: err{ 1 }, window{ NULL }, renderer{ NULL } {
			window = SDL_CreateWindow(window_title, window_dimension.x, window_dimension.y,
																window_dimension.w, window_dimension.h, window_flags);
			if (window != NULL) {
				renderer = SDL_CreateRenderer(window, -1, renderer_flags);
				if (renderer != NULL) err = 0;
			}
		}
		~SDL_Container() {
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
		}
		SDL_Container(const SDL_Container& obj) = delete;
		SDL_Container(const SDL_Container&& const other) = delete;
		operator bool() { return err == 0; }
	};
}

#endif