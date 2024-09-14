#pragma once

#include "global.hpp"

class Zombie
{
public:
  Zombie(vector<float> zs, int x, int y);
  ~Zombie();
  void render(RenderWindow &window);
  void update();
  Vector2f get_pos();
  void damage_taken(float d);
  bool check_health();
  float get_damage();
  virtual bool same_row(float y);
  virtual bool same_collum(float x);
  bool take_damage(Vector2f p);
  void plant_eaten();
  float get_speed();
  void zombie_freezing();

protected:
  float ZOMBIE_HEALTH, ZOMBIE_DAMAGE, ZOMBIE_SPEED, ZOMBIE_DAMAGE_RATE;
  float BIG_ZOMBIE_HEALTH, BIG_ZOMBIE_DAMAGE, BIG_ZOMBIE_SPEED, BIG_ZOMBIE_DAMAGE_RATE;
  bool reached_plant = false;
  Clock z_clock;
  Clock freez_zombie;
  float health;
  float damage;
  float speed;
  int damage_cooldown;
  Clock clock;
  IntRect rect;
  Texture texture;
  Sprite sprite;
  bool freezed = false;
  Vector2f pos;
};
class Normal_zambie : public Zombie
{
public:
  Normal_zambie(vector<float> zs, int x, int y);
  bool same_row(float y);
  bool same_collum(float x);

private:
};
class Big_zombie : public Zombie
{
public:
  Big_zombie(vector<float> zs, int x, int y);
  bool same_row(float y);
  bool same_collum(float x);

private:
};
