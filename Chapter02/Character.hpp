//
//  Character.hpp
//  Character
//
//  Created by Joseph Rhodes on 11/23/21.
//  Copyright © 2021 Sanjay Madhav. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include "Actor.h"

class Character : public Actor
{
public:
    Character(class Game* game);
    void UpdateActor(float deltaTime) override;
    void ProcessKeyboard(const uint8_t* state);
    float GetRightSpeed() const { return mRightSpeed; }
    float GetDownSpeed() const { return mDownSpeed; }

private:
    float mRightSpeed;
    float mDownSpeed;
};

#endif /* Character_hpp */
