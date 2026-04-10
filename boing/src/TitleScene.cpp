//
// Created by Roy Skullestad on 4/9/26.
//

#include<TitleScene.h>

TitleScene::TitleScene(): selected_menu_item_(MenuItem::kPlayOnePlayer){
}

void TitleScene::Update(const float &dt) {
    current_seconds_+=dt;
    if(current_seconds_>=seconds_until_quit_) {
        EventQuitGame(QuitEvent{});
    }
}

void TitleScene::draw(sf::RenderTarget &target, sf::RenderStates states) const {
}
