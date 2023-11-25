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
    Array(const std::string &input);
    ~Array();

  union {
    std::vector<std::string> strings;
    std::vector<double> numbers;
    std::vector<Object> objects;
    std::vector<Array> arrays;
    std::vector<bool> booleans;
  } value;
  enum {
    ARRAY,
    STRING,
    OBJECT,
    NUMBER,
  } type;
  unsigned long size;

  unsigned long addItem(const std::string &input);

  void addBool(const std::string &input);
  void addString(const std::string &input);
  void addArray(const std::string &input);
  void addObject(const std::string &input);
  void addNumber(const std::string &input);
};

class Object {
  public:
    Object(const std::string &input);
    ~Object();

  std::string name;
  union {
    std::string string;
    double number;
    std::vector<Object> objects;
    bool boolean;
    Array array;
  } value;
  enum {
    ARRAY,
    STRING,
    OBJECT,
    NUMBER,
    BOOL,
  } type;
  unsigned long size;

  void addObject(const std::string &input);
  void setName(const std::string &input);
  void addProperty(const std::string &input);

  unsigned long setString(const std::string &input);
  unsigned long setArray(const std::string &input);
};

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

bool isDigit(char c)
{
  return (c >= '0' && c <= '9') || c == '.';
}

std::string getNumberString(const std::string &string)
{
  std::string number;
  bool point = false;

  for (unsigned long i = 0; string[i] && isDigit(string[i]); i++) {
    point = !point && string[i] == '.' ? true : false;
    if (point && string[i] == '.') {
      std::cout << "JSON_PARSING_ERROR: Invalid number." << std::endl;
      return number;
    }
    number += string[i];
  }
  return number;
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

unsigned int getBool(const std::string &input)
{
  std::string trueValue = "true";

  if (input.compare(0, trueValue.length(), input)) {
    return true;
  }
  return false;
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
