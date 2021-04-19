//
// Created by eliww on 4/18/2021.
//

#include "GameRound.h"

namespace doodleJump {
    
GameRound::GameRound() {
    for (int i = 0; i < 10; i++) {
        platforms_.emplace_back(Platform());
    }
}

void GameRound::Display() {
    character_.Display();
    for (Platform current_platform : platforms_) {
            current_platform.Display();
    }
}

void GameRound::UpdateGame() {
    character_.UpdateCharacter(platforms_);
}

}  // namespace doodleJump