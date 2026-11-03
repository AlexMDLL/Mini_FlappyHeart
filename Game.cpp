#include "Game.h"
#include "Config.h"
#include "Renderer.h"

#include <cmath>
#include <cstdlib>

Game::Game(const sf::Font& font)
    : m_font(font)
{
    // Чит-код: ↑ ↑ ↓ ↓ ← → ← → B A
    m_cheatSequence = {
        sf::Keyboard::Up,    sf::Keyboard::Up,
        sf::Keyboard::Down,  sf::Keyboard::Down,
        sf::Keyboard::Left,  sf::Keyboard::Right,
        sf::Keyboard::Left,  sf::Keyboard::Right,
        sf::Keyboard::B,     sf::Keyboard::A
    };

    m_pillars.resize(config::OBSTACLE_PAIRS);
    resetWorld();
}

// ---------------------------------------------------------
//  Создание нового проёма по случайной высоте.
// ---------------------------------------------------------
void Game::spawnPair(PillarPair& pair, float x)
{
    const int range = static_cast<int>(config::HOLE_MAX_Y - config::HOLE_MIN_Y + 1.0f);
    const float holeY = config::HOLE_MIN_Y + static_cast<float>(std::rand() % range);

    // Верхний столб: от потолка вниз до проёма
    pair.top.width      = config::PILLAR_WIDTH;
    pair.top.height     = holeY - 10.0f;
    pair.top.x          = x;
    pair.top.y          = 0.0f;
    pair.top.speed      = config::PILLAR_SPEED;
    pair.top.color      = sf::Color(185, 185, 185);
    pair.top.isTopPillar = true;

    // Нижний столб: от проёма вниз до пола
    pair.bottom.width      = config::PILLAR_WIDTH;
    pair.bottom.height     = static_cast<float>(config::WINDOW_HEIGHT) - holeY - config::GAP_HEIGHT + 10.0f;
    pair.bottom.x          = x;
    pair.bottom.y          = holeY + config::GAP_HEIGHT - 10.0f;
    pair.bottom.speed      = config::PILLAR_SPEED;
    pair.bottom.color      = sf::Color(185, 185, 185);
    pair.bottom.isTopPillar = false;
}

// ---------------------------------------------------------
//  Сброс мира в начальное положение.
// ---------------------------------------------------------
void Game::resetWorld()
{
    m_player = makePlayer();

    for (int i = 0; i < config::OBSTACLE_PAIRS; ++i)
    {
        spawnPair(m_pillars[i], config::PILLAR_SPAWN_X + static_cast<float>(i) * config::PILLAR_SPACING);
    }

    m_velocityY = config::toPerSecond(config::GRAVITY_STEP);
}

// ---------------------------------------------------------
//  Старт новой игры.
// ---------------------------------------------------------
void Game::startNewGame()
{
    resetWorld();
    m_state         = GameState::Playing;
    m_score         = 0;
    m_exitConfirm   = false;
    m_player.wingTimer = config::WING_ANIM_DURATION;
    m_player.wingAnim  = 0.0f;
}

// ---------------------------------------------------------
//  Взмах крыльями: мгновенно задаём скорость вверх.
// ---------------------------------------------------------
void Game::flap()
{
    m_velocityY        = config::FLAP_SPEED;
    m_player.wingTimer = 0.0f;  // запускаем анимацию крыльев
}

// ---------------------------------------------------------
//  Проигрыш.
// ---------------------------------------------------------
void Game::gameOver()
{
    if (m_score > m_bestScore)
        m_bestScore = m_score;

    m_state       = GameState::GameOver;
    m_exitConfirm = false;
}

// ---------------------------------------------------------
//  Обработка ввода.
// ---------------------------------------------------------
void Game::handleEvent(const sf::Event& event)
{
    // Отпускание пробела разрешает следующий взмах.
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Space)
            m_spaceHeld = false;
        return;
    }

    if (event.type != sf::Event::KeyPressed)
        return;

    const sf::Keyboard::Key key = event.key.code;

    // Ввод чит-кода работает только в меню.
    if (m_state == GameState::Menu)
    {
        if (m_cheatIndex < m_cheatSequence.size() && key == m_cheatSequence[m_cheatIndex])
        {
            ++m_cheatIndex;
            if (m_cheatIndex == m_cheatSequence.size())
            {
                m_cheatsActive  = true;
                m_showCheatMsg  = true;
                m_cheatMsgTimer = 0.0f;
                m_cheatIndex    = 0;  // чтобы можно было ввести ещё раз
            }
        }
        else
        {
            m_cheatIndex = 0;  // неверная клавиша — начинаем заново
        }
    }

    // Отмена подтверждения выхода.
    if (key == sf::Keyboard::N && m_exitConfirm)
    {
        m_exitConfirm = false;
        return;
    }

    // ESC: просим подтверждение, повторное нажатие — выход.
    if (key == sf::Keyboard::Escape)
    {
        // Во время игры ESC не обрабатывается (как и в старой версии).
        if (m_state == GameState::Playing)
            return;

        if (m_exitConfirm)
            m_quitRequested = true;
        else
            m_exitConfirm = true;

        return;
    }

    if (key == sf::Keyboard::Space)
    {
        // Зажатый пробел даёт только один взмах: ждём, пока клавишу отпустят.
        if (m_spaceHeld)
            return;

        m_spaceHeld = true;

        if (m_state == GameState::Menu)
        {
            if (!m_exitConfirm)
                startNewGame();
        }
        else if (m_state == GameState::Playing)
        {
            flap();
        }
        return;
    }

    if (key == sf::Keyboard::R && m_state == GameState::GameOver)
    {
        m_state       = GameState::Menu;
        m_exitConfirm = false;
    }
}

