#include "Renderer.h"
#include "Config.h"

#include <cmath>

namespace
{
    // ---------------------------------------------------------
    //  Крылья: два сплющенных круга за сердечком.
    //  wingAnim: 0 — покой (опущены), 1 — задраны вверх.
    // ---------------------------------------------------------
    void drawWings(sf::RenderWindow& window, const GameObject& heart,
                   float centerX, float centerY)
    {
        const float anim = heart.wingAnim;  // 0..1

        // правое: +15° -> -50°, левое: -15° -> +50°
        const float rightRot = config::WING_REST_ANGLE - anim * (config::WING_REST_ANGLE + config::WING_FLAP_ANGLE);
        const float leftRot  = -config::WING_REST_ANGLE + anim * (config::WING_REST_ANGLE + config::WING_FLAP_ANGLE);

        const float wingWidth  = heart.width * config::WING_WIDTH_RATIO;
        const float wingHeight = heart.width * config::WING_HEIGHT_RATIO;
        const float offsetX    = heart.width * config::WING_OFFSET_RATIO;  // расстояние от центра до крыла

        sf::CircleShape rightWing(wingWidth / 2.0f);
        rightWing.setOrigin(wingWidth / 2.0f, wingWidth / 2.0f);
        rightWing.setScale(1.0f, wingHeight / wingWidth);  // сплющиваем круг в эллипс
        rightWing.setPosition(centerX + offsetX, centerY);
        rightWing.setRotation(rightRot);
        rightWing.setFillColor(sf::Color::White);
        window.draw(rightWing);

        sf::CircleShape leftWing(wingWidth / 2.0f);
        leftWing.setOrigin(wingWidth / 2.0f, wingWidth / 2.0f);
        leftWing.setScale(1.0f, wingHeight / wingWidth);
        leftWing.setPosition(centerX - offsetX, centerY);
        leftWing.setRotation(leftRot);
        leftWing.setFillColor(sf::Color::White);
        window.draw(leftWing);
    }

    // ---------------------------------------------------------
    //  Сердечко по параметрической формуле (кривая "сердца").
    // ---------------------------------------------------------
    void drawHeart(sf::RenderWindow& window, const GameObject& heart)
    {
        const float centerX = heart.x + heart.width / 2.0f;
        const float centerY = heart.y + heart.height / 2.0f;
        const float scale   = heart.width / 2.0f;

        const int points = 40;
        sf::ConvexShape shape;
        shape.setPointCount(points);

        for (int i = 0; i < points; i++)
        {
            const float angle = static_cast<float>(i) * 2.0f * 3.14159f / static_cast<float>(points);
            const float px = 16.0f * std::pow(std::sin(angle), 3.0f);
            const float py = -(13.0f * std::cos(angle)
                             - 5.0f  * std::cos(2.0f * angle)
                             - 2.0f  * std::cos(3.0f * angle)
                             -         std::cos(4.0f * angle));

            shape.setPoint(i, sf::Vector2f(centerX + px * scale / 16.0f,
                                           centerY + py * scale / 16.0f));
        }

        shape.setFillColor(heart.color);
        window.draw(shape);
    }

    // ---------------------------------------------------------
    //  Верхний столб: шишки косточки внизу.
    // ---------------------------------------------------------
    void drawTopPillar(sf::RenderWindow& window, const GameObject& pillar)
    {
        const float knobRadius = pillar.width * 0.2899f;  // радиус "шишек"
        const float shaftWidth = pillar.width * 0.6f;     // ширина "стержня"
        const float shaftX     = pillar.x + (pillar.width - shaftWidth) / 2.0f;

        // Стержень сверху до уровня шишек
        sf::RectangleShape shaft(sf::Vector2f(shaftWidth, pillar.height - knobRadius));
        shaft.setPosition(shaftX, pillar.y);
        shaft.setFillColor(pillar.color);
        window.draw(shaft);

        // Две шишки внизу
        sf::CircleShape leftKnob(knobRadius);
        leftKnob.setOrigin(knobRadius, knobRadius);
        leftKnob.setPosition(pillar.x + knobRadius, pillar.y + pillar.height - knobRadius);
        leftKnob.setFillColor(pillar.color);
        window.draw(leftKnob);

        sf::CircleShape rightKnob(knobRadius);
        rightKnob.setOrigin(knobRadius, knobRadius);
        rightKnob.setPosition(pillar.x + pillar.width - knobRadius, pillar.y + pillar.height - knobRadius);
        rightKnob.setFillColor(pillar.color);
        window.draw(rightKnob);
    }

    // ---------------------------------------------------------
    //  Нижний столб: шишки косточки сверху.
    // ---------------------------------------------------------
    void drawBottomPillar(sf::RenderWindow& window, const GameObject& pillar)
    {
        const float knobRadius = pillar.width * 0.2899f;
        const float shaftWidth = pillar.width * 0.6f;
        const float shaftX     = pillar.x + (pillar.width - shaftWidth) / 2.0f;

        // Стержень от уровня шишек до низа
        sf::RectangleShape shaft(sf::Vector2f(shaftWidth, pillar.height - knobRadius));
        shaft.setPosition(shaftX, pillar.y + knobRadius);
        shaft.setFillColor(pillar.color);
        window.draw(shaft);

        // Две шишки сверху
        sf::CircleShape leftKnob(knobRadius);
        leftKnob.setOrigin(knobRadius, knobRadius);
        leftKnob.setPosition(pillar.x + knobRadius, pillar.y + knobRadius);
        leftKnob.setFillColor(pillar.color);
        window.draw(leftKnob);

        sf::CircleShape rightKnob(knobRadius);
        rightKnob.setOrigin(knobRadius, knobRadius);
        rightKnob.setPosition(pillar.x + pillar.width - knobRadius, pillar.y + knobRadius);
        rightKnob.setFillColor(pillar.color);
        window.draw(rightKnob);
    }
}

void drawObject(sf::RenderWindow& window, const GameObject& object)
{
    if (object.isHeart)
    {
        const float centerX = object.x + object.width / 2.0f;
        const float centerY = object.y + object.height / 2.0f;

        drawWings(window, object, centerX, centerY);  // крылья сзади сердечка
        drawHeart(window, object);
        return;
    }

    if (object.isTopPillar)
        drawTopPillar(window, object);
    else
        drawBottomPillar(window, object);
}
