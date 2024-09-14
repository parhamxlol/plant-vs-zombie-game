#pragma once

#include "global.hpp"
#include "zombie.hpp"
#include "functions.hpp"
#include "sun.hpp"
#include "plant.hpp"
#include "bullet.hpp"
#include "melon.hpp"
#include <string>
class Handler
{
private:
    vector<vector<float>> plant_sett;
    vector<float> zomb_sett;
    vector<float> sun_sett;
     int TOTAL_TIME, FIRST_WAVE_TIME, SECOND_WAVE_TIME;
    Clock big_zombie_clock, normal_zombie_clock, sun_clock, freez_clock;
    vector<Zombie *> zombies;
    vector<Sun *> suns;
    vector<Plant *> plants;
    vector<Bullet *> bullets;
    bool game_end = false;
    vector<Bullet *> snow_bullets;
    vector<Bullet *> nokhood_bullets;
    vector<Mellon_bullet *> mellon_bullets;
    Clock clock;
    int number_of_waves = 1;
    Clock total_time;
    bool freezed = false;
    void melon_strike();
    void bullet_strike();
    void zombie_spawn();
    void end_ckeck();
    void sun_check();
    void plants_check();
    void zombie_check();

public:
    vector<vector<float>> get_plant_sett()
    {
        return plant_sett;
    }
    vector<float> get_zomb_sett()
    {
        return zomb_sett;
    }
    vector<float> get_sun_sett()
    {
        return sun_sett;
    }
    void reading_from_file();
    Handler();
    void update();
    bool won_or_no();
    bool check_planted_plants(Vector2f p);
    int get_total_money() { return total_money; }
    int total_money = TOTAL_MONEY;
    void render(RenderWindow &window);
    void new_zombie(Zombie *z);
    void new_sun(Sun *s);
    void new_plant(Plant *p);
    bool game_ended();
    void new_bullet(Bullet *b);
    void new_mellon_bullet(Mellon_bullet *m);
    void checking_click_on_sun(Vector2f p);
};