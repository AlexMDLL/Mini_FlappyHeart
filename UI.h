#pragma once

#include <SFML/Graphics.hpp>

// ============================================================
//  UI.h
//  Весь текст на экране: счёт, меню, экран проигрыша.
// ============================================================

// Общее состояние интерфейса, которое нужно знать для отрисовки.
struct UiState
{
    int  score       = 0;
    int  bestScore   = 0;
    bool exitConfirm = false;  // показано "Вы точно хотите выйти?"
};

// Счёт в левом верхнем углу во время игры.
void drawScore(sf::RenderWindow& window, const sf::Font& font, int score);

// Стартовое меню (до начала игры).
void drawMenu(sf::RenderWindow& window, const sf::Font& font, const UiState& ui);

// Экран проигрыша.
void drawGameOver(sf::RenderWindow& window, const sf::Font& font, const UiState& ui);

// Сообщение "Читы были активированы!" (рисуется поверх любого экрана).
void drawCheatNotice(sf::RenderWindow& window, const sf::Font& font);
