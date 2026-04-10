//
// Created by Roy Skullestad on 4/9/26.
//

#ifndef TITLESCENE_H
#define TITLESCENE_H
#include "Scene.h"
#include<GameEvent.h>

struct StartGameEvent {
    unsigned int num_players;
};

struct QuitEvent{};

class TitleScene final: public Scene{
public:
    TitleScene();
    void Update(const float &dt) override;
    GameEvent<StartGameEvent> EventStartGame;
    GameEvent<QuitEvent> EventQuitGame;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    enum class MenuItem{
        kPlayOnePlayer,
        kPlayTwoPlayer,
        kQuit
    };

    MenuItem selected_menu_item_;
    sf::Sprite title_sprite_;
    sf::Texture title_texture_;
    sf::Font title_font_;
    sf::Text start_one_player_text_;
    sf::Text start_two_player_text_;
    sf::Text quit_text_;
};



#endif //TITLESCENE_H
