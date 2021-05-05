//
// Created by eliww on 4/18/2021.
//

#include "DoodleJumpApp.h"

namespace doodleJump {

doodleJump::DoodleJumpApp::DoodleJumpApp() {
    ci::app::setWindowSize(kWindowSize, kWindowSize);
    background_ = ci::gl::Texture2d::create(ci::loadImage(R"(C:\Users\eliww\Downloads\Cinder\my_projects\final-project\assets\background.png)"));
}

void DoodleJumpApp::draw() {
    ci::Rectf back(vec2(0, kWindowSize + 300), vec2(kWindowSize, 0));
    ci::gl::draw(background_, back);
    if (current_game_.alive) {
        current_game_.Display();
    } else {
        if (current_game_.round_score > highscore_) {
            highscore_ = current_game_.round_score;
        }
        std::string last_score = "Score: " + std::to_string(current_game_.round_score);
        std::string high_score = "High Score: " + std::to_string(highscore_);
        ci::gl::drawString("GAME OVER", vec2(250, 250), ci::Color("Black"), ci::Font("arial", 80));
        ci::gl::drawString(last_score, vec2(250, 350), ci::Color("Black"), ci::Font("arial", 80));
        ci::gl::drawString(high_score, vec2(250, 450), ci::Color("Black"), ci::Font("arial", 80));
    }
}

void DoodleJumpApp::update() {
    if (current_game_.alive) {
        current_game_.UpdateGame();
    }
}

void DoodleJumpApp::keyDown(ci::app::KeyEvent event) { 
    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_LEFT:
            current_game_.KeyInput("left");
            break;
        case ci::app::KeyEvent::KEY_RIGHT:
            current_game_.KeyInput("right");
            break;
        case ci::app::KeyEvent::KEY_SPACE:
            if (!current_game_.alive) {
                current_game_ = GameRound();
            }
            current_game_.KeyInput("space");
            break;
    }
}

}