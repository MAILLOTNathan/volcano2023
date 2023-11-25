/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Object
*/

#include <string>
#include <iostream>
#include <vector>

class Array {
  public:
    Array();
    ~Array();

  union {
    std::vector<std::string> strings;
    std::vector<double> numbers;
    std::vector<Object> objects;
    std::vector<Array> arrays;
  } value;
  enum {
    ARRAY,
    STRING,
    OBJECT,
    NUMBER,
  } type;
};

class Object {
  public:
    Object(std::string &input);
    ~Object();

  std::string name;
  union {
    std::string string;
    double number;
    std::vector<Object> objects;
    Array array;
  } value;
  enum {
    ARRAY,
    STRING,
    OBJECT,
    NUMBER,
  } type;
  unsigned long size;

  void addObject(const std::string &input);
  void setName(const std::string &input);
  void addProperty(const std::string &input);

  unsigned long setString(const std::string &input);
  unsigned long setArray(const std::string &input);
};

Object::Object(std::string &input)
{
  for (this->size = 0; input[this->size]; this->size++) {
    input = input.substr(this->size);
    switch (input.front()) {
      case '{':
        this->addObject(input);
      case '"':
        this->setName(input);
      case ':':
        this->addProperty(input);
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

  for (unsigned int i = 0; text[i] && text[i] != ']'; i++) {
    this->value.string += text[i];
    this->size++;
    written++;
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
