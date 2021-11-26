//
//  TileMapComponent.hpp
//  TileMapComponent
//
//  Created by Joseph Rhodes on 11/24/21.
//  Copyright © 2021 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "SpriteComponent.h"
#include <vector>
#include <string>
#include "Math.h"


class TileMapComponent : public SpriteComponent
{
public:
    TileMapComponent(class Actor *owner, const std::string& tileMapFileName, int drawOrder = 11);
    void Draw(SDL_Renderer* renderer) override;
    void SetScreenSize(const Vector2& size) { screenSize = size; }

private:
    std::vector<std::vector<int>> tileMap;
    Vector2 screenSize;
};

