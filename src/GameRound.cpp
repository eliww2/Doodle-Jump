//
// Created by eliww on 4/18/2021.
//

#include "GameRound.h"

namespace doodleJump {
    
GameRound::GameRound() {
    for (int i = 0; i < platform_count; i++) {
        platforms_.emplace_back(Platform());
    }
}
 
void GameRound::Display() {
    for (Platform current_platform : platforms_) {
        current_platform.Display();
    }
    character_.Display();
    if (!playing_) {
        ci::gl::drawString("Press SPACEBAR to play", vec2(90, 350), ci::Color("black"), ci::Font("arial", 80));
    }
    if (alive) {
        std::string current_score = "Score: " + std::to_string((int)(character_.GetScore() / 4));
        ci::gl::drawString(current_score, vec2(10, 10), ci::Color("black"), ci::Font("arial", 24));
    }
}

void GameRound::UpdateGame() {
    int platforms_onscreen = -1;
    if (playing_ && alive) {
        platforms_onscreen = 0;
        character_.UpdateCharacter(platforms_);
        for (Platform &platform : platforms_) {
            platform.UpdatePlatform();
            if (platform.bottom_position_ > 0) {
                platforms_onscreen++;
            }
        }
    }
    //When the player falls this changes to Gameover screen.
    if (platforms_onscreen == 0) {
        round_score = (int)(character_.GetScore() / 4);
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