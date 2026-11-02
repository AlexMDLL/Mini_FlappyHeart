//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <time.h>
//using namespace std;
//using namespace sf;
//
//struct GameObject {
//    float x;
//    float y;
//    float height;
//    float width;
//    Color color;
//    float speed;
//};
//
//bool clls(GameObject a, GameObject b) {
//    return a.x + a.width > b.x && a.x < b.x + b.width && a.y + a.height > b.y && a.y < b.y + b.height;
//}
//
//RenderWindow window(VideoMode(800, 800), L"Новый проект", Style::Default);
//
//void DrawObject(GameObject go) {
//    RectangleShape shape;
//    Vector2f size(go.width, go.height);
//    shape.setSize(size);
//    shape.setPosition(go.x, go.y);
//    shape.setFillColor(go.color);
//    window.draw(shape);
//}
//
//int main() {
//    GameObject player = { 325,750,50,150,Color::Yellow,35 };
//    window.setVerticalSyncEnabled(true);
//    bool gmo = false;
//    int score = 0;
//
//    Font f;
//    if (!f.loadFromFile("shrivt.otf")) {
//        return -1;
//    }
//
//    Text text;
//    text.setFont(f);
//    text.setCharacterSize(24);
//    text.setFillColor(Color::White);
//
//    srand(time(0));
//    GameObject enemy[8];
//    for (int i = 0; i < 8; i++) {
//        enemy[i].x = rand() % 650;
//        enemy[i].y = -50 - i * 100;
//        enemy[i].width = 25;
//        enemy[i].height = 25;
//        enemy[i].color = Color::Red;
//        enemy[i].speed = 2;
//    }
//
//    while (window.isOpen()) {
//        if (!gmo) {
//            for (int i = 0; i < 8; i++) {
//                if (enemy[i].y > 800) {
//                    gmo = true;
//                }
//
//                if (clls(player, enemy[i])) {
//                    score++;
//                    enemy[i].x = rand() % 650;
//                    enemy[i].y = -50;
//                }
//
//                enemy[i].y += enemy[i].speed;
//            }
//
//            Event event;
//            while (window.pollEvent(event)) {
//                if (event.type == Event::Closed)
//                    window.close();
//                if (event.type == Event::KeyPressed) {
//                    if (event.key.code == sf::Keyboard::A) {
//                        if (player.x > 0)
//                            player.x -= player.speed;
//                    }
//                    if (event.key.code == sf::Keyboard::D) {
//                        if (player.x < 800 - player.width)
//                            player.x += player.speed;
//                    }
//                }
//            }
//            window.clear(Color::Black);
//            DrawObject(player);
//            for (int i = 0; i < 8; i++) {
//                DrawObject(enemy[i]);
//            }
//
//            text.setString("Score: " + to_string(score));
//            text.setPosition(10, 10);
//            window.draw(text);
//
//            window.display();
//        }
//        else {
//            text.setString("Game Over! Score: " + to_string(score));
//            text.setPosition(200, 400);
//            window.clear();
//            DrawObject(player);
//            for (int i = 0; i < 8; i++) {
//                DrawObject(enemy[i]);
//            }
//            window.draw(text);
//            window.display();
//        }
//    }
//}


//_______________________________________________________________________________________________________________________________________________


//#include <SFML/Graphics.hpp>
//#include <time.h>
//using namespace sf;
//int x[25];
//int y[25];
//int sX[25];
//int sY[25];
//CircleShape* shape[25];
//void Move() {
//    for (int i = 0; i < 25; i++) {
//        if (x[i] < 10)
//            sX[i] = rand() % 5 + 1;
//        if (x[i] > 1900)
//            sX[i] = (rand() % 5 + 1) * -1;
//        if (y[i] < 10)
//            sY[i] = rand() % 5 + 1;
//        if (y[i] > 1060)
//            sY[i] = (rand() % 5 + 1) * -1;
//        x[i] += sX[i];
//        y[i] += sY[i];
//        shape[i]->setPosition(x[i], y[i]);
//        shape[i]->setFillColor(Color::White);
//    }
//}
//int main()
//{
//    srand(time(0));
//    RenderWindow window(VideoMode(1920, 1080), L"Нет", Style::Default);
//
//    window.setVerticalSyncEnabled(true);
//    for (int i = 0; i < 25; i++) {
//        x[i] = 100;
//        y[i] = 100;
//        sX[i] = 5;
//        sY[i] = 5;
//        shape[i] = new CircleShape(5, 50);
//    }
//
//
//    while (window.isOpen())
//    {
//        Move();
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//        }
//
//        window.clear(Color::Black);
//        for (int i = 0; i < 25; i++)
//            window.draw(*shape[i]);
//        window.display();
//    }
//    return 0;
//}


