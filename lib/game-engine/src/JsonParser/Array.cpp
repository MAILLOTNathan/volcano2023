/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Array
*/

#include "JsonParser/Array.hpp"

Array::Array(const std::string &input)
{
  for (this->size = 1; input[this->size] && input[this->size] != ','; this->size++) {
    switch (input[this->size]) {
      case '"':
        this->addString(input.substr(this->size));
      case '{':
        this->addObject(input.substr(this->size));
      case '[':
        this->addArray(input.substr(this->size));
      case 't':
        this->addBool(input.substr(this->size));
      case 'f':
        this->addBool(input.substr(this->size));
      default:
        this->addNumber(input.substr(this->size));
    }
  }
}

void Array::addNumber(const std::string &input)
{
  std::string number = getNumberString(input);
  double value = std::atof(number.c_str());

  this->size += number.length();
  this->value.numbers.push_back(value);
}

void Array::addString(const std::string &input)
{
  this->size++;

  std::string value;

  for (unsigned int i = 1; input[i] && input[i] != '"'; i++, this->size++) {
    value += input[i];
  }
  this->size++;
  this->value.strings.push_back(value);
}

void Array::addObject(const std::string &input)
{
  Object *object = new Object(input);

  this->value.objects.push_back((*object));
  this->size += object->size;
}

void Array::addArray(const std::string &input)
{
  Array *array = new Array(input);
  this->value.arrays.push_back((*array));
}

void Array::addBool(const std::string &input)
{
  bool value = getBool(input);

  this->size += value ? 4 : 5;
  this->value.booleans.push_back(value);
}

unsigned long Array::addItem(const std::string &input)
{
  for (this->size = 1; input[this->size] && input[this->size] != ','; this->size++) {
    switch (input[this->size]) {
      case '"':
        this->addString(input.substr(this->size));
      case '{':
        this->addObject(input.substr(this->size));
      case '[':
        this->addArray(input.substr(this->size));
      case 't':
        this->addBool(input.substr(this->size));
      case 'f':
        this->addBool(input.substr(this->size));
      default:
        this->addNumber(input.substr(this->size));
    }
  }
}
