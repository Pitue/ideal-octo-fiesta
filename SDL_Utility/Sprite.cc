#include "Sprite.h"

mh::Sprite::Sprite() : texture_{ nullptr }, clipped_{ false }{}
mh::Sprite::Sprite(SDL_Texture* texture) : texture_{ texture }, clipped_{ true } {
	SDL_QueryTexture(texture, NULL, NULL, &size_.x_, &size_.y_);
}
mh::Sprite::Sprite(SDL_Texture* texture, mh::Rect clip): texture_{texture}, clip_(clip), clipped_{true} {
	SDL_QueryTexture(texture, NULL, NULL, &size_.x_, &size_.y_);
}

void mh::Sprite::Draw(SDL_Renderer* renderer) {
	mh::Rect dest(position_.x_, position_.y_, size_.x_, size_.y_);
	if (clipped_) {
		SDL_RenderCopy(renderer, texture_, &clip_, &dest);
	}
	else {
		SDL_RenderCopy(renderer, texture_, NULL, &dest); 
	}
}

SDL_Texture* mh::Sprite::get_texture(void) {
	return texture_;
}
void mh::Sprite::set_texture(SDL_Texture* texture, bool resize/* = false*/) {
	texture_ = texture;
	if (resize) {
		SDL_QueryTexture(texture_, NULL, NULL, &size_.x_, &size_.y_);
	}
}

mh::Vector2i& mh::Sprite::Size(void) { return size_; }
mh::Point& mh::Sprite::Position(void) { return position_; }
mh::Rect& mh::Sprite::Clip(void) { return clip_; }
bool& mh::Sprite::Clipped(void) { return clipped_; }