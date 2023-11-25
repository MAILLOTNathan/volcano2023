/*
** EPITECH PROJECT, 2023
** Volcano
** File description:
** programmers start to count from 0
*/

#include "Volcano.hpp"

Volcano::Volcano()
{
}

void Volcano::init()
{
    _graphical = std::make_shared<etib::AGraphical>();
}

void Volcano::run()
{
    while (_graphical->isOpen()) {
        _graphical->clear();
        _graphical->draw();
    }
}

Volcano::~Volcano()
{
}
