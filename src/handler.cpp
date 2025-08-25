#include "handler.hpp"

Handler::Handler()
{
    total_time.restart();
}
void Handler::zombie_spawn()
{
    Time total_time_ = total_time.getElapsedTime();
    if (total_time_.asSeconds() < FIRST_WAVE_TIME)
    {
        Time zelapsed = normal_zombie_clock.getElapsedTime();
        if (zelapsed.asMilliseconds() >= ZOMBIE_TIME_SPAWN)
        {
            normal_zombie_clock.restart();
            int zombie_row = random_number(1, NUMBER_ZOMBIE_ROW);
            Zombie *z;
            z = new Normal_zambie(zomb_sett, 950, 98 * zombie_row + 75 - 116);
            new_zombie(z);
        }
    }
    if ((FIRST_WAVE_TIME <= total_time_.asSeconds() ) && (total_time_.asSeconds()< SECOND_WAVE_TIME))
    {
        Time zelapsed = normal_zombie_clock.getElapsedTime();
        if (zelapsed.asMilliseconds() >= ZOMBIE_TIME_SPAWN)
        {
            normal_zombie_clock.restart();
            int zombie_row = random_number(1, NUMBER_ZOMBIE_ROW);
            Zombie *z;
            z = new Normal_zambie(zomb_sett, 950, 98 * zombie_row + 75 - 116);
            new_zombie(z);
        }
    }
    if ((SECOND_WAVE_TIME <= total_time_.asSeconds()) && (total_time_.asSeconds() <= TOTAL_TIME))
    {
      Time zelapsed = normal_zombie_clock.getElapsedTime();
    if(zelapsed.asMilliseconds() >= ZOMBIE_TIME_SPAWN){
        normal_zombie_clock.restart();
        int zombie_row=random_number(1, NUMBER_ZOMBIE_ROW);
        Zombie *z;
        z= new Normal_zambie(zomb_sett,950,98*zombie_row + 75 - 116);
        new_zombie(z);
    }

    Time B_zelapsed = big_zombie_clock.getElapsedTime();
    if(B_zelapsed.asMilliseconds() >= BIG_ZOMBIE_TIME_SPAWN){
        big_zombie_clock.restart();
        int zombie_row=random_number(1, NUMBER_ZOMBIE_ROW);
        Zombie *z;
        z= new Big_zombie(zomb_sett,950,98*zombie_row + 75 - 116);
        new_zombie(z);
    }
    }
}
void Handler::melon_strike()
{
    for (size_t i = 0; i < mellon_bullets.size(); i++)
    {
        if (mellon_bullets[i]->update())
        {
            for (size_t j = 0; j < zombies.size(); j++)
            {
                if (zombies[j]->same_row(mellon_bullets[i]->get_pos().y + 20) && zombies[j]->same_collum(mellon_bullets[i]->get_pos().x + 27))
                {
                    zombies[j]->damage_taken(mellon_bullets[i]->get_damage());
                    if (zombies[j]->check_health())
                    {
                        zombies.erase(zombies.begin() + j);
                    }
                    break;
                }
            }
            mellon_bullets.erase(mellon_bullets.begin() + i);
        }
    }
}
void Handler::bullet_strike()
{
    for (size_t i = 0; i < zombies.size(); i++)
    {
        for (size_t j = 0; j < bullets.size(); j++)
        {
            Vector2f b_p = bullets[j]->get_pos();
            if (zombies[i]->same_collum(b_p.x) && zombies[i]->same_row(b_p.y))
            {
                zombies[i]->damage_taken(bullets[j]->damage);
                if (bullets[j]->get_type() == "snow")
                {
                    zombies[i]->zombie_freezing();
                }

                if (zombies[i]->check_health())
                {
                    zombies.erase(zombies.begin() + i);
                }
                bullets.erase(bullets.begin() + j);
            }
        }
    }
}
void Handler::end_ckeck()
{
    for (size_t i = 0; i < zombies.size(); i++)
    {
        zombies[i]->update();
        Vector2f zombie_ended_pos = zombies[i]->get_pos();
        if (zombie_ended_pos.x < 135 - 75)
        {
            game_end = true;
        }
    }
}
void Handler::sun_check()
{
    Time selapsed = sun_clock.getElapsedTime();
    if (selapsed.asMilliseconds() >= SUN_TIME_SPAWN)
    {
        sun_clock.restart();
        int sun_collum = random_number(150, 780);
        Sun *s;
        s = new Sun(sun_sett, sun_collum, -83, sun_sett[1]);
        new_sun(s);
    }
    for (size_t i = 0; i < suns.size(); i++)
    {
        suns[i]->update();
        if ((suns[i]->get_pos()).y >= 600)
            suns.erase(suns.begin() + i);
    }
}
void Handler::plants_check()
{
    for (size_t i = 0; i < plants.size(); i++)
    {
        if ((plants[i]->update()) && (plants[i]->placed_or_no))
        {
            if (plants[i]->Type == "Sunflower")
            {
                Vector2f pos_sun = plants[i]->get_pos();
                Sun *s = new Sun(sun_sett, pos_sun.x, pos_sun.y, 50);
                s->placed_or_no = true;
                new_sun(s);
            }
            bool zombie_in_row = false;

            if (plants[i]->Type == "Nokhood")
            {
                for (size_t j = 0; j < zombies.size(); j++)
                {
                    if ((zombies[j]->same_row(plants[i]->get_pos().y)) && (zombies[j]->get_pos().x >= plants[i]->get_pos().x))
                    {
                        zombie_in_row = true;
                    }
                }
                if (zombie_in_row)
                {

                    Vector2f pos_b = plants[i]->get_pos();
                    Bullet *b = new Nokhood_bullet(plant_sett, pos_b.x + 40, pos_b.y);
                    new_bullet(b);
                }
            }
            if (plants[i]->Type == "Snow")
            {
                for (size_t j = 0; j < zombies.size(); j++)
                {
                    if ((zombies[j]->same_row(plants[i]->get_pos().y)) && (zombies[j]->get_pos().x >= plants[i]->get_pos().x))
                    {
                        zombie_in_row = true;
                    }
                }
                if (zombie_in_row)
                {

                    Vector2f pos_b = plants[i]->get_pos();
                    Bullet *b = new Snow_bullet(plant_sett, pos_b.x + 40, pos_b.y);
                    new_bullet(b);
                }
            }
            if (plants[i]->Type == "Melon")
            {
                int targeted_zombie;
                bool first_zombie = true;
                for (size_t j = 0; j < zombies.size(); j++)
                {
                    if ((zombies[j]->same_row(plants[i]->get_pos().y)) && (zombies[j]->get_pos().x >= plants[i]->get_pos().x))
                    {

                        zombie_in_row = true;
                        if (zombie_in_row && first_zombie)
                        {
                            targeted_zombie = j;
                            first_zombie = false;
                        }
                    }
                }
                if (zombie_in_row)
                {
                    Vector2f pos_b = plants[i]->get_pos();
                    Mellon_bullet *mb = new Mellon_bullet(plant_sett[4][1], pos_b, zombies[targeted_zombie]->get_pos(), zombies[targeted_zombie]->get_speed());
                    new_mellon_bullet(mb);
                }
            }
        }
    }
}

