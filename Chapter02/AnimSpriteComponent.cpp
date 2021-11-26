// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "AnimSpriteComponent.h"
#include "Math.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, mCurrFrame(0.0f)
	, mAnimFPS(24.0f)
    , mCurrentAnimation(nullptr)
{
}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

    if (mAnimTextures.empty())
    {
        return;
    }

    float wrapSize = mAnimTextures.size();
    float resetSize = wrapSize;
    bool repeat = true;
    float fps = mAnimFPS;

    if (mCurrentAnimation != nullptr && !mCurrentAnimation->isEmpty())
    {
        if (mCurrFrame < mCurrentAnimation->start)
        {
            mCurrFrame = mCurrentAnimation->start;
        }

        wrapSize = mCurrentAnimation->end + 1;
        resetSize = mCurrentAnimation->length();
        repeat = mCurrentAnimation->repeats;
        fps = mCurrentAnimation->fps;
    }

    // Update the current frame based on frame rate
    // and delta time
    mCurrFrame += fps * deltaTime;

    // Wrap current frame if needed
    while (mCurrFrame >= wrapSize)
    {
        if (repeat)
            mCurrFrame -= resetSize;
        else
            mCurrFrame = wrapSize - 1;
    }

    // Set the current texture
    SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures)
{
	mAnimTextures = textures;
	if (mAnimTextures.size() > 0)
	{
		// Set the active texture to first frame
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}

void AnimSpriteComponent::SetSpriteAnimations(const std::vector<SpriteAnimation> &animations)
{
    mSpriteAnimations = animations;

    if (!mSpriteAnimations.empty())
    {
        mCurrentAnimation = &mSpriteAnimations.front();
    }
}

void AnimSpriteComponent::SetCurrentAnimation(const std::string animationName)
{
    for (std::size_t index = 0; index < mSpriteAnimations.size(); index++)
    {
        auto *animation = &mSpriteAnimations[index];

        if (animation->name == animationName)
        {
            mCurrFrame = 0.0f;
            mCurrentAnimation = animation;
            break;
        }
    }
}
