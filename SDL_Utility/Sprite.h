#pragma once
#include <SDL.h>
#include "Vector.h"
namespace mh {
class Sprite {
	SDL_Texture* texture_;
	mh::Vector2i size_;
	mh::Point position_;
	mh::Rect clip_;
	bool clipped_;

public:
	Sprite();
	Sprite(SDL_Texture* texture);
	Sprite(SDL_Texture* texture, mh::Rect clip);

	void Draw(SDL_Renderer* renderer);

	SDL_Texture*& Texture(void);
	mh::Vector2i& Size(void);
	mh::Point& Position(void);
	mh::Rect& Clip(void);
	bool& Clipped(void);
};
}

