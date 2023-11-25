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
  index++;
  while (index < file.length()) {
    this->addPlateform(extractData(file.substr(index)));
    index = goToNextData(file, index);
  }
}

void Map::addPlateform(sf::Vector2f position)
{
  std::shared_ptr<Plateform> plateform = std::make_shared<Plateform>();
  plateform->init(position, false);
  this->_map.push_back(plateform);
}

void Map::setName(std::string name)
{
  this->_name = name;
}

void Map::display(void)
{
  std::cout << "Map: " + this->_name << std::endl;
  for (unsigned long i = 0; i < this->_map.size(); i++) {
    this->_map[i]->display();
  }
}
