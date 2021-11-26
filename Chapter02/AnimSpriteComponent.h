// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "SpriteComponent.h"
#include <vector>
#include <string>

class AnimSpriteComponent : public SpriteComponent
{
public:
    struct SpriteAnimation
    {
        SpriteAnimation()=default;
        SpriteAnimation(std::string name, uint8_t start, uint8_t end, bool repeats, float fps)
            : name(name)
            , start(start)
            , end(end)
            , repeats(repeats)
            , fps(fps) {};

        std::string name { "" };
        uint8_t start { 0 };
        uint8_t end { 0 };
        bool repeats { false };
        float fps { 0.0f };

        uint8_t length() { return end - start; }
        bool isEmpty() { return start == 0 && end == 0; };
    };

    AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
	// Update animation every frame (overridden from component)
	void Update(float deltaTime) override;
	// Set the textures used for animation
	void SetAnimTextures(const std::vector<SDL_Texture*>& textures);
	// Set/get the animation FPS
	float GetAnimFPS() const { return mAnimFPS; }
	void SetAnimFPS(float fps) { mAnimFPS = fps; }

    void SetSpriteAnimations(const std::vector<SpriteAnimation> &animations);
    void SetCurrentAnimation(const std::string animationName);
private:
	// All textures in the animation
	std::vector<SDL_Texture*> mAnimTextures;
	// Current frame displayed
	float mCurrFrame;
	// Animation frame rate
	float mAnimFPS;

    // Index range of animated textures
    std::vector<SpriteAnimation> mSpriteAnimations;
    SpriteAnimation *mCurrentAnimation;
};
