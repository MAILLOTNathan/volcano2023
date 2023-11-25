/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Utils
*/

#include "cppIncludes.hpp"

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

unsigned int getBool(const std::string &input)
{
  std::string trueValue = "true";

  if (input.compare(0, trueValue.length(), input)) {
    return true;
  }
  return false;
}
