//
// Created by eliww on 4/18/2021.
//

#include "Platform.h"

namespace doodleJump {
    
Platform::Platform() {
    left_position_ = (float)(rand() % 720);
    top_position_ = (float)(rand() % 720);
    bottom_position_ = top_position_ + kHeight;
    right_position_ = left_position_ + kLength;
    platform_box_ = ci::Rectf(vec2(left_position_, top_position_), vec2(right_position_, bottom_position_));
}

void Platform::Display() {
    ci::gl::color(ci::Color("black"));
    ci::gl::drawSolidRect(platform_box_);
}

vec2 Platform::getPosition() const {
    return glm::vec2(left_position_, top_position_); 
}


} // namespace doodleJump
