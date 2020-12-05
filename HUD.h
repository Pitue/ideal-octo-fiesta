#pragma once
#include "Section.h"
#include "main_include.h"
class HUD :
    public Section {

public:
  void Draw(SDL_Renderer* renderer) override;
  void Update() override;
  void HandleInput(SDL_Event& e) override;
};

