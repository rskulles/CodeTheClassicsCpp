//
// Created by Roy Skullestad on 4/9/26.
//

#ifndef BALLEFFECT_H
#define BALLEFFECT_H

#include <../../../gamelib/include/GameObject.h>

class BallEffect final: public GameObject {

public:
    BallEffect();
    void Update(const float &dt) override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};



#endif //BALLEFFECT_H
