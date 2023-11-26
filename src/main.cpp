#include "Volcano.hpp"
#include "Map/Map.hpp"

std::string readFileToString(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "ERROR: Can't open the file :" << filename << std::endl;
        return "";
    }

    std::ostringstream content;
    content << file.rdbuf();

    return content.str();
}

int main2(void)
{
    Map *map = new Map();

    map->init(readFileToString("ressources/test.map"));
    map->display();
    return 0;
}

int main(void)
{
    Volcano volcano;

    volcano.init(1920, 1080, "Volcano");
    volcano.run();
    return 0;
}