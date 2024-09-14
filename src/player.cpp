#include "player.hpp"
#include "functions.hpp"

void Player::render(RenderWindow &Window)
{
    Window.draw(sprite);
}
Player::Player(int x, int y)
{
    pos = Vector2f(x, y);
}
Player::~Player()
{
}

void Player ::update(Vector2i p)
{

    if (is_tagged)
    {
        Vector2f target(static_cast<float>(p.x - PLANTS_IMAGE_MIDDLE), static_cast<float>(p.y - PLANTS_IMAGE_MIDDLE));
        sprite.setPosition(target);
    }
}
void Player ::set_handler(Handler *h)
{

    handler = h;
    plant_sett = handler->get_plant_sett();
    zomb_sett = handler->get_zomb_sett();
    sun_sett = handler->get_zomb_sett();
    NOKHOOD_HEALTH = plant_sett[0][0];
    NOKHOOD_PRODOCTION_RATE = plant_sett[0][1];
    NOKHOOD_COOLDOWN = plant_sett[0][2];
    NOKHOOD_DAMAGE = plant_sett[0][3];
    NOKHOOD_DAMAGE_RATE = plant_sett[0][4];

    SUNFLOWER_HEALTH = plant_sett[1][0];
    SUNFLOWER_PRODUCTION_RATE == plant_sett[1][1];
    SUNFLOWER_COOLDOWN = plant_sett[1][2];

    SNOW_HEALTH = plant_sett[2][0];
    SNOW_PRODOCTION_RATE = plant_sett[2][1];
    SNOW_COOLDOWN = plant_sett[2][2];
    SNOW_DAMAGE = plant_sett[2][3];
    SNOW_DAMAGE_RATE = plant_sett[2][4];

    POTATO_HEALTH = plant_sett[3][0];
    POTATO_PRODOCTION_RATE = plant_sett[3][1];
    POTATO_COOLDOWN = plant_sett[3][2];

    MELON_HEALTH = plant_sett[4][0];
    MELLON_DAMAGE = plant_sett[4][1];
    MELLON_SPEED = plant_sett[4][2];
    MELON_COOLDOWN = plant_sett[4][3];
}
void Player::handle_mouse_press(Vector2i p)
{
    if (!is_tagged)
    {
        handler->checking_click_on_sun({p.x, p.y});
        if ((p.x >= snow_left && p.x <= snow_right &&
             p.y >= snow_top && p.y <= snow_bottom) &&
            (handler->total_money >= snow_value))
        {
            Time cooldown_elapsed = snow_clock.getElapsedTime();
            if (cooldown_elapsed.asMilliseconds() >= SNOW_COOLDOWN || first_time_snow)
            {
                snow_clock.restart();
                handler->total_money -= snow_value;
                plant_being_grown = new Snow(plant_sett, p.x + PLANTS_IMAGE_MIDDLE, p.y + PLANTS_IMAGE_MIDDLE);
                sprite = plant_being_grown->geting_sprite();
                is_tagged = true;
                first_time_snow = false;
            }
        }
        if ((p.x >= nokhood_left && p.x <= nokhood_right &&
             p.y >= nokhood_top && p.y <= nokhood_bottom) &&
            (handler->total_money >= nokhood_value))
        {
            Time n_elapsed = sunflower_clock.getElapsedTime();
            if (n_elapsed.asMilliseconds() >= NOKHOOD_COOLDOWN || first_time_nokhod)
            {
                sunflower_clock.restart();
                handler->total_money -= nokhood_value;
                plant_being_grown = new Nokhood(plant_sett, p.x + PLANTS_IMAGE_MIDDLE, p.y + PLANTS_IMAGE_MIDDLE);
                sprite = plant_being_grown->geting_sprite();
                is_tagged = true;
                first_time_nokhod = false;
            }
        }

        if ((p.x >= sunflower_left && p.x <= sunflower_right &&
             p.y >= sunflower_top && p.y <= sunflower_bottom) &&
            (handler->total_money >= sunflower_value))
        {
            Time su_elapsed = sunflower_clock.getElapsedTime();
            if (su_elapsed.asMilliseconds() >= SUNFLOWER_COOLDOWN || first_time_sunflower)
            {
                sunflower_clock.restart();
                handler->total_money -= sunflower_value;
                plant_being_grown = new Sunflower(plant_sett, p.x + PLANTS_IMAGE_MIDDLE, p.y + PLANTS_IMAGE_MIDDLE);
                sprite = plant_being_grown->geting_sprite();
                is_tagged = true;
                first_time_sunflower = false;
            }
        }
        if ((p.x >= potato_left && p.x <= potato_right && p.y >= potato_top && p.y <= potato_bottom) && (handler->total_money >= potato_value))
        {
            Time p_elapsed = sunflower_clock.getElapsedTime();
            if (p_elapsed.asMilliseconds() >= POTATO_COOLDOWN || first_time_potato)
            {
                sunflower_clock.restart();
                handler->total_money -= potato_value;
                plant_being_grown = new Potato(plant_sett, p.x + PLANTS_IMAGE_MIDDLE, p.y + PLANTS_IMAGE_MIDDLE);
                sprite = plant_being_grown->geting_sprite();
                is_tagged = true;
                first_time_potato = false;
            }
        }
        if ((p.x >= melon_left && p.x <= melon_right &&
             p.y >= melon_top && p.y <= melon_bottom) &&
            (handler->total_money >= melon_value))
        {
            Time m_elapsed = melon_clock.getElapsedTime();
            if (m_elapsed.asMilliseconds() >= MELON_COOLDOWN || first_time_melon)
            {
                melon_clock.restart();
                handler->total_money -= melon_value;
                plant_being_grown = new Melon(plant_sett, p.x + PLANTS_IMAGE_MIDDLE, p.y + PLANTS_IMAGE_MIDDLE);
                sprite = plant_being_grown->geting_sprite();
                is_tagged = true;
                first_time_melon = false;
            }
        }
    }
    else
    {
        if (p.x < ((9) * 81 + 135))
        {

            Vector2f plant_placed_location = plant_place_to_grow(p.x, p.y);
            if (!handler->check_planted_plants({plant_placed_location.x + PLANTS_IMAGE_MIDDLE, plant_placed_location.y + PLANTS_IMAGE_MIDDLE}))
            {
                plant_being_grown->finished_position(plant_placed_location);
                handler->new_plant(plant_being_grown);
                is_tagged = !is_tagged;
            }
        }
    }
}
bool Player::is_tagged_or_no()
{
    return is_tagged;
}
