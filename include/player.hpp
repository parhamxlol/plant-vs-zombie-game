#pragma once

#include "global.hpp"
#include "plant.hpp"
#include "handler.hpp"

class Player
{
public:
    Player(int x, int y);
    ~Player();
    void render(RenderWindow &window);
    void update(Vector2i pos);
    void handle_mouse_press(Vector2i pos);
    // void handle_mouse_release(Vector2i pos);
    void set_handler(Handler *h);
    bool is_tagged_or_no();

private:
    vector<vector<float>> plant_sett;
    vector<float> zomb_sett;
    vector<float> sun_sett;
    float NOKHOOD_HEALTH, NOKHOOD_PRODOCTION_RATE, NOKHOOD_COOLDOWN, NOKHOOD_DAMAGE, NOKHOOD_DAMAGE_RATE;
    float SUNFLOWER_HEALTH, SUNFLOWER_PRODUCTION_RATE, SUNFLOWER_COOLDOWN;
    float SNOW_HEALTH, SNOW_PRODOCTION_RATE, SNOW_COOLDOWN, SNOW_DAMAGE, SNOW_DAMAGE_RATE;
    float POTATO_HEALTH, POTATO_PRODOCTION_RATE, POTATO_COOLDOWN;
    float MELON_HEALTH, MELLON_DAMAGE, MELLON_SPEED, MELON_COOLDOWN;
    Texture texture;
    Handler *handler;
    Sprite sprite;
    IntRect rect;
    Vector2f pos;
    Plant *plant_being_grown;
    bool is_tagged = false;
    Clock sunflower_clock;
    Clock potato_clock;
    Clock nokhod_clock;
    Clock snow_clock;
    Clock melon_clock;

    bool first_time_melon = true;
    bool first_time_sunflower = true;
    bool first_time_snow = true;
    bool first_time_nokhod = true;
    bool first_time_potato = true;
    void fix_position();
};