//
// Created by Roy Skullestad on 4/9/26.
//

#ifndef APPLICATION_H
#define APPLICATION_H
#include "SFML/Graphics.hpp"
#include<Scene.h>

#include "GameEvent.h"
#include "TitleScene.h"

class Application final : public GameEventHandler<StartGameEvent>, public GameEventHandler<QuitEvent> {
public:
    Application();

    void Run();

protected:
    void Handle(const StartGameEvent &value) override;

    void Handle(const QuitEvent &value) override;

private: // methods
    void HandleEvents();

    void Update(const float &dt);

    void Render();

private: // fields
    bool is_running_;
    sf::View game_view_;
    std::shared_ptr<Scene> title_scene_;
    std::shared_ptr<Scene> game_scene_;
    std::shared_ptr<Scene> current_scene_;
    sf::RenderWindow window_;
};


#endif //APPLICATION_H
