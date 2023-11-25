/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <string>
#include <iostream>

class Object {
  public:
    Object(char *jsonValue);
    ~Object();

  const nullptrstd::string name;
  union {
    char *string;
    double number;
    Object *object;
    Object **array;
  } value;
  enum {
    ARRAY,
    STRING,
    OBJECT,
    NUMBER,
  } type;
};

#endif /* !OBJECT_HPP_ */
