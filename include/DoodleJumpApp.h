//
// Created by eliww on 4/18/2021.
//

#ifndef FINAL_PROJECT_DOODLEJUMPAPP_H
#define FINAL_PROJECT_DOODLEJUMPAPP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Character.h"
#include "Platform.h"
#include "GameRound.h"

namespace doodleJump {
    
class DoodleJumpApp : public ci::app::App {
    
public:
    /**
     * Initializes the App
     */
    DoodleJumpApp();
    
    /**
     * Draws the objects on screen.
     */
    void draw() override;
    
    /**
     * Updates the game state and the games items. (DOES NOT UPDATE SCREEN).
     */
    void update() override;
    
    /**
     * Takes in keyboard input to make the game playable.
     * @param event - The key pressed down in the game.
     */
    void keyDown(ci::app::KeyEvent event) override;
    
    const int kWindowSize = 900;
    const int kMargin = 100;

private:
    
    // The round being played.
    GameRound current_game_;
    int highscore_ = 0;
};
    
} //namespace doodleJump
#endif //FINAL_PROJECT_DOODLEJUMPAPP_H
