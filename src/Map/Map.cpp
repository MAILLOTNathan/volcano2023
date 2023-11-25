/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Map
*/

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Plateform {
  public:
    Plateform(sf::Vector2f position, bool passed);
    ~Plateform();

    sf::Vector2f position;
    bool passed;

    void setPosition(sf::Vector2f position);
    void setPassed(bool passed);
};

class Map {
  public:
    Map(std::string file);
    ~Map();

    std::string name;
    std::vector<Plateform *> map;

    void addPlateform(sf::Vector2f pos);
    void setName(std::string name);
};

Plateform::Plateform(sf::Vector2f position, bool passed)
{
  this->setPosition(position);
  this->setPassed(passed);
}

void Plateform::setPosition(sf::Vector2f position)
{
  this->position = position;
}

void Plateform::setPassed(bool passed)
{
  this->passed = passed;
}

void Map::addPlateform(sf::Vector2f position)
{
  this->map.push_back(new Plateform(position, false));
}

void Map::setName(std::string name)
{
  this->name = name;
}

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
    if (isAvailableChar(input[i], "0123456789.,")) {
      data += input[i];
    }
  }
  return data;
}

sf::Vector2f extractData(std::string input)
{
  sf::Vector2f position;
  std::string posx;
  std::string posy;
  unsigned int i = 0;
  std::string data = getData(input);

  for (i = 0; i < data.length() && data[i] != ','; i++) {
    posx += data[i];
  }
  i++;
  for (i; i < data.length(); i++) {
    posy += data[i];
  }

  position.x = std::atof(posx.c_str());
  position.y = std::atof(posy.c_str());
  return position;
}

unsigned long goToNextData(std::string input, unsigned long position)
{
  while (position < input.length() && input[position] != ']') {
    position++;
  }

  return position;
}

Map::Map(std::string file)
{
  unsigned long index = 0;
  std::string name;

  while (file[index] != '[') {
    name += file[index++];
  }
  while (index < file.length()) {
    this->addPlateform(extractData(file.substr(index)));
    index = goToNextData(file, index);
  }
}