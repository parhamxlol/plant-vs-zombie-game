#pragma once

#include "global.hpp"
#include "player.hpp"
#include "handler.hpp"

enum State
{
  IN_GAME,
  PAUSE_MENU,
  MAIN_MENU,
  VICTORY_SCREEN,
  GAMEOVER_SCREEN,
  EXIT
};

class System
{
public:
  System(int width, int height);
  void run();
  RenderWindow window;

private:
  Clock clock;
  Font font;
  Text text;
  State state;
  Player *player;
  Handler *handler;
  Texture backgroundTexture;
  Sprite backgroundSprite;
  Texture sunbarTexture;
  Texture sunflowerTexture;
  Texture nokhoodTexture;
  Texture snowTexture;
  Texture pototoTexture;
  Texture gameoverTexture;
  Texture winTexture;
  Texture melonTexture;
  Sprite melonSprite;

  Sprite gameoverSprite;
  Sprite winSprite;

  Sprite sunbarSprite;
  Sprite sunflowerSprite;
  Sprite nokhoodSprite;
  Sprite snowSprite;
  Sprite potatoSprite;
  Music music;
  void set_total_money_text();
  void update();
  void render();
  void handle_events();
  void handle_mouse_press(Event ev);
};
