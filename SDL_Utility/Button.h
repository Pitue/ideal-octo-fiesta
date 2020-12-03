#include "Sprite.h"
#include "Vector.h"

namespace mh {

	class Button : public mh::Sprite {
	public:
		bool HasFocus(mh::Point mouse_pos) {
			if ((mouse_pos.x_ >= position_.x_ && mouse_pos.x_ <= (size_.x_ + position_.x_))
				&& (mouse_pos.y_ >= position_.y_ && mouse_pos.y_ <= (size_.y_ + position_.y_))) {
				return true;
			}
			return false;
		}
	};

}