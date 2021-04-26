//
// Created by eliww on 4/18/2021.
//

#ifndef FINAL_PROJECT_PLATFORM_H
#define FINAL_PROJECT_PLATFORM_H

#include "cinder/gl/gl.h"
#include <random>

using glm::vec2;

namespace doodleJump {
    
/**
 * Jumpable platforms for the character.
 */
class Platform {
    
public:
    
    /**
     * Creates the any platforms that are used to start the game.
     * Sets their positions randomly.
     */
    Platform();
    
    /**
     * Creates platform of random x position, but is passed the height that it will spawn at.
     * @param height at what position the height the platform should spawn.
     */
    explicit Platform(const float height);
    
    /**
     * Displays the platform on the screen.
     * Currently has default black color but will have sprite in future.
     */
    void Display();
    
    void UpdatePlatform();
    
    /**
     * Basic positions for the platform.
     */
    float left_position_;
    float top_position_;
    float bottom_position_;
    float right_position_;
    ci::Rectf platform_box_;
    
private:
    constexpr static const float kHeight = 20;
    constexpr static const float kLength = 80;
    constexpr static const int kWindowSize = 900;
};
    
}
#endif //FINAL_PROJECT_PLATFORM_H
