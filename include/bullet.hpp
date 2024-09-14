#pragma once

#include "global.hpp"

class Bullet{
    public:
    Bullet(vector<vector<float>> ps,int x,int y);
    ~Bullet();
    void render(RenderWindow &window);
    void update();
    Vector2f get_pos();
    string get_type(){return type;}
    float damage;
    Vector2f pos; 

    protected:
    float NOKHOOD_DAMAGE;
    float SNOW_DAMAGE;
    Clock b_clock;
    string type;
    Clock clock;
    IntRect rect;
    float speed = BULLET_SPEAD;
    Texture texture;
    Sprite sprite;
};
class Snow_bullet: public Bullet{
  public:
  Snow_bullet(vector<vector<float>> ps,int x , int y);
  private:
};
class Nokhood_bullet: public Bullet{
  public:
  Nokhood_bullet(vector<vector<float>> ps,int x , int y);
  private:


};
