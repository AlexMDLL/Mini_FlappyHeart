#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "UI.h"

#include <vector>

// ============================================================
//  Game.h
//  Игровая логика: состояния, физика, столкновения, счёт.
//  Ничего не знает о том, как рисовать — за это отвечает Renderer/UI.
// ============================================================

enum class GameState
{
    Menu,      // главное меню
    Playing,   // идёт игра
    GameOver   // проигрыш
};

class Game
{
public:
    explicit Game(const sf::Font& font);

    void handleEvent(const sf::Event& event);
    void update(float dt);
    void draw(sf::RenderWindow& window) const;

    // Игрок нажал "выйти" (подтвердил ESC).
    bool wantsQuit() const { return m_quitRequested; }

private:
    void startNewGame();
    void resetWorld();
    void spawnPair(PillarPair& pair, float x);
    void flap();
    void updateWings(float dt);
    void gameOver();

    UiState buildUi() const;

    const sf::Font& m_font;

    GameState m_state        = GameState::Menu;
    bool      m_quitRequested = false;
    bool      m_exitConfirm   = false;
    int       m_score         = 0;
    int       m_bestScore     = 0;
    bool      m_cheatsActive  = false;
    bool      m_showCheatMsg  = false;
    float     m_cheatMsgTimer = 0.0f;

    // Пробел уже зажат: автоповтор клавиши не должен давать новые взмахи,
    // иначе сердечко бесконечно улетает вверх.
    bool      m_spaceHeld     = false;

    // Чит-код: ↑ ↑ ↓ ↓ ← → ← → B A
    std::vector<sf::Keyboard::Key> m_cheatSequence;
    std::size_t m_cheatIndex = 0;

    GameObject              m_player;
    std::vector<PillarPair> m_pillars;
    float                   m_velocityY = 0.0f;  // вертикальная скорость, px/сек
};
