//
// Created by eliww on 4/18/2021.
//

#ifndef FINAL_PROJECT_CHARACTER_H
#define FINAL_PROJECT_CHARACTER_H

#include "cinder/gl/gl.h"
#include "Platform.h"

using glm::vec2;

namespace doodleJump {
    
class Character {
    
public:
    
    Character();
    
    void Display();
    
    void UpdateCharacter(const std::vector<Platform>& platforms);
    
    void ChangeHorizontalVel(float change);
    
private:
    
    float position_x_ = 450;
    float position_y_ = 300;
    vec2 velocity_ = vec2(0, 15);
    ci::Rectf hit_box_;
    
    const float kHeight = 70;
    const float kWidth = 50;   
    const double kJumpHeight = 17;
    const float kAcceleration = -.4f;
    const float kAirResistance = .2f;
};    
}  // namespace doodleJump
#endif //FINAL_PROJECT_CHARACTER_H
