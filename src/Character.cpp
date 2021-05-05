//
// Created by eliww on 4/18/2021.
//

#include "Character.h"

namespace doodleJump {
    
Character::Character() {
    hit_box_ = ci::Rectf (vec2(position_x_, position_y_), vec2(position_x_ + (float)kWidth, position_y_ + (float)kHeight));
}

void Character::Display() {
    if (facing_left) {
        ci::gl::draw(kSkinLeft, hit_box_);
    } else {
        ci::gl::draw(kSkinRight, hit_box_);
    }
}

void Character::UpdateCharacter(std::vector<Platform>& platforms) {
    
    // Makes player move up the screen and checks for collision logic
    bool jumps = false;
    for (Platform& current_platform : platforms) {
        current_platform.bottom_position_ += velocity_[1];
        current_platform.top_position_ += velocity_[1];
        if (velocity_[1] <= 0 && CheckCollision(current_platform)) {
            jumps = true;
        }
    }
    if (jumps) {
        velocity_[1] = (float)kJumpHeight;
    }
    
    //Constant change in character based on velocity and acceleration as well as air resistance.
    position_x_ += velocity_[0];
    velocity_[1] = velocity_[1] + kAcceleration;
    if (velocity_[0] < 0) {
        if (-velocity_[0] < kAirResistance) {
            velocity_[0] = 0;
        } else {
            velocity_[0] += kAirResistance;
        }
        facing_left = true;
    } else if (velocity_[0] != 0) {
        if (velocity_[0] < kAirResistance) {
            velocity_[0] = 0;
        } else {
            velocity_[0] -= kAirResistance;
        }
        facing_left = false;
    }
    
    PlayerWrap();

    UpdateScore();

    hit_box_ = ci::Rectf (vec2(position_x_, position_y_), vec2(position_x_ + (float)kWidth, position_y_ + (float)kHeight));

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

bool Character::CheckCollision(const Platform& current_platform) const {
    auto platform_box = ci::Rectf(
            vec2(current_platform.left_position_, current_platform.top_position_),
            vec2(current_platform.right_position_, current_platform.bottom_position_)
    );
    ci::Rectf checker;
    if (facing_left) {
        checker = ci::Rectf(vec2(position_x_ + 30, position_y_), vec2((position_x_ + (float)kWidth), position_y_ + (float)kHeight));
    } else {
        checker = ci::Rectf(vec2(position_x_, position_y_), vec2((position_x_ + 60), position_y_ + (float)kHeight));
    }
    if (checker.intersects(platform_box) && (position_y_ + (float)kHeight) <= current_platform.bottom_position_) {
        return true;
    } else {
        return false;
    }
}

void Character::PlayerWrap() {
    if (position_x_ + (float)kWidth < 0) {
        position_x_ = kScreenSize;
    } else if (position_x_ > kScreenSize) {
        position_x_ = 0 - (float)kWidth;
    }
}

void Character::UpdateScore() {
    height_up_ += velocity_[1];
    if (height_up_ > score) {
        score = height_up_;
    }
}

float Character::GetScore() const {
    return score;
}

}