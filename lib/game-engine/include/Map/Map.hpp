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

    void init(std::string file);
    void addPlateform(params_t *params);
    void setName(std::string name);
    void display(void);

    std::string _name;
    std::vector<std::shared_ptr<Plateform>> _map;
};
