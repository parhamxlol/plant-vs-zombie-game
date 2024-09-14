#pragma once

#include "global.hpp"

class Mellon_bullet
{
public:
    Mellon_bullet(float dm, Vector2f p, Vector2f z, float zs);
    void render(RenderWindow &window);
    bool update();
    Vector2f get_pos();
    string get_type() { return type; }
    float get_damage() { return damage; }
    Vector2f pos;

private:
    string type;
    float x_target;
    float damage;
    Clock clock;
    Clock m_clock;
    float start;
    float up_speed = 2.5;
    float middle;
    IntRect rect;
    float speed = 13;
    Texture texture;
    Sprite sprite;
    Vector2f zombie_target;
};