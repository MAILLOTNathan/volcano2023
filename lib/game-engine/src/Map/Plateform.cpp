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
void Plateform::init(params_t *params)
{
  this->setPosition(params->position);
  this->setPassed(false);
  this->setType(params->type);
}

void Plateform::setPosition(sf::Vector2f position)
{
  this->_position = position;
}

void Plateform::setPassed(bool passed)
{
  this->_passed = passed;
}

void Plateform::setType(PlateformType type)
{
  this->_type = type;
}

void Plateform::display(void)
{
  std::cout << "========" << std::endl;
  std::cout << "Plateform: " << std::endl;
  printf("x: %f\n", this->_position.x);
  printf("y: %f\n", this->_position.y);
  switch (this->_type) {
    case STATIC:
      printf("static\n");
      break;
    case HORIZONTAL:
      printf("horizontal\n");
      break;
    case VERTICAL:
      printf("vertical\n");
      break;
    case BREAKABLE:
      printf("breakable\n");
      break;
    default:
      printf("unknown\n");
      break;
  }
  std::cout << "========" << std::endl;
}
