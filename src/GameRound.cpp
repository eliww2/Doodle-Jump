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
    if (!playing_) {
        ci::gl::drawString("Press SPACEBAR to play", vec2(90, 450), ci::Color("Blue"), ci::Font("arial", 80));
    }
}

void GameRound::UpdateGame() {
    if (playing_ && alive) {
        character_.UpdateCharacter(platforms_);
        for (Platform &platform : platforms_) {
            platform.UpdatePlatform();
        }
    }
    int platforms_onscreen = 0;
    for (Platform current_platform : platforms_) {
        if (current_platform.bottom_position_ > 0) {
            platforms_onscreen++;
        }  
    }
    if (platforms_onscreen == 0) {
        round_score = (int)(character_.getScore() / 4);
        alive = false;
    }
}

void GameRound::KeyInput(const std::string& event) {
    if (event == "left" && playing_) {
        character_.ChangeHorizontalVel(-3);
    } else if (event == "right" && playing_) {
        character_.ChangeHorizontalVel(3);
    } else if (event == "space") {
        playing_ = !playing_;
    }
}

}  // namespace doodleJump