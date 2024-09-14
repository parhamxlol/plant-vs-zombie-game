#pragma once

#include "global.hpp"

class Sun
{
public:
    Sun(vector<float> ss, int x, int y, int v);
    ~Sun();
    void render(RenderWindow &window);
    void update();
    Vector2f get_pos();
    int value;
    bool position_in_sprite(Vector2f p);
    bool placed_or_no = false;

private:
    float SUN_SPAWN_RATE, VALUE;
    Clock s_clock;
    Clock clock;
    IntRect rect;
    float speed = SUN_FALLING_SPEED;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};