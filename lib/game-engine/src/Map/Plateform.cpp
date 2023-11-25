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
  this->_position = position;
}

void Plateform::setPassed(bool passed)
{
  this->_passed = passed;
}

void Plateform::display(void)
{
  std::cout << "========" << std::endl;
  std::cout << "Plateform: " << std::endl;
  printf("x: %f\n", this->_position.x);
  printf("y: %f\n", this->_position.y);
  std::cout << "========" << std::endl;
}