// ---------------------------------------------------------
//  Анимация крыльев.
// ---------------------------------------------------------
void Game::updateWings(float dt)
{
    if (m_player.wingTimer < config::WING_ANIM_DURATION)
    {
        m_player.wingTimer += dt;

        float t = m_player.wingTimer / config::WING_ANIM_DURATION;  // 0..1
        if (t > 1.0f)
            t = 1.0f;

        m_player.wingAnim = std::sin(t * 3.14159f);  // 0 -> 1 -> 0
    }
    else
    {
        m_player.wingAnim = 0.0f;
    }
}

// ---------------------------------------------------------
//  Обновление логики. dt — время кадра в секундах.
//
//  ВАЖНО (исправленный баг гравитации):
//  раньше скорость падения увеличивалась ДВАЖДЫ за кадр —
//  в коде стояли два подряд одинаковых блока
//  "if (grvt < 8.0f) grvt += 1.0f;". Из-за этого сердечко
//  разгонялось вдвое быстрее и падало "камнем".
//  Теперь скорость растёт один раз за кадр, а вверх
//  по-прежнему толкает с импульсом -15.
// ---------------------------------------------------------
void Game::update(float dt)
{
    // Сообщение о читах живёт по таймеру.
    if (m_showCheatMsg)
    {
        m_cheatMsgTimer += dt;
        if (m_cheatMsgTimer >= config::CHEAT_MSG_DURATION)
            m_showCheatMsg = false;
    }

    if (m_state != GameState::Playing)
        return;

    // Физика сердечка -------------------------------------------------
    // Скорость меняется на GRAVITY_ACCEL px/сек^2, не выше FALL_SPEED_MAX.
    m_velocityY += config::GRAVITY_ACCEL * dt;
    if (m_velocityY > config::FALL_SPEED_MAX)
        m_velocityY = config::FALL_SPEED_MAX;

    m_player.y += m_velocityY * dt;

    // Выход за границы экрана — проигрыш.
    if (m_player.y < 0.0f ||
        m_player.y > static_cast<float>(config::WINDOW_HEIGHT) - m_player.height)
    {
        gameOver();
        return;
    }

    // Движение столбов и столкновения ---------------------------------
    const float pillarStep = config::toPerSecond(config::PILLAR_SPEED) * dt;

    for (int i = 0; i < config::OBSTACLE_PAIRS; ++i)
    {
        PillarPair& pair = m_pillars[i];

        pair.top.x    -= pillarStep;
        pair.bottom.x -= pillarStep;

        // Если читы не активированы — проверяем столкновение.
        if (!m_cheatsActive &&
            (intersects(m_player, pair.top) || intersects(m_player, pair.bottom)))
        {
            gameOver();
            return;
        }

        // Прошли пару — начисляем очко и возвращаем столбы справа.
        if (pair.top.x + pair.top.width < 0.0f)
        {
            spawnPair(pair, config::PILLAR_RESPAWN_X);
            if (m_cheatsActive == true) { m_score++*2;}
            ++m_score;
        }
    }

    updateWings(dt);
}

// ---------------------------------------------------------
//  Сбор состояния для интерфейса.
// ---------------------------------------------------------
UiState Game::buildUi() const
{
    UiState ui;
    ui.score       = m_score;
    ui.bestScore   = m_bestScore;
    ui.exitConfirm = m_exitConfirm;
    return ui;
}

// ---------------------------------------------------------
//  Отрисовка.
// ---------------------------------------------------------
void Game::draw(sf::RenderWindow& window) const
{
    switch (m_state)
    {
    case GameState::Menu:
        drawMenu(window, m_font, buildUi());
        break;

    case GameState::Playing:
        drawObject(window, m_player);
        for (const PillarPair& pair : m_pillars)
        {
            drawObject(window, pair.top);
            drawObject(window, pair.bottom);
        }
        drawScore(window, m_font, m_score);
        break;

    case GameState::GameOver:
        drawGameOver(window, m_font, buildUi());
        break;
    }

    // Сообщение о читах видно поверх любого экрана.
    if (m_showCheatMsg)
        drawCheatNotice(window, m_font);
}
