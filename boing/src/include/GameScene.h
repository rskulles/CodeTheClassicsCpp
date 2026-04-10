//
// Created by Roy Skullestad on 4/9/26.
//

#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "../../../gamelib/include/Scene.h"


class GameScene final: public Scene{
public:
    GameScene();
    void Update(const float &dt) override;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    unsigned int left_paddle_score_;
    unsigned int right_paddle_score_;
    std::unique_ptr<GameObject> left_paddle_;
    std::unique_ptr<GameObject> right_paddle_;
    std::unique_ptr<GameObject> ball_;
    std::vector<std::unique_ptr<GameObject>> effects_;
};



#endif //GAMESCENE_H
