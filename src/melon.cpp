#include "melon.hpp"

Vector2f Mellon_bullet::get_pos()
{
    return pos;
}
Mellon_bullet::Mellon_bullet(float dm,Vector2f p, Vector2f z, float zp) 
{
    pos = p;
    start = p.x;
    zombie_target = z;
    float distance = (z.x - pos.x);
    x_target = start + speed * distance / (speed + zp);

    if (!texture.loadFromFile(PICS_PATH + "melon.png"))
    {
        debug("Mellon_bullet image load faild")
    }
    rect.top = 0;
    rect.left = 0;
    rect.width = 158;
    rect.height = 113;

    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(0.3, 0.3);
    sprite.setPosition(pos);
    damage = dm;
    type = "mellon";
}
void Mellon_bullet::render(RenderWindow &window)
{
    window.draw(sprite);
}
bool Mellon_bullet::update()
{
    Time selapsed = m_clock.getElapsedTime();
    if ((selapsed.asMilliseconds() >= 20))
    {
        m_clock.restart();
        pos.x += speed;
        if (pos.x >= ((x_target - start) * 0.5 + start))
        {
            pos.y += up_speed;
        }
        else
        {
            pos.y -= up_speed;
        }
    }
    sprite.setPosition(pos);
    if (pos.x >= x_target)
    {
        return true;
    }
    else
        return false;
}
