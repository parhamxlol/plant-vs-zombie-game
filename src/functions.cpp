#include "functions.hpp"

int random_number(int min, int max)
{
    random_device rd;

    std::mt19937 gen(rd());
    int lower_bound = min;

    int upper_bound = max;

    std::uniform_int_distribution<int> distribution(lower_bound, upper_bound);
    int random_number = distribution(gen);
    return random_number;
}
Vector2f plant_place_to_grow(int x, int y)
{
    int row = 1, collum = 1;
    while (1)
    {
        if (y <= (row) * 98 + 75)
            break;
        row++;
    }
    while (1)
    {
        if (x <= ((collum) * 81 + 135))
            break;
        collum++;
    }

    return {(collum - 1) * 81 + 137, (row - 1) * 98 + 80};
}