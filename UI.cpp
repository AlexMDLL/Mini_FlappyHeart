#include "UI.h"
#include "Config.h"

#include <string>

namespace
{
    // Быстрое создание текста с нужными настройками.
    void drawText(sf::RenderWindow& window, const sf::Font& font,
                  const sf::String& text, float x, float y,
                  unsigned size, const sf::Color& color)
    {
        sf::Text label;
        label.setFont(font);
        label.setString(text);
        label.setPosition(x, y);
        label.setFillColor(color);
        label.setCharacterSize(size);
        window.draw(label);
    }

    // Общая строка "нажмите ESC чтобы выйти" / "точно хотите выйти?".
    void drawExitHint(sf::RenderWindow& window, const sf::Font& font,
                      const UiState& ui, float centerX, float y)
    {
        if (!ui.exitConfirm)
        {
            drawText(window, font,
                     L"нажмите кнопку   ESC   чтобы выйти из игры",
                     centerX, y, 40, sf::Color::White);
        }
        else
        {
            drawText(window, font,
                     L"Вы точно хотите выйти?   (ESC)   или   N   чтобы отменить",
                     centerX, y, 40, sf::Color::Red);
        }
    }
}

void drawCheatNotice(sf::RenderWindow& window, const sf::Font& font)
{
    drawText(window, font, L"Читы были активированы!", 50.0f, 50.0f, 40, sf::Color::Yellow);
}

void drawScore(sf::RenderWindow& window, const sf::Font& font, int score)
{
    drawText(window, font, "Score: " + std::to_string(score), 20.0f, 0.0f, 30, sf::Color::White);
}

void drawMenu(sf::RenderWindow& window, const sf::Font& font, const UiState& ui)
{
    const float centerX = (static_cast<float>(config::WINDOW_WIDTH) - 600.0f) / 2.0f;

    drawText(window, font, L"Нажмите   пробел   чтобы начать",
             centerX, 400.0f, 50, sf::Color::White);

    if (ui.bestScore > 0)
    {
        drawText(window, font,
                 L"Максимальный счёт: " + std::to_wstring(ui.bestScore),
                 centerX - 50.0f, 500.0f, 30, sf::Color::Yellow);
    }

    drawExitHint(window, font, ui, centerX, 600.0f);
}

void drawGameOver(sf::RenderWindow& window, const sf::Font& font, const UiState& ui)
{
    const float centerX = (static_cast<float>(config::WINDOW_WIDTH) - 800.0f) / 2.0f;

    drawText(window, font, L"Вы проиграли!", centerX, 300.0f, 50, sf::Color::Red);
    drawText(window, font, L"Ваш счёт: " + std::to_wstring(ui.score),
             centerX, 400.0f, 40, sf::Color::White);
    drawText(window, font, L"Максимальный счёт: " + std::to_wstring(ui.bestScore),
             centerX, 500.0f, 40, sf::Color::Yellow);

    if (!ui.exitConfirm)
    {
        drawText(window, font, L"Нажмите   R   чтобы перезапустить",
                 centerX, 600.0f, 40, sf::Color::White);
        drawExitHint(window, font, ui, centerX, 700.0f);
    }
    else
    {
        drawExitHint(window, font, ui, centerX, 600.0f);
    }
}
