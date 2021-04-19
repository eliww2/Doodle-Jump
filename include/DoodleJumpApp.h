//
// Created by eliww on 4/18/2021.
//

#ifndef FINAL_PROJECT_DOODLEJUMPAPP_H
#define FINAL_PROJECT_DOODLEJUMPAPP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Character.h"

namespace doodleJump {
 
class DoodleJumpApp : public ci::app::App {
    
public:
    DoodleJumpApp();
    void draw() override;
    void update() override;
    
    const int kWindowSize = 900;
    const int kMargin = 100;

private:
    Character character_;
};
    
} //namespace doodleJump
#endif //FINAL_PROJECT_DOODLEJUMPAPP_H
