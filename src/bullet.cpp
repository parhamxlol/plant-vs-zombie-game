#include "bullet.hpp"
Vector2f Bullet::get_pos()
{
    return pos;
}
Bullet::Bullet(vector<vector<float>> ps,int x, int y)
{
    SNOW_DAMAGE=ps[2][3];
    NOKHOOD_DAMAGE=ps[0][3];
    pos.x = x;
    pos.y = y;
}
void Bullet::render(RenderWindow &window)
{
    window.draw(sprite);
}
void Bullet::update()
{
    Time selapsed = b_clock.getElapsedTime();
    if ((selapsed.asMilliseconds() >= 20))
    {
        b_clock.restart();
        pos.x += speed;
    }
    sprite.setPosition(pos);
}
Bullet::~Bullet()
{
}
Nokhood_bullet::Nokhood_bullet(vector<vector<float>> ps,int x, int y) : Bullet(ps,x, y)
{
    if (!texture.loadFromFile(PICS_PATH + "nokhod_bullet.png"))
    {
        debug("bullet image load faild")
    }
    rect.top = 0;
    rect.left = 0;
    rect.width = 220;
    rect.height = 220;

    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(0.16, 0.16);
    sprite.setPosition(pos);
    damage = NOKHOOD_DAMAGE;
    type = "nokhood";
}
Snow_bullet::Snow_bullet(vector<vector<float>> ps,int x, int y) : Bullet(ps,x, y)
{
    if (!texture.loadFromFile(PICS_PATH + "ice_bullet.png"))
    {
        debug("bullet image load faild")
    }
    rect.top = 0;
    rect.left = 0;
    rect.width = 24;
    rect.height = 24;

    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(1.46, 1.46);
    sprite.setPosition(pos);
    damage = SNOW_DAMAGE;
    type = "snow";
}