//
// Created by eliww on 4/18/2021.
//

#include "Platform.h"

namespace doodleJump {
    
    
Platform::Platform() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::mt19937 gen(rng);
    std::uniform_int_distribution<unsigned> x_distrib(0, kWindowSize - (int)kLength);
    std::uniform_int_distribution<unsigned> y_distrib(0, kWindowSize - (int)kHeight);
    left_position_ = (float)x_distrib(gen);
    top_position_ = (float)y_distrib(gen);
    bottom_position_ = top_position_ + kHeight;
    right_position_ = left_position_ + kLength;
    platform_box_ = ci::Rectf (vec2(left_position_, top_position_), vec2(right_position_, bottom_position_));
}

void Platform::Display() {
    platform_box_ = ci::Rectf (vec2(left_position_, top_position_), vec2(right_position_, bottom_position_));
    ci::gl::draw(platform_skin, platform_box_);
}

void Platform::UpdatePlatform() {
    if (top_position_ > kWindowSize) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::mt19937 gen(rng);
        std::uniform_int_distribution<unsigned> x_distrib(0, kWindowSize - (int)kLength);
        top_position_ = -kHeight;
        bottom_position_ = top_position_ + kHeight;
        left_position_ = (float)x_distrib(gen);
        right_position_ = left_position_ + kLength;
    }
}

} // namespace doodleJump
