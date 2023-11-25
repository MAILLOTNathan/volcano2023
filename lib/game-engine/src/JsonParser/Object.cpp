/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Object
*/

#include "JsonParser/Object.hpp"

Object::Object(const std::string &input)
{
  std::string text = input;
  for (this->size = 0; text[this->size]; this->size++) {
    text = text.substr(this->size);
    switch (text.front()) {
      case '{':
        this->addObject(text);
      case '"':
        this->setName(text);
      case ':':
        this->addProperty(text);
      default:
        break;
    }
  }
}

void Object::setName(const std::string &input)
{
  std::string text = input.substr(1);
  this->size++;

  for (unsigned int i = 0; text[i] && text[i] != '"'; i++) {
    this->name += text[i];
    this->size++;
  }
}

unsigned long Object::setString(const std::string &input)
{
  std::string text = input.substr(1);
  unsigned long written = 0;
  this->size++;

  for (unsigned int i = 0; text[i] && text[i] != '"'; i++) {
    this->value.string += text[i];
    this->size++;
    written++;
  }
  return written;
}

unsigned long Object::setArray(const std::string &input)
{
  std::string text = input.substr(1);
  unsigned long written = 0;
  this->size++;

  for (unsigned long i = 0; text[i] && text[i] != ']'; i++) {
    i += this->value.array.addItem(text.substr(i));
  }
  return written;
}

void Object::addProperty (const std::string &input)
{
  for (unsigned int i = 0; input[i] && input[i] != ','; i++) {
    switch (input[i]) {
      case '"':
        i += this->setString(input);
      case '[':
        i += this->setArray(input);
      default:
        break;
    }
  }
}

void Object::addObject(const std::string &input)
{
  std::string newInput = input.substr(1);
  this->value.objects.push_back(Object(newInput));
  for (unsigned int i = 0; i < this->value.objects.size(); i++) {
    this->size += this->value.objects[i].size;
  }
}


const char *object = "{'oui': false, 'name': 'jean' }";
