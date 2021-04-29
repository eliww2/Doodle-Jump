//
// Created by eliww on 4/18/2021.
//

#include "Character.h"

namespace doodleJump {
    
Character::Character() {}

void Character::Display() {
    hit_box_ = ci::Rectf (vec2(position_x_, position_y_), vec2(position_x_ + (float)kWidth, position_y_ + (float)kHeight));
    ci::gl::draw(kSkinLeft, hit_box_);
    std::string current_score = "Score: " + std::to_string((int)(score / 4));
    ci::gl::drawString(current_score, vec2(10, 10), ci::Color("black"), ci::Font("arial", 24));
}

void Character::UpdateCharacter(std::vector<Platform>& platforms) {

    // checks if the character is coming down on a platform and makes it bounce 
    if (velocity_[1] <= 0) {
        for (Platform& current_platform : platforms) {
            auto check = ci::Rectf(
                    vec2(current_platform.left_position_, current_platform.top_position_), 
                    vec2(current_platform.right_position_, current_platform.bottom_position_)
            );
            if (hit_box_.intersects(check) && (position_y_ + (float)kHeight) <= current_platform.bottom_position_) {
                velocity_[1] = (float)kJumpHeight;
                break;
            }
        }
    }
    
    for (Platform& current_platform : platforms) {
        current_platform.bottom_position_ += velocity_[1];
        current_platform.top_position_ += velocity_[1];
    }

    //Constant change in character based on velocity and acceleration
    position_x_ += velocity_[0];
    velocity_[1] = velocity_[1] + kAcceleration;
    
    // slows down the x velocity to make it seem like there is air resistance
    if (velocity_[0] < 0) {
        if (-velocity_[0] < kAirResistance) {
            velocity_[0] = 0;
        } else {
            velocity_[0] += kAirResistance;
        }
    } else if (velocity_[0] != 0) {
        if (velocity_[0] < kAirResistance) {
            velocity_[0] = 0;
        } else {
            velocity_[0] -= kAirResistance;
        }
    }
    
    // deals with player wrapping the screen.
    if (position_x_ + (float)kWidth < 0) {
        position_x_ = kScreenSize;
    } else if (position_x_ > kScreenSize) {
        position_x_ = 0 - (float)kWidth;
    }

    height_up_ += velocity_[1];
    if (height_up_ > score) {
        score = height_up_;
    }
    
}

void Character::ChangeHorizontalVel(float change) {
    if (velocity_[0] > -9 && velocity_[0] < 9) {
        if ((velocity_[0] > 0 && change < 0) || (velocity_[0] < 0 && change > 0)) {
            velocity_[0] = 0;
            velocity_[0] += change;
        }
        if ( velocity_[0] == 0) {
            velocity_[0] += change;
        }
        velocity_[0] += change + 1;
    }
}

float Character::getScore() {
    return score;
}

}