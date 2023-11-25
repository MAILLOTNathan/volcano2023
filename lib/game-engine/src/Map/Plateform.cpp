/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Plateform
*/

#include "Map/Plateform.hpp"

// initialize
Plateform::Plateform()
{
}

Plateform::~Plateform()
{
}

// methods
void Plateform::init(sf::Vector2f position, bool passed)
{
  this->setPosition(position);
  this->setPassed(passed);
}

void Plateform::setPosition(sf::Vector2f position)
{
  this->position = position;
}

void Plateform::setPassed(bool passed)
{
  this->passed = passed;
}

void Plateform::display(void)
{
  std::cout << "========" << std::endl;
  std::cout << "Plateform: " << std::endl;
  std::cout << "x: " + this->position.x << std::endl;
  std::cout << "y: " + this->position.y << std::endl;
  std::cout << "========" << std::endl;
}
