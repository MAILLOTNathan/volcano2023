#include "Volcano.hpp"

int main(void)
{
    Volcano volcano;

    volcano.init(1920, 1080, "Volcano");
    volcano.run();
    return 0;
}
