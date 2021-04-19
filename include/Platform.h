//
// Created by eliww on 4/18/2021.
//

#ifndef FINAL_PROJECT_PLATFORM_H
#define FINAL_PROJECT_PLATFORM_H

#include "cinder/gl/gl.h"
#include <random>

using glm::vec2;

namespace doodleJump {
    
class Platform {
    
public:
    Platform();
    
    Platform(const float height);
    
    void Display() const;
    
    float left_position_;
    float top_position_;
    float bottom_position_;
    float right_position_;
    ci::Rectf platform_box_;

private:
    const float kHeight = 20;
    const float kLength = 80;
};
    
}
#endif //FINAL_PROJECT_PLATFORM_H
