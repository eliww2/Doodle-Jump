//
// Created by eliww on 4/18/2021.
//

#include "Character.h"

namespace doodleJump {
    
Character::Character() {}

void Character::Display() {
    ci::gl::color(ci::Color("green"));
    hit_box_ = ci::Rectf (vec2(position_x_, position_y_), vec2(position_x_ + kWidth, position_y_ + kHeight));
    ci::gl::drawSolidRect(hit_box_);
}

void Character::OnCollision() {}

void Character::UpdateCharacter(std::vector<Platform> platforms) {
    position_y_ -= velocity_[1];
    position_x_ += velocity_[0];
    velocity_[1] = velocity_[1] + (float)kAcceleration;
    // take in the key input and update x velocity accordingly
    
    if (velocity_[1] <= 0) {
        for (Platform current_platform : platforms) {
            if (hit_box_.intersects(current_platform.platform_box_)) {
                velocity_[1] = (float)kJumpHeight;
            }
        }
    }
    
    if (position_y_ > 800) {
        velocity_[1] = (float)kJumpHeight;
    }
}


}