void Handler::zombie_check()
{
    for (size_t i = 0; i < zombies.size(); i++)
    {
        for (size_t j = 0; j < plants.size(); j++)
        {
            if (zombies[i]->take_damage({plants[j]->get_pos().x + PLANTS_IMAGE_MIDDLE, plants[j]->get_pos().y + PLANTS_IMAGE_MIDDLE}))
            {
                if (plants[j]->taking_damage(zombies[i]->get_damage()))
                {
                    for (size_t k = 0; k < zombies.size(); k++)
                    {
                        if (zombies[k]->same_collum(plants[j]->get_pos().x + PLANTS_IMAGE_MIDDLE) && zombies[k]->same_row(plants[j]->get_pos().y + PLANTS_IMAGE_MIDDLE))
                            zombies[k]->plant_eaten();
                    }

                    plants.erase(plants.begin() + j);
                }
            }
        }
    }
}

void Handler::update()
{
    melon_strike();
    bullet_strike();
    zombie_spawn();
    end_ckeck();
    sun_check();
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i]->update();
    }
    plants_check();
    zombie_check();
}
void Handler::render(RenderWindow &window)
{
    for (size_t j = 0; j < plants.size(); j++)
    {
        plants[j]->render(window);
    }
    for (size_t i = 0; i < zombies.size(); i++)
    {
        zombies[i]->render(window);
    }
    for (size_t j = 0; j < suns.size(); j++)
    {
        suns[j]->render(window);
    }
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i]->render(window);
    }
    for (size_t i = 0; i < mellon_bullets.size(); i++)
    {
        mellon_bullets[i]->render(window);
    }
}
void Handler::checking_click_on_sun(Vector2f p)
{
    for (size_t i = 0; i < suns.size(); i++)
    {
        if (suns[i]->position_in_sprite(p))
        {
            total_money += suns[i]->value;
            suns.erase(suns.begin() + i);
            break;
        }
    }
}

