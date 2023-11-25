#include <iostream>
#include <fstream>
#include <sstream>

#include "../lib/game-engine/include/JsonParser/Object.hpp"
#include "../lib/game-engine/include/JsonParser/Array.hpp"

std::string readFileToString(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier : " << filename << std::endl;
        return "";
    }

    std::ostringstream content;
    content << file.rdbuf();  // Lire tout le contenu du fichier dans le tampon

    return content.str();
}

std::string printSpace(int space)
{
    std::string string = "----";

    for (unsigned int i = 0; i < space; i++) {
        string += string;
    }
    return string;
}

void print(std::string content, int space)
{
    std::cout << printSpace(space) + content << std::endl;
}


void displayObject(Object *object, int space)
{
    print("name: " + object->name + ",", space);
    if ()
}

int main(void)
{
    std::string path = "ressources/test.json";
    std::string json;

    json = readFileToString(path);

    Object *object = new Object(json);


}
