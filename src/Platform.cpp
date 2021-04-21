//
// Created by eliww on 4/18/2021.
//

#include "Platform.h"

namespace doodleJump {
    
    
Platform::Platform() {
    left_position_ = (float)(rand() % 720);
    top_position_ = (float)(rand() % 780);
    bottom_position_ = top_position_ + kHeight;
    right_position_ = left_position_ + kLength;
    platform_box_ = ci::Rectf(vec2(left_position_, top_position_), vec2(right_position_, bottom_position_));
}

Platform::Platform(const float setHeight) {
    left_position_ = (float)(rand() % 720);
    bottom_position_ = setHeight;
    top_position_ = bottom_position_ - kHeight;
    right_position_ = left_position_ + kLength;
    platform_box_ = ci::Rectf(vec2(left_position_, top_position_), vec2(right_position_, bottom_position_));
}

void Platform::Display() const {
    ci::gl::color(ci::Color("black"));
    ci::gl::drawSolidRoundedRect(platform_box_, 10, 10);
}



} // namespace doodleJump