void Handler::new_zombie(Zombie *z)
{
    zombies.push_back(z);
}
void Handler::new_plant(Plant *p)
{
    plants.push_back(p);
}
void Handler::new_sun(Sun *s)
{
    suns.push_back(s);
}
void Handler::new_bullet(Bullet *b)
{
    bullets.push_back(b);
}
bool Handler ::check_planted_plants(Vector2f p)
{
    for (size_t i = 0; i < plants.size(); i++)
    {
        if (plants[i]->in_plant_pos(p))
        {
            return true;
        }
    }
    return false;
}
bool Handler::game_ended()
{
    return game_end;
}
void Handler::new_mellon_bullet(Mellon_bullet *m)
{
    mellon_bullets.push_back(m);
}

bool Handler::won_or_no()
{
    if (total_time.getElapsedTime().asSeconds() >= TOTAL_TIME && (zombies.size() == 0))
    {
        game_end = true;
        return true;
    }
    return false;
}
void Handler::reading_from_file()
{
    ifstream file("setting.csv");

    if (!file.is_open())
    {

        cerr << "Error opening file." << endl;
        return;
    }
    string tmp_line_reader;
    vector<string> file_to_string;
    while (getline(file, tmp_line_reader))
    {
        file_to_string.push_back(tmp_line_reader);
    }
    file.close();
    int i = 0;
    for (int j = 0; j < 8; j++)
    {
        string number;
        while (1)
        {
            if (file_to_string[4][i] == ',')
                break;
            number = number + string(1, file_to_string[4][i]);
            i++;
        }
        i++;
        float floated_number = stof(number);
        zomb_sett.push_back(floated_number);
    }

    i = 0;
    vector<float> nokhod_sett;
    for (int j = 0; j < 5; j++)
    {
        string number;
        while (1)
        {
            if (file_to_string[7][i] == ',')
                break;
            number = number + string(1, file_to_string[7][i]);
            i++;
        }
        i++;
        float floated_number = stof(number);
        nokhod_sett.push_back(floated_number);
    }
    plant_sett.push_back(nokhod_sett);

    i = 0;
    vector<float> sunflower_sett;
    for (int j = 0; j < 3; j++)
    {

        string number;
        while (1)
        {
            if (file_to_string[9][i] == ',')
                break;
            number = number + string(1, file_to_string[9][i]);
            i++;
        }
        i++;
        float floated_number = stof(number);
        sunflower_sett.push_back(floated_number);
    }
    plant_sett.push_back(sunflower_sett);

    i = 0;
    vector<float> snow_sett;
    for (int j = 0; j < 5; j++)
    {

        string number;
        while (1)
        {
            if (file_to_string[11][i] == ',')
                break;
            number = number + string(1, file_to_string[11][i]);
            i++;
        }
        i++;
        float floated_number = stof(number);
        snow_sett.push_back(floated_number);
    }
    plant_sett.push_back(snow_sett);

    i = 0;
    vector<float> potato_sett;
    for (int j = 0; j < 3; j++)
    {

        string number;
        while (1)
        {
            if (file_to_string[13][i] == ',')
                break;
            number = number + string(1, file_to_string[13][i]);
            i++;
        }
        i++;
        float floated_number = stof(number);
        potato_sett.push_back(floated_number);
    }
    plant_sett.push_back(potato_sett);

    i = 0;
    vector<float> melon_sett;
    for (int j = 0; j < 4; j++)
    {

        string number;
        while (1)
        {
            if (file_to_string[15][i] == ',')
                break;
            number = number + string(1, file_to_string[15][i]);
            i++;
        }
        i++;
        float floated_number = stof(number);
        melon_sett.push_back(floated_number);
    }
    plant_sett.push_back(melon_sett);

    i = 0;
    for (int j = 0; j < 2; j++)
    {

        string number;
        while (1)
        {
            if (file_to_string[18][i] == ',')
                break;
            number = number + string(1, file_to_string[18][i]);
            i++;
        }
        i++;
        float floated_number = stof(number);
        sun_sett.push_back(floated_number);
    }

    i = 0;
    string number11;
    while (1)
    {
        if (file_to_string[20][i] == ',')
            break;
        number11 = number11 + string(1, file_to_string[20][i]);
        i++;
    }
    i++;
    TOTAL_TIME = stoi(number11);

    string number22;
    while (1)
    {
        if (file_to_string[20][i] == ',')
            break;
        number22 = number22 + string(1, file_to_string[20][i]);
        i++;
    }
    i++;
    FIRST_WAVE_TIME = stoi(number22);

    string number33;
    while (1)
    {
        if (file_to_string[20][i] == ',')
            break;
        number33 = number33 + string(1, file_to_string[20][i]);
        i++;
    }
    i++;
    SECOND_WAVE_TIME = stoi(number33);
}