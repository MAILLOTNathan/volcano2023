/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Plateform
*/

#pragma once
#include "cppIncludes.hpp"
#include "Map/Utils.hpp"

class Plateform {
  public:
    Plateform();
    ~Plateform();

    void init(params_t *params);
    void setPosition(sf::Vector2f position);
    void setPassed(bool passed);
    void setType(PlateformType type);
    void display(void);

    sf::Vector2f _position;
    bool _passed;
    PlateformType _type;
};
