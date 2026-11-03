#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <ctime>

#include "Config.h"
#include "Game.h"

// ============================================================
//  main.cpp
//  Точка входа: создаём окно, грузим шрифт, крутим главный цикл.
//  Вся игра живёт в классе Game.
// ============================================================

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::RenderWindow window(
        sf::VideoMode(config::WINDOW_WIDTH, config::WINDOW_HEIGHT),
        L"Flappy Heart",
        sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    // Отключаем автоповтор клавиш: иначе зажатый пробел шлёт поток
    // событий KeyPressed и сердечко улетает вверх.
    window.setKeyRepeatEnabled(false);

    sf::Font font;
    if (!font.loadFromFile(config::FONT_FILE))
        return -1;

    Game game(font);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            game.handleEvent(event);
        }

        if (game.wantsQuit())
            window.close();

        // Время кадра в секундах, с защитой от больших скачков.
        float dt = clock.restart().asSeconds();
        if (dt > config::MAX_FRAME_DT)
            dt = config::MAX_FRAME_DT;

        game.update(dt);

        window.clear(sf::Color::Black);
        game.draw(window);
        window.display();
    }

    return 0;
}
