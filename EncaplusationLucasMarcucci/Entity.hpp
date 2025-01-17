#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "datas.hpp"

class Entity {
public:
    virtual void update(float deltaTime) = 0;
    virtual void draw(RenderWindow & window) = 0;
};

#endif