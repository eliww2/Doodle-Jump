//
// Created by eliww on 4/18/2021.
//

#include "../include/DoodleJumpApp.h"

namespace doodleJump {

doodleJump::DoodleJumpApp::DoodleJumpApp() {
    ci::app::setWindowSize(kWindowSize, kWindowSize);
}

    void DoodleJumpApp::draw() {
        ci::Color background_color("white");
        ci::gl::clear(background_color);
        ci::gl::color(ci::Color("green"));
        character_.Display();
        update();
    }

    void DoodleJumpApp::update() {
        character_.UpdateCharacter();
    }

}