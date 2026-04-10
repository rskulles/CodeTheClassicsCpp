//
// Created by Roy Skullestad on 4/9/26.
//

#ifndef PADDLE_H
#define PADDLE_H
#include "../../../gamelib/include/GameObject.h"


class Paddle final: public GameObject{
public:
    void Update(const float &dt) override;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //PADDLE_H
