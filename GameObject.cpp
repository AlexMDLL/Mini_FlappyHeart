#include "GameObject.h"
#include "Config.h"

bool intersects(const GameObject& a, const GameObject& b)
{
    return a.x + a.width  > b.x &&
           a.x            < b.x + b.width &&
           a.y + a.height > b.y &&
           a.y            < b.y + b.height;
}

GameObject makePlayer()
{
    GameObject player;
    player.width  = config::PLAYER_SIZE;
    player.height = config::PLAYER_SIZE;
    player.x      = config::PLAYER_START_X;
    player.y      = config::PLAYER_START_Y;
    player.speed  = 0.5f;
    player.color  = sf::Color::Red;
    player.isHeart = true;
    return player;
}
