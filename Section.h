#pragma once

#include "main_include.h"

class Section {
protected:
	int err;
public:
	Section(): err{0} {}
	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual void Update() = 0;
	virtual void HandleInput(SDL_Event& e) = 0;
	operator bool() { return err == 0; }
};

