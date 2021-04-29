//
// Created by eliww on 4/18/2021.
//

#ifndef FINAL_PROJECT_CHARACTER_H
#define FINAL_PROJECT_CHARACTER_H

#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/audio/audio.h"
#include "cinder/app/App.h"
#include "Platform.h"

using glm::vec2;

namespace doodleJump {
    
/**
 * Object for the human playable character.
 * Can only be one for each game.
 */
class Character {
    
public:
    
    /**
     * Creates and initializes the character
     */
    Character();
    
    /**
     * This is called by that app to show the current placement of the character.
     * In here the default color is green, however later on there should be a sprite added.
     */
    void Display();
    
    /**
     * Updates character current position and velocity. Detects collisions and air resistance.
     * @param platforms Takes in the only current object that is collideable and checks to see if they intersect.
     */
    void UpdateCharacter(std::vector<Platform>& platforms);
    
    /**
     * Used in changing the velocity of the character in the x axis, only possible through player key inputs.
     * @param change 
     */
    void ChangeHorizontalVel(float change);
    
    /**
     * Deals with the player going off the screen. If they do then it makes it come out the other side.
     */
    void PlayerWrap();
    
    /**
     * Returns player score
     * @return score.
     */
    float GetScore() const;
    
private:

    ci::gl::Texture2dRef kSkinLeft = ci::gl::Texture2d::create(ci::loadImage(R"(C:\Users\eliww\Downloads\Cinder\my_projects\final-project\Sprites\skin_left.png)"));
    ci::gl::Texture2dRef kSkinRight = ci::gl::Texture2d::create(ci::loadImage(R"(C:\Users\eliww\Downloads\Cinder\my_projects\final-project\Sprites\skin_right.png)"));

    /**
     * Set to initial player data. Updated in UpdateCharacter()
     */
    float position_x_ = 450;
    float position_y_ = 415;
    vec2 velocity_ = vec2(0, 15);
    ci::Rectf hit_box_;
    float height_up_ = 0;
    float score = 0;
    bool facing_left = true;
    
    /**
     * Basic const variables for game play.
     */
    constexpr static const float kHeight = 90;
    constexpr static const float kWidth = 90;   
    constexpr static const double kJumpHeight = 17;
    constexpr static const float kAcceleration = -.4f;
    constexpr static const float kAirResistance = .2f;
    constexpr static const float kScreenSize = 900;
    
};    
}  // namespace doodleJump
#endif //FINAL_PROJECT_CHARACTER_H
