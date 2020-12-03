#ifndef SDL_UTILITY_H
#define SDL_UTILITY_H

#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "Vector.h"
#include "Sprite.h"

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
				if (renderer != NULL) {
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					err = 0;
				}
			}
		}
		~SDL_Container() {
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
		}
		SDL_Container(const SDL_Container& obj) = delete;
		SDL_Container& operator =(const SDL_Container&) = delete;
		operator bool() { return err == 0; }
	};
	bool LoadSpriteSheet(SDL_Renderer* renderer, const char* filename, mh::Point entry, mh::Vector2i size, std::vector<std::vector<mh::Sprite>>* result) {
		SDL_Texture* sheet = IMG_LoadTexture(renderer, filename);
		if (sheet == NULL) return false;

		mh::Vector2i sheet_size;
		SDL_QueryTexture(sheet, NULL, NULL, &sheet_size.x_, &sheet_size.y_);
		mh::Vector2i sprite_size((sheet_size.x_ - entry.x_) / size.y_, (sheet_size.y_ - entry.y_) / size.y_);

		for (int x = 0; x < size.x_; x++) {
			for (int y = 0; y < size.y_; y++) {
				mh::Sprite temp(sheet, mh::Rect(entry.x_, entry.y_, sprite_size.x_, sprite_size.y_));
				result->at(x).at(y) = temp;
			}
		}
		return true;
	}
}

#endif