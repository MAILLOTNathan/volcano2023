/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** ASprite
*/

#include "../../include/Graphical/ASprite.hpp"

etib::ASprite::ASprite()
{
}

std::string etib::ASprite::getPath()
{
    return _path;
}

Rect etib::ASprite::getTextureRect()
{
    return _rect;
}

Vector2 etib::ASprite::getPosition()
{
    return _pos;
}