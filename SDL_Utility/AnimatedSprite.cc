#include "AnimatedSprite.h"

mh::Frame::Frame(SDL_Texture* _texture) {
	clipped = false;
	texture = _texture;
}
mh::Frame::Frame(SDL_Texture* _texture, mh::Rect _clip) {
	clipped = true;
	texture = _texture;
	clip = _clip;
}

void mh::AnimatedSprite::SetFrame(void) {
	mh::Frame& frame = *frames_.at(index_);
	sprite_.set_texture(frame.texture);
	sprite_.Clipped() = frame.clipped;
	sprite_.Clip() = frame.clip;
}

mh::AnimatedSprite::AnimatedSprite(unsigned int _frametime /*= 100*/,
	bool _repeated /*= true*/,
	bool _playing /*= false*/) : frametime_{ _frametime },
													 repeated_{ _repeated },
													 playing_{ _playing },
													 index_{ 0 }{}

void mh::AnimatedSprite::AddFrame(SDL_Texture* texture) {
	frames_.push_back(new Frame(texture));
}
void mh::AnimatedSprite::AddFrame(SDL_Texture* texture, mh::Rect clip) {
	frames_.push_back(new Frame(texture, clip));
}

void mh::AnimatedSprite::Stop(void) {
	playing_ = false;
}
void mh::AnimatedSprite::Resume(void) {
	playing_ = true;
}
void mh::AnimatedSprite::Reset(void) {
	clock_.Restart();
}
void mh::AnimatedSprite::Draw(SDL_Renderer* renderer) {
	if (clock_.GetElapsedTime().AsMilliseconds<unsigned int>() >= frametime_ && playing_) {
		if (index_ + 1 >= frames_.size()) {
			if (repeated_) {
				index_ = 0;
			}
			else {
				index_ = frames_.size() - 1;
			}
		}
		index_++;
		SetFrame();
		clock_.Restart();
	}
	sprite_.Draw(renderer);
}