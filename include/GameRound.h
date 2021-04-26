//
// Created by eliww on 4/18/2021.
//

#ifndef FINAL_PROJECT_GAMEROUND_H
#define FINAL_PROJECT_GAMEROUND_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Character.h"
#include "Platform.h"

namespace doodleJump {
    
/**
 * The current game being played. This is when there is action, rather than home or pause screen.
 */
class GameRound {
    
public:
    
    /**
     * Starts the game and then initializes the platforms.
     */
    GameRound();
    
    /**
     * Uses it's characters and platforms, then gets their display information and communicates it with the app.
     */
    void Display();
    
    /**
     * Updates the game state.
     */
    void UpdateGame();
    
    /**
     * Passes they Key event to the character to tell it how to change it's variables.
     * @param event - Key pressed.
     */
    void KeyInput(const std::string& event);

private:
    Character character_;
    std::vector<Platform> platforms_;
};    
    
}

#endif //FINAL_PROJECT_GAMEROUND_H
