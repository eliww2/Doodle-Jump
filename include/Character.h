//
// Created by eliww on 4/18/2021.
//

#ifndef FINAL_PROJECT_CHARACTER_H
#define FINAL_PROJECT_CHARACTER_H

#include "cinder/gl/gl.h"

using glm::vec2;

namespace doodleJump {
    
class Character {
    
public:
    
    Character();
    
    void Display();
    
    void OnCollision();

    void UpdateCharacter();

private:
    
    bool alive = true;

    float position_x_ = 450;
    float position_y_ = 300;
    vec2 velocity_ = vec2(0, 15);
    
    const float kHeight = 70;
    const float kWidth = 50;   
    const double kJumpHeight = 13;
    const double kAcceleration = -.2;
};    
}  // namespace doodleJump
#endif //FINAL_PROJECT_CHARACTER_H
