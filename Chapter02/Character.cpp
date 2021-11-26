//
//  Character.cpp
//  Character
//
//  Created by Joseph Rhodes on 11/23/21.
//  Copyright © 2021 Sanjay Madhav. All rights reserved.
//

#include "Character.hpp"
#include "AnimSpriteComponent.h"
#include "Game.h"


Character::Character(Game *game)
    : Actor(game)
    , mRightSpeed(0.0f)
    , mDownSpeed(0.0f)
{
    auto *charSprite = new AnimSpriteComponent(this);

    std::vector<SDL_Texture*> anims;
    for (int index = 1; index <= 18; index++)
    {
        auto num = std::to_string(index);
        num = num.length() == 1 ? "0" + num : num;
        std::string name = "Assets/Character" + num + ".png";
        anims.push_back(game->GetTexture(name));
    }

    charSprite->SetSpriteAnimations({
        AnimSpriteComponent::SpriteAnimation("walk", 0, 5, true, 10.0f),
        AnimSpriteComponent::SpriteAnimation("jump", 6, 14, false, 20.0f),
        AnimSpriteComponent::SpriteAnimation("punch", 15, 17, false, 5.0f),
    });
    charSprite->SetAnimTextures(anims);
    charSprite->SetCurrentAnimation("walk");
}

void Character::UpdateActor(float deltaTime)
{
    Actor::UpdateActor(deltaTime);
    // Update position based on speeds and delta time
    Vector2 pos = GetPosition();
    pos.x += mRightSpeed * deltaTime;
    pos.y += mDownSpeed * deltaTime;
    // Restrict position to left half of screen
    if (pos.x < 25.0f)
    {
        pos.x = 25.0f;
    }
    else if (pos.x > 500.0f)
    {
        pos.x = 500.0f;
    }
    if (pos.y < 25.0f)
    {
        pos.y = 25.0f;
    }
    else if (pos.y > 743.0f)
    {
        pos.y = 743.0f;
    }
    SetPosition(pos);
}

void Character::ProcessKeyboard(const uint8_t* state)
{
    mRightSpeed = 0.0f;
    mDownSpeed = 0.0f;
    // right/left
    if (state[SDL_SCANCODE_D])
    {
        mRightSpeed += 250.0f;
    }
    if (state[SDL_SCANCODE_A])
    {
        mRightSpeed -= 250.0f;
    }
    // up/down
    if (state[SDL_SCANCODE_S])
    {
        mDownSpeed += 300.0f;
    }
    if (state[SDL_SCANCODE_W])
    {
        mDownSpeed -= 300.0f;
    }
}
