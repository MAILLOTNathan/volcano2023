/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include "../cppIncludes.hpp"
#include "Object.hpp"

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

#endif /* !ARRAY_HPP_ */
