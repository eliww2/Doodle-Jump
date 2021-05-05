//
// Created by eliww on 4/18/2021.
//

#ifndef FINAL_PROJECT_PLATFORM_H
#define FINAL_PROJECT_PLATFORM_H

#include "cinder/gl/gl.h"
#include <ctime>
#include <chrono>
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
     * Displays the platform on the screen.
     * Currently has default black color but will have sprite in future.
     */
    void Display();
    
    /**
     * Updates the position of the platform.
     */
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
    
    constexpr static const float kHeight = 40;
    constexpr static const float kLength = 100;
    constexpr static const int kWindowSize = 900;
    ci::gl::Texture2dRef platform_skin = 
            ci::gl::Texture2d::create(
                    ci::loadImage(
                            R"(C:\Users\eliww\Downloads\Cinder\my_projects\final-project\assets\platform.png)")
    );
};
    
}
#endif //FINAL_PROJECT_PLATFORM_H
