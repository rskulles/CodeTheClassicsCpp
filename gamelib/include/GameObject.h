//
// Created by Roy Skullestad on 4/9/26.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<SFML/Graphics.hpp>

class GameObject: public sf::Drawable,public sf::Transformable{
public:
    virtual void Update(const float &dt)=0;
};
#endif //GAMEOBJECT_H
