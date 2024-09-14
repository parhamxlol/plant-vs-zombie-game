#include "plant.hpp"

Vector2f Plant::get_pos()
{
    return pos;
}
Plant::Plant(vector<vector<float>> ps, int x, int y)
{
    NOKHOOD_HEALTH = ps[0][0];
    NOKHOOD_PRODOCTION_RATE = ps[0][1];
    NOKHOOD_COOLDOWN = ps[0][2];
    NOKHOOD_DAMAGE = ps[0][3];
    NOKHOOD_DAMAGE_RATE = ps[0][4];

    SUNFLOWER_HEALTH = ps[1][0];
    SUNFLOWER_PRODUCTION_RATE = ps[1][1];
    SUNFLOWER_COOLDOWN = ps[1][2];

    SNOW_HEALTH = ps[2][0];
    SNOW_PRODOCTION_RATE = ps[2][1];
    SNOW_COOLDOWN = ps[2][2];
    SNOW_DAMAGE = ps[2][3];
    SNOW_DAMAGE_RATE = ps[2][4];

    POTATO_HEALTH=ps[3][0];
    POTATO_PRODOCTION_RATE=ps[3][1];
    POTATO_COOLDOWN=ps[3][2];

    MELON_HEALTH=ps[4][0];
    MELLON_DAMAGE=ps[4][1];
    MELLON_SPEED=ps[4][2];
    MELON_COOLDOWN=ps[4][3];

    pos.x = x;
    pos.y = y;
}
void Plant::render(RenderWindow &window)
{
    window.draw(sprite);
}
Sprite Plant ::geting_sprite()
{
    return sprite;
}
void Plant::finished_position(Vector2f p)
{
    pos = p;
    placed_or_no = true;
    sprite.setPosition(pos);
}
Shooter::Shooter(vector<vector<float>> ps, int x, int y) : Plant(ps, x, y)
{
}
Snow::Snow(vector<vector<float>> ps, int x, int y) : Shooter(ps, x, y)
{
    Type = "Snow";
    if (!texture.loadFromFile(PICS_PATH + "snow.png"))
    {
    }
    rect.top = 0;
    rect.left = 0;
    rect.width = 1200;
    rect.height = 968;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(0.075, 0.078);
    health = SNOW_HEALTH;
}
Nokhood::Nokhood(vector<vector<float>> ps, int x, int y) : Shooter(ps, x, y)
{
    if (!texture.loadFromFile(PICS_PATH + "plant.png"))
    {
    }
    Type = "Nokhood";
    rect.top = 0;
    rect.left = 0;
    rect.width = 442;
    rect.height = 446;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(0.17, 0.16);
    health = NOKHOOD_HEALTH;
}
Sunflower::Sunflower(vector<vector<float>> ps, int x, int y) : Plant(ps, x, y)
{
    Type = "Sunflower";
    if (!texture.loadFromFile(PICS_PATH + "sunflower.png"))
    {
    }
    rect.top = 0;
    rect.left = 0;
    rect.width = 211;
    rect.height = 238;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(0.35, 0.3);
    health = SUNFLOWER_HEALTH;
}
Potato::Potato(vector<vector<float>> ps, int x, int y) : Plant(ps, x, y)
{
    if (!texture.loadFromFile(PICS_PATH + "potato1.png"))
    {
    }
    Type = "Potato";
    rect.top = 0;
    rect.left = 0;
    rect.width = 149;
    rect.height = 182;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(0.45, 0.39);
    health = POTATO_HEALTH;
}
bool Plant ::update()
{
    sprite.setPosition(pos);
    return false;
}
bool Sunflower::update()
{
    sprite.setPosition(pos);
    Time pelapsed = clock.getElapsedTime();
    if (pelapsed.asMilliseconds() >= SUNFLOWER_PRODUCTION_RATE)
    {
        clock.restart();
        return true;
    }
    else
        return false;
}
bool Nokhood::update()
{
    sprite.setPosition(pos);
    Time pelapsed = clock.getElapsedTime();
    if (pelapsed.asMilliseconds() >= NOKHOOD_DAMAGE_RATE)
    {
        clock.restart();
        return true;
    }
    else
        return false;
}
bool Snow::update()
{
    sprite.setPosition(pos);
    Time pelapsed = clock.getElapsedTime();
    if (pelapsed.asMilliseconds() >= SNOW_DAMAGE_RATE)
    {
        clock.restart();
        return true;
    }
    else
        return false;
}
bool Melon::update()
{
    sprite.setPosition(pos);
    Time pelapsed = clock.getElapsedTime();
    if (pelapsed.asMilliseconds() >= SNOW_DAMAGE_RATE)
    {
        clock.restart();
        return true;
    }
    else
        return false;
}
bool Plant::in_plant_pos(Vector2f p)
{
    if (p.x >= pos.x && p.x <= (pos.x + 2 * PLANTS_IMAGE_MIDDLE) && p.y >= pos.y && p.y <= (pos.y + 2 * PLANTS_IMAGE_MIDDLE))
    {
        return true;
    }
    else
        return false;
}
bool Plant::taking_damage(float d)
{
    health -= d;
    if (health <= 0)
        return true;
    else
        return false;
}

Melon::Melon(vector<vector<float>> ps, int x, int y) : Plant(ps, x, y)
{
    if (!texture.loadFromFile(PICS_PATH + "melonplant.png"))
    {
    }
    Type = "Melon";
    rect.top = 0;
    rect.left = 0;
    rect.width = 499;
    rect.height = 499;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(0.15, 0.15);
    health = MELON_HEALTH;
}
