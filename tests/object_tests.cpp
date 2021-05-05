//
// Created by eliww on 5/4/2021.
//

#include <catch2/catch.hpp>
#include "Character.h"
#include "Platform.h"

using namespace doodleJump;

TEST_CASE("Test collision") {
    Character man;
    std::vector<Platform> platforms;
    platforms.emplace_back(Platform());
    
    platforms[0].platform_box_ = ci::Rectf (vec2(400, 500), vec2(500, 400));
    
    REQUIRE(!man.CheckCollision(platforms[0]));

    man.velocity_[1] = 0;

    REQUIRE(man.CheckCollision(platforms[0]));

}

TEST_CASE("Test update") {
    Character man;
    std::vector<Platform> platforms;
    platforms.emplace_back(Platform());
    platforms[0].platform_box_ = ci::Rectf (vec2(400, 500), vec2(500, 400));
    man.velocity_[1] = 0;
    man.UpdateCharacter(platforms);
    REQUIRE(man.velocity_[0] == 0);
    REQUIRE(man.velocity_[1] == 17);
    man.UpdateCharacter(platforms);
    REQUIRE(man.velocity_[1] == 16.6f);
}

TEST_CASE("Change Horizontal Velocity") {
    Character man;
    REQUIRE(man.velocity_[0] == 0);
    man.ChangeHorizontalVel(-3);
    REQUIRE(man.velocity_[0] == -3);
    man.ChangeHorizontalVel(3);
    REQUIRE(man.velocity_[0] == 0);
}

TEST_CASE("Update Score") {
    Character man;
    std::vector<Platform> platforms;
    platforms.emplace_back(Platform());
    REQUIRE(man.GetScore() == 0);
    man.UpdateCharacter(platforms);
    REQUIRE(man.GetScore() == 14);
}

TEST_CASE("Update Platform") {
    Platform platform;
    float top = platform.top_position_;
    float left = platform.left_position_;
    platform.UpdatePlatform();
    REQUIRE(platform.top_position_ == -40);
    REQUIRE(left != platform.left_position_);
}
