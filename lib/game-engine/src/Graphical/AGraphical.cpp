/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** AGraphical
*/

#include "Graphical/AGraphical.hpp"

etib::AGraphical::AGraphical()
{
}

std::uint32_t etib::AGraphical::getWidth() const
{
    return this->_width;
}

std::uint32_t etib::AGraphical::getHeight() const
{
    return this->_height;
}

std::string etib::AGraphical::getTitle() const
{
    return this->_title;
}