//_______________________________________________________________________________________________________________________________________________


//#include <SFML/Graphics.hpp>
//#include <time.h>
//using namespace sf;
//CircleShape Sie(20, 100);
//float Sx = 0;
//float Sy = 400;
//int dir = 1;
//void DS() {
//    Sx += 2 * dir;
//    if (Sx > 780) {
//        dir = -1;
//    }
//    else if (Sx < 0) {
//        dir = 1;
//    }
//    Sy = 400 + sin(Sx * 0.05) * 100;
//    Sie.setPosition(Sx, Sy);
//}
//int main() {
//    srand(time(0));
//    RenderWindow window(VideoMode(800, 800), L"Шарики", Style::Default);
//    window.setVerticalSyncEnabled(true);
//    Sie.setFillColor(Color::Blue);
//    while (window.isOpen()) {
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::Closed)
//                window.close();
//        }
//        DS();
//        window.clear(Color::Black);
//        window.draw(Sie);
//        window.display();
//    }
//}




//_______________________________________________________________________________________________________________________________________________



#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
using namespace sf;

float grvt = 1.0f;
RenderWindow window(VideoMode(1920, 1080), L"Flappy Heart", Style::Default);

struct GO {
    float wid, hig, x, y, spd;
    Color color;
    bool isHeart = false;

    float wingAnim = 0.0f;    // 0 = покой, 1 = крылья задраны вверх
    float wingTimer = 1.0f;   // >= 0.25 — анимация не играет

    // Конструктор по умолчанию
    GO() : wid(0), hig(0), x(0), y(0), spd(0), color(Color::White), isHeart(false) {}
    GO(float w, float h, float px, float py, float s, Color c, bool heart = false)
        : wid(w), hig(h), x(px), y(py), spd(s), color(c), isHeart(heart) {
    }
};

void gg(GO go) {
    if (go.isHeart) {
        float centerX = go.x + go.wid / 2.0f;
        float centerY = go.y + go.hig / 2.0f;
        float scale = go.wid / 2.0f;

        // ===== КРЫЛЬЯ (сзади сердечка) =====
        {
            float anim = go.wingAnim;   // 0..1
            float restAngle = 15.0f;         // опущены на 15° в покое
            float flapAngle = 50.0f;         // взмах до 50° вверх

            // правое: +15° → -50°, левое: -15° → +50°
            float rightRot = restAngle - anim * (restAngle + flapAngle);
            float leftRot = -restAngle + anim * (restAngle + flapAngle);

            float wingW = go.wid * 0.70f;
            float wingH = go.wid * 0.22f;
            float offsetX = go.wid * 0.45f;  // расстояние от центра до крыла
            Color wingColor(255, 255, 255);  // кремовый — хорошо видно на чёрном

            CircleShape wR(wingW / 2.0f);
            wR.setOrigin(wingW / 2.0f, wingW / 2.0f);
            wR.setScale(1.0f, wingH / wingW);      // сплющиваем круг в эллипс
            wR.setPosition(centerX + offsetX, centerY);
            wR.setRotation(rightRot);
            wR.setFillColor(wingColor);
            window.draw(wR);

            CircleShape wL(wingW / 2.0f);
            wL.setOrigin(wingW / 2.0f, wingW / 2.0f);
            wL.setScale(1.0f, wingH / wingW);
            wL.setPosition(centerX - offsetX, centerY);
            wL.setRotation(leftRot);
            wL.setFillColor(wingColor);
            window.draw(wL);
        }

        // ===== САМО СЕРДЕЧКО =====
        ConvexShape heart;
        int points = 40;
        heart.setPointCount(points);

        for (int i = 0; i < points; i++) {
            float angle = (float)i * 2.0f * 3.14159f / points;
            float x = 16 * pow(sin(angle), 3);
            float y = -(13 * cos(angle) - 5 * cos(2 * angle) - 2 * cos(3 * angle) - cos(4 * angle));

            float finalX = centerX + x * scale / 16.0f;
            float finalY = centerY + y * scale / 16.0f;

            heart.setPoint(i, Vector2f(finalX, finalY));
        }

        heart.setFillColor(go.color);
        window.draw(heart);
    }

    else {
        // Столб в виде косточки
        bool boneAtBottom = (go.y < 1.0f); // верхний столб всегда начинается с y = 0

        float r = go.wid * 0.2899f;  // радиус "шишек" косточки
        float shaftW = go.wid * 0.6f;  // ширина "стержня"
        float shaftX = go.x + (go.wid - shaftW) / 2.0f;

        if (boneAtBottom) {
            //  Верхний столб: косточка снизу 

            // Стержень сверху до уровня шишек
            RectangleShape shaft(Vector2f(shaftW, go.hig - r));
            shaft.setPosition(shaftX, go.y);
            shaft.setFillColor(go.color);
            window.draw(shaft);

            // Две шишки внизу
            CircleShape knobL(r);
            knobL.setOrigin(r, r);
            knobL.setPosition(go.x + r, go.y + go.hig - r);
            knobL.setFillColor(go.color);
            window.draw(knobL);

            CircleShape knobR(r);
            knobR.setOrigin(r, r);
            knobR.setPosition(go.x + go.wid - r, go.y + go.hig - r);
            knobR.setFillColor(go.color);
            window.draw(knobR);
        }
        else {
            //  Нижний столб: косточка сверху 

            // Стержень от уровня шишек до низа
            RectangleShape shaft(Vector2f(shaftW, go.hig - r));
            shaft.setPosition(shaftX, go.y + r);
            shaft.setFillColor(go.color);
            window.draw(shaft);

            // Две шишки сверху
            CircleShape knobL(r);
            knobL.setOrigin(r, r);
            knobL.setPosition(go.x + r, go.y + r);
            knobL.setFillColor(go.color);
            window.draw(knobL);

            CircleShape knobR(r);
            knobR.setOrigin(r, r);
            knobR.setPosition(go.x + go.wid - r, go.y + r);
            knobR.setFillColor(go.color);
            window.draw(knobR);
        }
    }
}

