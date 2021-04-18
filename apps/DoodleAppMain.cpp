//
// Created by eliww on 4/18/2021.
//
#include "DoodleJumpApp.h"

using doodleJump::DoodleJumpApp;

void prepareSettings(DoodleJumpApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(DoodleJumpApp, ci::app::RendererGl, prepareSettings);
