/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Graphical
*/

#include "../../include/Graphical/Graphical.hpp"

etib::Graphical::Graphical()
{
}

std::uint32_t etib::Graphical::getWidth() const
{
    return this->_width;
}

std::uint32_t etib::Graphical::getHeight() const
{
    return this->_height;
}

std::string etib::Graphical::getTitle() const
{
    return this->_title;
}