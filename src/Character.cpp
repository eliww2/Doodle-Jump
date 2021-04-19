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

void Character::UpdateCharacter(const std::vector<Platform>& platforms) {

    // checks if the character is coming down on a platform and makes it bounce 
    if (velocity_[1] <= 0) {
        for (Platform current_platform : platforms) {
            if (hit_box_.intersects(current_platform.platform_box_) && (position_y_ + kHeight) <= current_platform.bottom_position_) {
                velocity_[1] = (float)kJumpHeight;
                break;
            }
        }
    }
    
    //Constant change in character based on velocity and acceleration
    position_y_ -= velocity_[1];
    position_x_ += velocity_[0];
    velocity_[1] = velocity_[1] + kAcceleration;
    
    // slows down the x velocity to make it seem like there is air resistance
    if (velocity_[0] < 0) {
        velocity_[0] += kAirResistance;
    } else if (velocity_[0] != 0) {
        velocity_[0] -= kAirResistance;
    }
    
    //For testing right now TODO: Remove
    if (position_y_ > 800) {
        velocity_[1] = (float)kJumpHeight;
    }
}

void Character::ChangeHorizontalVel(float change) {
    if (velocity_[0] > -9 && velocity_[0] < 9) {
        if ((velocity_[0] > 0 && change < 0) || (velocity_[0] < 0 && change > 0)) {
            velocity_[0] = 0;
            velocity_[0] += change;
        }
        velocity_[0] += change;
    }
}

}