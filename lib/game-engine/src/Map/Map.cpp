/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Map
*/

#include "Map/Map.hpp"

// initialize
Map::Map()
{
}

Map::~Map()
{
}

// methods
void Map::init(std::string file)
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

void Map::addPlateform(sf::Vector2f position)
{
  Plateform *plateform = new Plateform();
  plateform->init(position, false);
  this->map.push_back(plateform);
}

void Map::setName(std::string name)
{
  this->name = name;
}

void Map::display(void)
{
  std::cout << "Map: " + this->name << std::endl;
  for (unsigned long i = 0; i < this->map.size(); i++) {
    this->map[i].display();
  }
}
