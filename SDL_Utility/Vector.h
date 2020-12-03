#pragma once

#include <SDL.h>

namespace mh {
	template<typename T> class Vector2 {
	public:
		T x_, y_;
		Vector2() : x_{ static_cast<T>(0) }, y_{ static_cast<T>(0) } {}
		Vector2(T x, T y) : x_{ x }, y_{ y } {}
		template <typename Tn> Vector2<Tn> Convert(void) {
			return Vector2<Tn>(static_cast<Tn>(x_), static_cast<Tn>(y_));
		}
	};

	typedef Vector2<int> Vector2i;
	typedef Vector2<unsigned int> Vector2u;
	typedef Vector2<float> Vector2f;
	typedef Vector2<double> Vector2d;
	typedef Vector2<int> Point;

	class Rect : public SDL_Rect {
	public:
		Rect(int x, int y, int w, int h) {
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;
		}
		Rect() {
			x = y = w = h = 0;
		}
	};
}

