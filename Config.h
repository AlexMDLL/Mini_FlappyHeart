#pragma once

// ============================================================
//  Config.h
//  Все настройки игры в одном месте: размеры, физика, ресурсы.
//  Меняешь число здесь — меняется поведение всей игры.
// ============================================================

namespace config
{
    // ---------- Окно ----------
    constexpr unsigned WINDOW_WIDTH  = 1920;
    constexpr unsigned WINDOW_HEIGHT = 1080;

    // ---------- Физика ----------
    // Числа ниже заданы "по-старому": в пикселях за КАДР при 60 FPS,
    // чтобы их было удобно сравнивать со старой версией.
    // Внутри игры они переводятся в пиксели за СЕКУНДУ функциями
    // toPerSecond() / toPerSecondSquared(), поэтому скорость игры
    // не зависит от FPS монитора.
    constexpr float REFERENCE_FPS = 60.0f;

    constexpr float GRAVITY_STEP = 1.0f;    // насколько растёт скорость падения за кадр
    constexpr float GRAVITY_MAX  = 8.0f;    // предельная скорость падения (px/кадр)
    constexpr float FLAP_IMPULSE = -15.0f;  // импульс взмаха крыльями (вверх, px/кадр)

    // Пересчёт "за кадр" -> "за секунду".
    constexpr float toPerSecond(float perFrame)
    {
        return perFrame * REFERENCE_FPS;
    }

    // Пересчёт ускорения "за кадр за кадр" -> "px/сек^2".
    constexpr float toPerSecondSquared(float perFramePerFrame)
    {
        return perFramePerFrame * REFERENCE_FPS * REFERENCE_FPS;
    }

    // Готовые значения в px/сек для физики.
    constexpr float GRAVITY_ACCEL = toPerSecondSquared(GRAVITY_STEP);  // 3600 px/сек^2
    constexpr float FALL_SPEED_MAX = toPerSecond(GRAVITY_MAX);         // 480 px/сек
    constexpr float FLAP_SPEED     = toPerSecond(FLAP_IMPULSE);        // -900 px/сек

    // ---------- Сердечко игрока ----------
    constexpr float PLAYER_SIZE    = 25.0f;
    constexpr float PLAYER_START_X = 25.0f;
    constexpr float PLAYER_START_Y = 540.0f - PLAYER_SIZE / 2.0f;

    // ---------- Крылья ----------
    constexpr float WING_ANIM_DURATION = 0.25f;  // длительность одного взмаха, сек
    constexpr float WING_REST_ANGLE    = 15.0f;  // наклон крыльев в покое
    constexpr float WING_FLAP_ANGLE    = 50.0f;  // максимальный взмах вверх

    // Размеры крыльев задаются в долях от ширины сердечка.
    // Хочешь крылья больше/меньше — крути эти три числа.
    constexpr float WING_WIDTH_RATIO  = 0.88f;  // длина крыла   (при 25px -> 22px)
    constexpr float WING_HEIGHT_RATIO = 0.26f;  // толщина крыла (при 25px -> 6.5px)
    constexpr float WING_OFFSET_RATIO = 0.48f;  // насколько крыло вынесено в сторону

    // ---------- Столбы-косточки ----------
    constexpr int   OBSTACLE_PAIRS   = 4;       // сколько пар столбов в игре
    constexpr float PILLAR_WIDTH     = 100.0f;
    constexpr float PILLAR_SPEED     = 10.0f;   // px/кадр -> toPerSecond()
    constexpr float GAP_HEIGHT       = 200.0f;  // высота проёма между столбами
    constexpr float HOLE_MIN_Y       = 200.0f;  // верхняя граница случайного проёма
    constexpr float HOLE_MAX_Y       = 600.0f;  // нижняя граница случайного проёма
    constexpr float PILLAR_SPAWN_X   = 800.0f;  // откуда появляются при старте
    constexpr float PILLAR_RESPAWN_X = 1920.0f; // куда уходят после прохода
    constexpr float PILLAR_SPACING   = 500.0f;  // расстояние между парами

    // ---------- Ресурсы ----------
    constexpr const char* FONT_FILE = "shrivt.otf";

    // ---------- Прочее ----------
    constexpr float CHEAT_MSG_DURATION = 3.0f;  // сколько секунд видно сообщение о читах
    constexpr float MAX_FRAME_DT       = 0.05f; // защита от "скачков" при лагах
}
