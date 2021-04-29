//
// Created by eliww on 4/18/2021.
//

#include "Platform.h"

namespace doodleJump {
    
    
Platform::Platform() {
    left_position_ = (float)(rand() % (kWindowSize - (int)kLength));
    top_position_ = (float)(rand() % (kWindowSize - (int)kHeight));
    bottom_position_ = top_position_ + kHeight;
    right_position_ = left_position_ + kLength;
    platform_box_ = ci::Rectf (vec2(left_position_, top_position_), vec2(right_position_, bottom_position_));
}

void Platform::Display() {
    ci::gl::color(ci::Color("black"));
    platform_box_ = ci::Rectf (vec2(left_position_, top_position_), vec2(right_position_, bottom_position_));
    ci::gl::drawSolidRoundedRect(platform_box_, 10, 10);
}

void Platform::UpdatePlatform() {
    if (top_position_ > kWindowSize) {
        top_position_ = -kHeight;
        bottom_position_ = top_position_ + kHeight;
        left_position_ = (float)(rand() % (kWindowSize - (int)kLength));
        right_position_ = left_position_ + kLength;
    }
}

} // namespace doodleJump
