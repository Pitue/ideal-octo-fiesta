#pragma once

#include <vector>
#include <SDL.h>
#include "Vector.h"
#include "Sprite.h"
#include "Time.h"

namespace mh {
	struct Frame {
		SDL_Texture* texture;
		mh::Rect clip;
		bool clipped;
		Frame(SDL_Texture* _texture);
		Frame(SDL_Texture* _texture, mh::Rect _clip);
	};
	class AnimatedSprite {
		std::vector<Frame*> frames_;
		mh::Sprite sprite_;
		size_t index_;
		unsigned int frametime_;
		mh::Clock clock_;
		bool repeated_, playing_;

		void SetFrame(void);
	public:
		AnimatedSprite(unsigned int _frametime = 100 , bool _repeated = true,
									 bool _playing = false);

		void AddFrame(SDL_Texture* texture);
		void AddFrame(SDL_Texture* texture, mh::Rect clip);

		void Stop(void);
		void Resume(void);
		void Reset(void);
		void Draw(SDL_Renderer* renderer);

		inline mh::Sprite& Properties(void) { return sprite_; }
		inline bool& Repeated(void) { return repeated_; }
		inline unsigned int& Frametime(void) { return frametime_; }
	};
}

/*
		Frame(SDL_Texture* _texture) {
			clipped = false;
			texture = _texture;
		}
		Frame(SDL_Texture* _texture, mh::Rect _clip) {
			clipped = true;
			texture = _texture;
			clip = _clip;
		}

*/