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
    
class GameRound {
    
public:
    GameRound();
    
    void Display();
    
    void UpdateGame();
    
    void KeyInput(const std::string& event);

private:
    Character character_;
    std::vector<Platform> platforms_;
};    
    
}

#endif //FINAL_PROJECT_GAMEROUND_H
