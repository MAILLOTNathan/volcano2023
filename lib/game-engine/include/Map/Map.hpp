/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Map
*/

#pragma once

#include "cppIncludes.hpp"
#include "Map/Plateform.hpp"
#include "Map/Utils.hpp"

class Map {
  public:
    Map();
    ~Map();

    std::string name;
    std::vector<Plateform *> map;

    void init(std::string file);
    void addPlateform(sf::Vector2f pos);
    void setName(std::string name);
    void display(void);
};