bool clls(GO a, GO b) {
    return a.x + a.wid > b.x && a.x < b.x + b.wid && a.y + a.hig > b.y && a.y < b.y + b.hig;
}

void initGame(GO& pl, GO en[], int len, float gap, float minHoleY, float maxHoleY) {
    pl = { 25.0f, 25.0f, 25.0f, 540.0f - 12.5f, 0.5f, Color::Red, true }; // Красное сердечко

    for (int i = 0; i < len; ++i) {
        int randRange = (int)(maxHoleY - minHoleY + 1.0f);
        float holeY = minHoleY + (float)(rand() % randRange);

        en[i * 2] = { 100.0f, holeY - 10.0f, 800.0f + (float)i * 500.0f, 0.0f, 10.0f, Color(185, 185, 185) }; // Серый столб (верх)
        en[i * 2 + 1] = { 100.0f, 1080.0f - holeY - gap + 10.0f, 800.0f + (float)i * 500.0f, holeY + gap - 10.0f, 10.0f, Color(185, 185, 185) }; // Серый столб (низ)
    }
}

int main() {
    srand((unsigned int)time(0));

    const int len = 4;
    GO pl;
    GO en[len * 2];

    float gap = 200.0f;
    float minHoleY = 200.0f;
    float maxHoleY = 600.0f;

    bool gmo = false;
    int score = 0;
    int maxScore = 0;
    bool gameStarted = false;
    bool exitConfirmation = false;
    bool cheatsActivated = false;
    float cheatTimer = 0.0f;
    bool showCheatMessage = false;
    float messageTimer = 0.0f;

    // Для ввода чит-кода
    vector<int> cheatSequence = {
        Keyboard::Up, Keyboard::Up, Keyboard::Down, Keyboard::Down,
        Keyboard::Left, Keyboard::Right, Keyboard::Left, Keyboard::Right,
        Keyboard::B, Keyboard::A
    };
    int cheatIndex = 0;

    window.setVerticalSyncEnabled(true);

    Font f;
    if (!f.loadFromFile("shrivt.otf")) {
        return -1;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if (!gameStarted) {
                    // Обработка чит-кода в меню
                    if (cheatIndex < cheatSequence.size() && event.key.code == cheatSequence[cheatIndex]) {
                        cheatIndex++;
                        if (cheatIndex == cheatSequence.size()) {
                            cheatsActivated = true;
                            showCheatMessage = true;
                            messageTimer = 0.0f;
                            cheatIndex = 0; // Сбросить для возможности повторного ввода
                        }
                    }
                    else if (event.key.code != cheatSequence[cheatIndex]) {
                        cheatIndex = 0; // Сбросить, если неправильная клавиша
                    }
                }

                if (event.key.code == Keyboard::N && exitConfirmation) {
                    // Отменить выход
                    exitConfirmation = false;
                }
                if (event.key.code == Keyboard::Escape) {
                    if (gameStarted) {
                        if (gmo) {
                            if (exitConfirmation) {
                                if (score > maxScore) {
                                    maxScore = score;
                                }
                                window.close();
                            }
                            else {
                                exitConfirmation = true;
                            }
                        }
                    }
                    else {
                        // Выход из игры в начальном меню
                        if (exitConfirmation) {
                            window.close();
                        }
                        else {
                            exitConfirmation = true;
                        }
                    }
                }
                if (event.key.code == Keyboard::Space && !gameStarted) {
                    if (!exitConfirmation) { // Не запускать, если подтверждение выхода активно
                        initGame(pl, en, len, gap, minHoleY, maxHoleY);
                        gameStarted = true;
                        gmo = false;
                        grvt = 1.0f;
                        score = 0;
                    }
                }
                else if (event.key.code == Keyboard::Space && gameStarted && !gmo) {
                    grvt = -15.0f;
                    pl.wingTimer = 0.0f;
                }
                if (event.key.code == Keyboard::R && gameStarted && gmo) {
                    if (score > maxScore) {
                        maxScore = score;
                    }
                    gameStarted = false;
                    gmo = false;
                    exitConfirmation = false;
                }
            }
        }

        // Обновление таймеров
        cheatTimer += 0.016f; // Примерное время кадра
        if (showCheatMessage) {
            messageTimer += 0.016f;
            if (messageTimer > 3.0f) { // Показывать 3 секунды
                showCheatMessage = false;
            }
        }

        if (gameStarted && !gmo) {
            pl.y += grvt;

            for (int i = 0; i < len * 2; i++) {
                en[i].x -= en[i].spd;

                if (!cheatsActivated) { // Если читы не активированы, проверять столкновения
                    if (clls(pl, en[i])) {
                        gmo = true;
                    }
                }

                if (pl.y < 0.0f || pl.y > 1080.0f - pl.hig) {
                    gmo = true;
                }

                if (en[i].x < -en[i].wid) {
                    int pairIndex = i / 2;

                    int newRandRange = (int)(maxHoleY - minHoleY + 1.0f);
                    float newHoleY = minHoleY + (float)(rand() % newRandRange);

                    en[pairIndex * 2] = { 100.0f, newHoleY - 10.0f, 1920.0f, 0.0f, 10.0f, Color(185, 185, 185) }; // Серый столб (верх)
                    en[pairIndex * 2 + 1] = { 100.0f, 1080.0f - newHoleY - gap + 10.0f, 1920.0f, newHoleY + gap - 10.0f, 10.0f, Color(185, 185, 185) }; // Серый столб (низ)

                    score++;
                }
            }

            if (pl.wingTimer < 0.25f) {
                pl.wingTimer += 0.016f;                    // ~60 FPS
                float t = pl.wingTimer / 0.25f;            // 0..1
                if (t > 1.0f) t = 1.0f;
                pl.wingAnim = sin(t * 3.14159f);           // 0 → 1 → 0
            }
            else {
                pl.wingAnim = 0.0f;
            }

            if (grvt < 8.0f) grvt += 1.0f;

            if (grvt < 8.0f) {
                grvt += 1.0f;
            }
        }

        window.clear(Color::Black);

        if (gameStarted) {
            if (!gmo) {
                gg(pl);

                for (int i = 0; i < len * 2; i++) {
                    gg(en[i]);
                }

                Text txt;
                txt.setFont(f);
                txt.setString("Score: " + std::to_string(score));
                txt.setPosition(20.0f, 0.0f);
                txt.setFillColor(Color::White);
                txt.setCharacterSize(30);
                window.draw(txt);
            }
            else {
                float centerX = (1920.0f - 800.0f) / 2.0f;
                float centerY1 = 300.0f;
                float centerY2 = 400.0f;
                float centerY3 = 500.0f;
                float centerY4 = 600.0f;

                Text gameOverTxt;
                gameOverTxt.setFont(f);
                gameOverTxt.setString(L"Вы проиграли!");
                gameOverTxt.setPosition(centerX, centerY1);
                gameOverTxt.setFillColor(Color::Red);
                gameOverTxt.setCharacterSize(50);
                window.draw(gameOverTxt);

                Text currentScoreTxt;
                currentScoreTxt.setFont(f);
                currentScoreTxt.setString(L"Ваш счёт: " + std::to_string(score));
                currentScoreTxt.setPosition(centerX, centerY2);
                currentScoreTxt.setFillColor(Color::White);
                currentScoreTxt.setCharacterSize(40);
                window.draw(currentScoreTxt);

                Text maxScoreTxt;
                maxScoreTxt.setFont(f);
                maxScoreTxt.setString(L"Максимальный счёт: " + std::to_string(maxScore));
                maxScoreTxt.setPosition(centerX, centerY3);
                maxScoreTxt.setFillColor(Color::Yellow);
                maxScoreTxt.setCharacterSize(40);
                window.draw(maxScoreTxt);

                if (!exitConfirmation) {
                    Text restartTxt;
                    restartTxt.setFont(f);
                    restartTxt.setString(L"Нажмите   R   чтобы перезапустить");
                    restartTxt.setPosition(centerX, centerY4);
                    restartTxt.setFillColor(Color::White);
                    restartTxt.setCharacterSize(40);
                    window.draw(restartTxt);

                    Text exitTxt;
                    exitTxt.setFont(f);
                    exitTxt.setString(L"нажмите кнопку   ESC   чтобы выйти из игры");
                    exitTxt.setPosition(centerX, centerY4 + 100.0f);
                    exitTxt.setFillColor(Color::White);
                    exitTxt.setCharacterSize(40);
                    window.draw(exitTxt);
                }
                else {
                    Text confirmTxt;
                    confirmTxt.setFont(f);
                    confirmTxt.setString(L"Вы точно хотите выйти?   (ESC)   или   N   чтобы отменить");
                    confirmTxt.setPosition(centerX, centerY4);
                    confirmTxt.setFillColor(Color::Red);
                    confirmTxt.setCharacterSize(40);
                    window.draw(confirmTxt);
                }
            }
        }
        else {
            float centerX = (1920.0f - 600.0f) / 2.0f;
            float centerY = 400.0f; // Подняли основной текст выше
            float centerY2 = 500.0f; // Для максимального счёта
            float centerY3 = 600.0f; // Для инструкции по выходу

            Text startTxt;
            startTxt.setFont(f);
            startTxt.setString(L"Нажмите   пробел   чтобы начать");
            startTxt.setPosition(centerX, centerY);
            startTxt.setFillColor(Color::White);
            startTxt.setCharacterSize(50);
            window.draw(startTxt);

            if (maxScore > 0) {
                Text maxScoreTxt;
                maxScoreTxt.setFont(f);
                maxScoreTxt.setString(L"Максимальный счёт: " + std::to_string(maxScore));
                maxScoreTxt.setPosition(centerX - 50.0f, centerY2);
                maxScoreTxt.setFillColor(Color::Yellow);
                maxScoreTxt.setCharacterSize(30);
                window.draw(maxScoreTxt);
            }

            if (!exitConfirmation) {
                Text exitTxt;
                exitTxt.setFont(f);
                exitTxt.setString(L"нажмите кнопку   ESC   чтобы выйти из игры");
                exitTxt.setPosition(centerX, centerY3);
                exitTxt.setFillColor(Color::White);
                exitTxt.setCharacterSize(40);
                window.draw(exitTxt);
            }
            else {
                Text confirmTxt;
                confirmTxt.setFont(f);
                confirmTxt.setString(L"Вы точно хотите выйти?   (ESC)   или   N   чтобы отменить");
                confirmTxt.setPosition(centerX, centerY3);
                confirmTxt.setFillColor(Color::Red);
                confirmTxt.setCharacterSize(40);
                window.draw(confirmTxt);
            }
        }

        // Отображение сообщения о читах
        if (showCheatMessage) {
            Text cheatTxt;
            cheatTxt.setFont(f);
            cheatTxt.setString(L"Читы были активированы!");
            cheatTxt.setPosition(50.0f, 50.0f);
            cheatTxt.setFillColor(Color::Yellow);
            cheatTxt.setCharacterSize(40);
            window.draw(cheatTxt);
        }

        window.display();
    }

    return 0;
}
