//
// Created by Roy Skullestad on 4/9/26.
//

#include "include/GameScene.h"

GameScene::GameScene() {
}

void GameScene::Update(const float &dt) {
}

void GameScene::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*left_paddle_,states);
    target.draw(*right_paddle_,states);
    target.draw(*ball_);
}
