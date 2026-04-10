//
// Created by Roy Skullestad on 4/9/26.
//

#include<Application.h>

#include "GameScene.h"
#include "TitleScene.h"

void Application::Handle(const StartGameEvent &value) {
    current_scene_= game_scene_;
}

void Application::Handle(const QuitEvent &value) {
    dynamic_cast<TitleScene*>(current_scene_.get())->EventQuitGame-=this;
    is_running_=false;
}

Application::Application():is_running_(true),game_view_(sf::FloatRect({0,0},{384,216})) {
    window_ = sf::RenderWindow(sf::VideoMode::getDesktopMode(),"Boing!",sf::Style::None,sf::State::Fullscreen);
    window_.setView(game_view_);
    const auto title = std::make_shared<TitleScene>();
    title_scene_ = title;
    title->EventQuitGame+=this;
    title->EventStartGame+=this;
    const auto game = std::make_shared<GameScene>();
    game_scene_ = game;
    current_scene_ = title_scene_;
}

void Application::Run() {
    sf::Clock clock;
    while(is_running_) {
        auto dt = clock.restart().asSeconds();
        HandleEvents();
        Update(dt);
        Render();
    }
    window_.close();
}

void Application::HandleEvents() {
    while( const auto e=window_.pollEvent()) {
        if(e->is<sf::Event::Closed>()) {
            is_running_=false;
        }
        if(const auto* resized = e->getIf<sf::Event::Resized>()) {
            window_.setView(game_view_);
        }
    }
}

void Application::Update(const float &dt) {
    if(current_scene_!=nullptr) {
        current_scene_->Update(dt);
    }
}

void Application::Render() {
    window_.clear(sf::Color::Cyan);
    if(current_scene_!=nullptr) {
        window_.draw(*current_scene_);
    }
    window_.display();
}
