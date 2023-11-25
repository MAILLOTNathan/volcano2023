/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Plateform
*/

#pragma once
#include "cppIncludes.hpp"

class Plateform {
  public:
    Plateform();
    ~Plateform();

    void init(sf::Vector2f position, bool passed);
    void setPosition(sf::Vector2f position);
    void setPassed(bool passed);
    void display(void);

    sf::Vector2f _position;
    bool _passed;
};
