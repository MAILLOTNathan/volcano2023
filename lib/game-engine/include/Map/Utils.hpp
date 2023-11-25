/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Utils
*/

#pragma once
#include "cppIncludes.hpp"

bool isAvailableChar (char c, std::string availables);
std::string getData(std::string input);
sf::Vector2f extractData(std::string input);
unsigned long goToNextData(std::string input, unsigned long position);
