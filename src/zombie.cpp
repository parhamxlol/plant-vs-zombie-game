#include "zombie.hpp"

Vector2f Zombie::get_pos()
{
   return pos;
}
Zombie::Zombie(vector<float> zs, int x, int y)
{
   ZOMBIE_HEALTH = zs[0];
   ZOMBIE_DAMAGE = zs[1];
   ZOMBIE_SPEED = zs[2];
   ZOMBIE_DAMAGE_RATE = zs[3];
   BIG_ZOMBIE_HEALTH = zs[4];
   BIG_ZOMBIE_DAMAGE = zs[5];
   BIG_ZOMBIE_SPEED = zs[6];
   BIG_ZOMBIE_DAMAGE_RATE = zs[7];
   pos.x = x;
   pos.y = y;
}
Normal_zambie::Normal_zambie(vector<float> zs, int x, int y) : Zombie(zs, x, y)
{
   if (!texture.loadFromFile(PICS_PATH + ZOMBIE_IMG))
   {
      debug("zombie image load faild")
   }
   // rect.top=0;
   // rect.left=0;
   // rect.width=40;
   // rect.height=60;

   sprite.setTexture(texture);
   // sprite.setTextureRect(rect);
   sprite.setScale(0.21, 0.21);
   sprite.setPosition(pos);
   health = ZOMBIE_HEALTH;
   damage = ZOMBIE_DAMAGE;
   speed = ZOMBIE_SPEED;
   damage_cooldown = ZOMBIE_DAMAGE_RATE;
}
Big_zombie::Big_zombie(vector<float> zs, int x, int y) : Zombie(zs, x, y)
{

   if (!texture.loadFromFile(PICS_PATH + BIG_ZOMBIE_IMG))
   {
      debug("Big_zombie image load faild")
   }
   // rect.top=0;
   // rect.left=0;
   // rect.width=40;
   // rect.height=60;

   sprite.setTexture(texture);
   // sprite.setTextureRect(rect);
   sprite.setScale(0.4, 0.4);
   sprite.setPosition(pos);
   health = BIG_ZOMBIE_HEALTH;
   damage = BIG_ZOMBIE_DAMAGE;
   speed = BIG_ZOMBIE_SPEED;
   damage_cooldown = BIG_ZOMBIE_DAMAGE_RATE;
}

void Zombie::render(RenderWindow &window)
{
   window.draw(sprite);
}
void Zombie::update()
{
   Time selapsed = z_clock.getElapsedTime();
   Time felapsed = freez_zombie.getElapsedTime();
   if (felapsed.asMilliseconds() >= 5000 && freezed)
   {
      speed *= 2;
      freezed = false;
   }
   if (!reached_plant && (selapsed.asMilliseconds() >= 20))
   {
      z_clock.restart();
      pos.x -= speed;
   }
   sprite.setPosition(pos);
}
Zombie::~Zombie()
{
}
bool Big_zombie::same_row(float y)
{
   if (y >= pos.y && (y <= pos.y + 302 * 0.4))
   {
      return true;
   }
   else
      return false;
}
bool Big_zombie::same_collum(float x)
{
   if (x >= pos.x && (x <= pos.x + 250 * 0.4))
   {
      return true;
   }

   else
      return false;
}

bool Normal_zambie::same_row(float y)
{
   if (y >= pos.y && (y <= pos.y + 505 * 0.21))
   {
      return true;
   }
   else
      return false;
}
bool Normal_zambie::same_collum(float x)
{
   if (x >= pos.x && (x <= pos.x + 494 * 0.21))
   {
      return true;
   }

   else
      return false;
}
void Zombie::damage_taken(float d)
{
   health -= d;
}
bool Zombie::same_collum(float x)
{
}
bool Zombie::same_row(float y)
{
}
bool Zombie::check_health()
{
   if (health <= 0)
      return true;
   else
      return false;
}
float Zombie ::get_damage()
{
   return damage;
}
bool Zombie::take_damage(Vector2f p)
{
   Time zelapsed = clock.getElapsedTime();
   if (same_collum(p.x) && same_row(p.y) && (zelapsed.asMilliseconds() >= damage_cooldown))
   {
      clock.restart();
      reached_plant = true;
      return true;
   }
   return false;
}
void Zombie::plant_eaten()
{
   reached_plant = false;
}
float Zombie::get_speed()
{
   if (reached_plant)
   {
      return 0;
   }
   return speed;
}
void Zombie::zombie_freezing()
{
   if (!freezed)
   {
      speed *= 0.5;
      freezed = true;
   }
   freez_zombie.restart();
}
