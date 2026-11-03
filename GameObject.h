#pragma once

#include <SFML/Graphics.hpp>

// ============================================================
//  GameObject.h
//  Один объект на экране: сердечко игрока или столб-косточка.
// ============================================================

struct GameObject
{
    float     width  = 0.0f;
    float     height = 0.0f;
    float     x      = 0.0f;
    float     y      = 0.0f;
    float     speed  = 0.0f;
    sf::Color color  = sf::Color::White;

    bool isHeart     = false;  // true — рисуем сердечко с крыльями
    bool isTopPillar = false;  // true — верхний столб (шишки косточки снизу)

    // Анимация крыльев: 0 — покой, 1 — крылья задраны вверх.
    float wingAnim  = 0.0f;
    float wingTimer = 1.0f;    // >= WING_ANIM_DURATION — анимация не играет
};

// Пара столбов: верхний и нижний, между ними проём.
struct PillarPair
{
    GameObject top;
    GameObject bottom;
};

// Проверка пересечения прямоугольников (AABB).
bool intersects(const GameObject& a, const GameObject& b);

// Создание нового сердечка в стартовой позиции.
GameObject makePlayer();
