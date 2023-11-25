/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "cppIncludes.hpp"
#include "JsonParser/Array.hpp"

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

#endif /* !OBJECT_HPP_ */
