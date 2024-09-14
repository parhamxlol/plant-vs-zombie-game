#include "sun.hpp"
#include "global.hpp"
Vector2f Sun::get_pos()
{
    return pos;
}
Sun::Sun(vector<float> ss, int x, int y, int v)
{
    pos.x = x;
    pos.y = y;
    value = v;
    SUN_SPAWN_RATE = ss[0];
    if (!texture.loadFromFile(PICS_PATH + SUN_PATH))
    {
    }
    rect.top = 24;
    rect.left = 329;
    rect.width = 595 - 329;
    rect.height = 301 - 24;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(0.3, 0.3);
    sprite.setPosition(pos);
}
void Sun::render(RenderWindow &window)
{
    window.draw(sprite);
}
bool Sun::position_in_sprite(Vector2f p)
{
    Vector2f spritePos = sprite.getPosition();
    Vector2f spriteSize = {sprite.getTextureRect().width * 0.3f, sprite.getTextureRect().height * 0.3f};
    if (p.x >= spritePos.x && p.x <= spritePos.x + spriteSize.x &&
        p.y >= spritePos.y && p.y <= spritePos.y + spriteSize.y)
    {
        return true;
    }
    else
        return false;
}
void Sun::update()
{
    Time selapsed = s_clock.getElapsedTime();
    if (!placed_or_no && (selapsed.asMilliseconds() >= 20))
    {
        pos.y += SUN_FALLING_SPEED;
        s_clock.restart();
    }
    sprite.setPosition(pos);
}
Sun::~Sun()
{
}