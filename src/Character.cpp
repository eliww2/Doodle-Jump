//
// Created by eliww on 4/18/2021.
//

#include "Character.h"

namespace doodleJump {
    
Character::Character() {}

void Character::Display() {
    
    ci::gl::drawSolidRect(ci::Rectf
        (vec2(position_x_, position_y_), vec2(position_x_ + kWidth, position_y_ + kHeight))
    );
    
    if (position_y_ > 800) {
        velocity_[1] = (float)kJumpHeight;
    }
    
}

void Character::OnCollision() {}

void Character::UpdateCharacter() {
    position_y_ -= velocity_[1];
    position_x_ += velocity_[0];
    velocity_[1] = velocity_[1] + (float)kAcceleration;
    // take in the key input and update x velocity accordingly
}


}