#pragma once

#include "global.hpp"
#include "sun.hpp"
class Plant
{
public:
    Plant(vector<vector<float>> ps, int x, int y);
    void finished_position(Vector2f p);
    void render(RenderWindow &window);
    Vector2f get_pos();
    Sprite geting_sprite();
    virtual bool update();
    string Type;
    bool placed_or_no = false;
    bool taking_damage(float d);
    bool in_plant_pos(Vector2f p);

protected:
    float NOKHOOD_HEALTH, NOKHOOD_PRODOCTION_RATE, NOKHOOD_COOLDOWN, NOKHOOD_DAMAGE, NOKHOOD_DAMAGE_RATE;
    float SUNFLOWER_HEALTH, SUNFLOWER_PRODUCTION_RATE, SUNFLOWER_COOLDOWN;
    float SNOW_HEALTH, SNOW_PRODOCTION_RATE, SNOW_COOLDOWN, SNOW_DAMAGE, SNOW_DAMAGE_RATE;
    float POTATO_HEALTH, POTATO_PRODOCTION_RATE, POTATO_COOLDOWN;
    float MELON_HEALTH, MELLON_DAMAGE, MELLON_SPEED, MELON_COOLDOWN;
    Clock clock;
    int price;
    int cooldown;
    float health;
    IntRect rect;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
class Shooter : public Plant
{
protected:
    Shooter(vector<vector<float>> ps, int x, int y);

protected:
    float tir_speed = TIR_SPEED;
    float fire_rate = NOKHOOD_DAMAGE_RATE;
    float damage = NOKHOOD_DAMAGE;
};
class Snow : public Shooter
{
public:
    Snow(vector<vector<float>> ps, int x, int y);
    bool update();
};
class Nokhood : public Shooter
{
public:
    Nokhood(vector<vector<float>> ps, int x, int y);
    bool update();

private:
};
class Sunflower : public Plant
{
public:
    Sunflower(vector<vector<float>> ps, int x, int y);
    bool update();

private:
    float production_rate = SUNFLOWER_PRODUCTION_RATE;
};
class Potato : public Plant
{
public:
    Potato(vector<vector<float>> ps, int x, int y);

private:
};
class Melon : public Plant
{
public:
    Melon(vector<vector<float>> ps, int x, int y);
    bool update();

private:
};
