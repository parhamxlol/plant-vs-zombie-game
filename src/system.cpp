#include "system.hpp"

System::System(int width, int height)
{
  window.create(VideoMode(width, height), WINDOW_HEADER_NAME, Style::Default);
  state = IN_GAME;
  handler = new Handler();
  handler->reading_from_file();
  player = new Player(100, 100);
    player->set_handler(handler);

  if (!backgroundTexture.loadFromFile(PICS_PATH + BACKGROUND_IMG))
    debug("failed to load bg image");
  if (!sunbarTexture.loadFromFile(PICS_PATH + SUN_BAR))
    debug("failed to load sun_bar image");
  if (!nokhoodTexture.loadFromFile(PICS_PATH + NOKHOOD_SHOTER_OPT_IMG))
    debug("failed to load nokhood_opt image");
  if (!snowTexture.loadFromFile(PICS_PATH + SNOW_SHOTR_OPT_IMG))
    debug("failed to load snow_opt image");
  if (!sunflowerTexture.loadFromFile(PICS_PATH + SUNFLIWER_OPT_IMG))
    debug("failed to load sunflower_opt image");
  if (!pototoTexture.loadFromFile(PICS_PATH + POTATO_OPT_IMG))
    debug("failed to load potato_opt image");
  if (!gameoverTexture.loadFromFile(PICS_PATH + GAMEOVER_IMG))
    debug("failed to load GAMEOVER image");
  if (!melonTexture.loadFromFile(PICS_PATH + MELON_OPT_IMG))
    debug("failed to load melon_opt image");
  if (!winTexture.loadFromFile(PICS_PATH + WIN_IMG))
    debug("failed to load win image");
  backgroundSprite.setTexture(backgroundTexture);
  sunbarSprite.setTexture(sunbarTexture);
  sunflowerSprite.setTexture(sunflowerTexture);
  nokhoodSprite.setTexture(nokhoodTexture);
  snowSprite.setTexture(snowTexture);
  potatoSprite.setTexture(pototoTexture);
  melonSprite.setTexture(melonTexture);
  gameoverSprite.setTexture(gameoverTexture);
  winSprite.setTexture(winTexture);

  sunbarSprite.setPosition(10, 8);
  sunflowerSprite.setPosition(10, 75);
  nokhoodSprite.setPosition(10, 155);
  snowSprite.setPosition(10, 235);
  potatoSprite.setPosition(10, 315);
  melonSprite.setPosition(10, 395);

  sunbarSprite.setScale(0.028f, 0.031f);
  sunflowerSprite.setScale(0.125f, 0.135f);
  nokhoodSprite.setScale(0.033f, 0.036f);
  snowSprite.setScale(0.033f, 0.036f);
  potatoSprite.setScale(0.033f, 0.036f);
  melonSprite.setScale(0.11f, 0.11f);

  gameoverSprite.setPosition(0, 0);
  gameoverSprite.setScale(1.66, 1.3);
  winSprite.setPosition(0, 0);
  winSprite.setScale(0.85, 0.61);
  if (!font.loadFromFile(FONTS_PATH + FONT_ADD))
    debug("FONT load faild");

  text.setFont(font);

  text.setCharacterSize(42);

  text.setFillColor(sf::Color::Black);

  text.setPosition(64, -1);
  if (!music.openFromFile(AUDIO_PATH + BACKGROUND_AUDIO))
    debug("failed to load music");

  music.setLoop(true);
  music.play();
}
void System::run()
{
  while (window.isOpen())
  {
    update();
    render();
    handle_events();
   bool status_of_win= handler->won_or_no();
    if (handler->game_ended())
    {
      if (!status_of_win)
      {
        while (window.isOpen())
        {
          window.draw(gameoverSprite);
          handle_events();
          window.display();
        }
      }
      else
      {
        while (window.isOpen())
        {
          window.draw(winSprite);
          handle_events();
          window.display();
        }
      }
    }
  }
}
void System::set_total_money_text()
{
  string numberStr = to_string(handler->get_total_money()); // تبدیل عدد به رشته
  text.setString(numberStr);
}
void System::handle_events()
{
  switch (IN_GAME)
  {
  case (IN_GAME):
    Event event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
      case (Event::Closed):
        window.close();
        break;
      case (Event::MouseButtonPressed):
        handle_mouse_press(event);
        break;
      case (Event::MouseButtonReleased):
        break;
      default:
        break;
      }
    }
    break;
  case (PAUSE_MENU):
    break;
  case (MAIN_MENU):
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  case (EXIT):
    break;
  }
}
void System::render()
{
  window.clear();
  switch (state)
  {
  case (IN_GAME):
    window.draw(backgroundSprite);
    window.draw(sunflowerSprite);
    window.draw(nokhoodSprite);
    window.draw(snowSprite);
    window.draw(potatoSprite);
    window.draw(sunbarSprite);
    window.draw(melonSprite);

    set_total_money_text();
    window.draw(text);
    if (player->is_tagged_or_no())
      player->render(window);
    handler->render(window);

    break;
  case (PAUSE_MENU):
    break;
  case (MAIN_MENU):
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    window.draw(gameoverSprite);
    break;
  case (EXIT):
    break;
  }

  Event event;
  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window.close();
  }

  window.display();
}

void System::update()
{
    handler->update();
    Vector2i mousePos = Mouse::getPosition(window);
    Vector2f worldPos = window.mapPixelToCoords(mousePos);
    player->update(Vector2i(worldPos.x, worldPos.y));
}

void System::handle_mouse_press(Event ev)
{
  if (ev.mouseButton.button == Mouse::Right)
    return;
  Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
  switch (state)
  {
  case (IN_GAME):{

    // player->handle_mouse_press(pos);
    Vector2i mousePos = Mouse::getPosition(window);
    Vector2f worldPos = window.mapPixelToCoords(mousePos);
    player->handle_mouse_press(Vector2i(worldPos.x, worldPos.y));
    break;
  }
  case (PAUSE_MENU):
    break;
  case (MAIN_MENU):
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
}