//
// Created by eliww on 4/18/2021.
//

#include "DoodleJumpApp.h"

namespace doodleJump {

doodleJump::DoodleJumpApp::DoodleJumpApp() {
    ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void DoodleJumpApp::draw() {
    ci::Color background_color("white");
    ci::gl::clear(background_color);
    current_game_.Display();
}

void DoodleJumpApp::update() {
    current_game_.UpdateGame();
}

void DoodleJumpApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_LEFT:
            current_game_.KeyInput("left");
            break;
        case ci::app::KeyEvent::KEY_RIGHT:
            current_game_.KeyInput("right");
            break;
    }
}

}