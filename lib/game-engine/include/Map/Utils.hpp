/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Utils
*/

#pragma once
#include "cppIncludes.hpp"

typedef enum PlateformType_e {
  STATIC,
  BREAKABLE,
  VERTICAL,
  HORIZONTAL,
} PlateformType;

typedef struct params_s {
  sf::Vector2f position;
  PlateformType type;
} params_t;

bool isAvailableChar (char c, std::string availables);
std::string getData(std::string input);
params_t *extractData(std::string input);
unsigned long goToNextData(std::string input, unsigned long position);

