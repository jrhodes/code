//
//  TileMapComponent.cpp
//  TileMapComponent
//
//  Created by Joseph Rhodes on 11/24/21.
//  Copyright © 2021 Sanjay Madhav. All rights reserved.
//

#include "TileMapComponent.hpp"
#include "CSVReader.hpp"
#include <iostream>

TileMapComponent::TileMapComponent(Actor *owner, const std::string &tileMapFileName, int drawOrder)
    : SpriteComponent(owner, drawOrder)
{
    auto reader = CSVReader(tileMapFileName);
    std::vector<std::string> tokens;

    while (reader.readLine(tokens))
    {
        std::vector<int> lineMap;
        for (auto token : tokens)
        {
            int num = std::stoi(token);
            lineMap.emplace_back(num);
        }

        tileMap.emplace_back(lineMap);
    }
}

void TileMapComponent::Draw(SDL_Renderer *renderer)
{
    if (!mTexture)
        return;

    int yPos = 0;

    for (auto line : tileMap)
    {
        int xPos = 0;

        for (auto tile : line)
        {
            if (tile != -1)
            {
                SDL_Rect srcRect = { (tile % 8) * 32, (tile / 8) * 32, 32, 32 };
                SDL_Rect destRect = { xPos, yPos, 32, 32 };

                SDL_RenderCopyEx(renderer, mTexture, &srcRect, &destRect,
                                 0, nullptr, SDL_FLIP_NONE);
            }

            xPos += 32;

            if (xPos >= screenSize.x)
                break;
        }

        yPos += 32;

        if (yPos >= screenSize.y)
            break;
    }
}
