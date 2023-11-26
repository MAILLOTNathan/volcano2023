/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Utils
*/

#include "Map/Utils.hpp"

bool isAvailableChar (char c, std::string availables)
{
  for (int i = 0; i < availables.length(); i++) {
    if (c == availables[i]) {
      return true;
    }
  }
  return false;
}

std::string getData(std::string input)
{
  std::string data;
  for (unsigned int i = 0; i < input.length() && input[i] != ']'; i++) {
    if (isAvailableChar(input[i], "0123456789.,shvb")) {
      data += input[i];
    }
  }
  return data;
}

params_t *extractData(std::string input)
{
  params_t *params = new params_t();

  std::string posx;
  std::string posy;
  unsigned int i = 0;
  std::string data = getData(input);

  for (i = 0; i < data.length() && data[i] != ','; i++) {
    posx += data[i];
  }
  i++;
  for (i; i < data.length() && data[i] != ','; i++) {
    posy += data[i];
  }
  params->position.x = std::atof(posx.c_str());
  params->position.y = std::atof(posy.c_str());

  i++;
  switch (data[i]) {
    case 'b':
      params->type = BREAKABLE;
      break;
    case 'v':
      params->type = VERTICAL;
      break;
    case 'h':
      params->type = HORIZONTAL;
      break;
    default:
      params->type = STATIC;
      break;
  }
  return params;
}

unsigned long goToNextData(std::string input, unsigned long position)
{
  while (position < input.length() && input[position] != '[') {
    position++;
  }

  return position + 1;
}
