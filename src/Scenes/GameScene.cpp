/*
** EPITECH PROJECT, 2023
** GameScene
** File description:
** rm -rf --no-preserve-root /
*/

#include "Scenes/GameScene.hpp"

GameScene::GameScene()
{
}

void GameScene::init()
{
    this->_texturePlayerStatic.loadFromFile("assets/player_static.png");
    this->_texturePlayerMoving.loadFromFile("assets/player_mv.png");
    this->_spritePlayer.setTexture(this->_texturePlayerStatic);
    this->_spritePlayer.setScale(3, 3);
    this->_spritePlayer.setPosition(250, 250);
    this->_playerVelocity = {0, 0};

    this->_textureBgScene.loadFromFile("assets/game_bg.jpg");
    this->_spriteBgScene.setTexture(this->_textureBgScene);

    this->_textureQuestion.loadFromFile("assets/question_bg.png");
    this->_spriteQuestion.setTexture(this->_textureQuestion);
    this->_spriteQuestion.setScale(2, 2);
    this->_spriteQuestion.setPosition(250, 240);

    this->_textureLife.loadFromFile("assets/heart.png");
    this->_spriteLife.setTexture(this->_textureLife);
    this->_spriteLife.setScale(3, 3);
    this->_spriteLife.setPosition(900, 100);


    this->_font.loadFromFile("assets/NotoSansMono-Regular.ttf");

    this->_cmptQuestion = 0;
    this->score = 0;
    this->life = 3;
    this->_questions.push_back(" Quel est le nom du volcan actif situe sur l'ile \nde la Reunion ?");
    this->_questions.push_back("Quelle est la hauteur approximative du Piton de la Fournaise, \nle volcan de l'ile de la Reunion ?");
    this->_questions.push_back("Quel type d'eruptions le Piton de la Fournaise est-il \nprincipalement associe ?");
    this->_questions.push_back("Quelle est la frequence moyenne des eruptions du Piton \nde la Fournaise ?");
    this->_questions.push_back("Quel est le nom du dernier cratere forme lors de l'eruption du \nPiton de la Fournaise en 2021 ?");

    this->_answers.push_back({"Mont St. Helens", "Mont Piton", "Piton de la Fournaise", "Mont Etna"});
    this->_answers.push_back({"2 631 metres", "3 456 metres", "4 231 metres", "2 109 metres"});
    this->_answers.push_back({"Eruptions explosives", "Eruptions effusives", "Eruptions pliniennes", "Eruptions pyroclastiques"});
    this->_answers.push_back({"Tous les 50 ans", "Tous les 5 ans", "Tous les 20 ans", "Tous les 2 ans"});
    this->_answers.push_back({"Cratere Etna", "Cratere Piton", "Cratere Dolomieu", "Cratere Reunion"});

    this->_correctAnswers = {2, 0, 1, 3, 2};

    this->_textQuestions[0].setString(this->_questions[0]);
    this->_textQuestions[1].setString(this->_answers[0][0]);
    this->_textQuestions[2].setString(this->_answers[0][1]);
    this->_textQuestions[3].setString(this->_answers[0][2]);
    this->_textQuestions[4].setString(this->_answers[0][3]);
    this->_textScore.setString("Score : " + std::to_string(this->score));

    this->_textQuestions[0].setPosition(467, 664);
    this->_textQuestions[1].setPosition(492, 831);
    this->_textQuestions[2].setPosition(1132, 831);
    this->_textQuestions[3].setPosition(492, 940);
    this->_textQuestions[4].setPosition(1132, 940);
    this->_textScore.setPosition(900, 200);

    this->_textQuestions[0].setCharacterSize(30);
    this->_textQuestions[1].setCharacterSize(30);
    this->_textQuestions[2].setCharacterSize(30);
    this->_textQuestions[3].setCharacterSize(30);
    this->_textQuestions[4].setCharacterSize(30);
    this->_textScore.setCharacterSize(30);

    this->_textQuestions[0].setFont(this->_font);
    this->_textQuestions[1].setFont(this->_font);
    this->_textQuestions[2].setFont(this->_font);
    this->_textQuestions[3].setFont(this->_font);
    this->_textQuestions[4].setFont(this->_font);
    this->_textScore.setFont(this->_font);
}

std::string GameScene::update(std::shared_ptr<sf::RenderWindow> window, sf::Event event)
{
    int currentQuestion = this->_cmptQuestion;
    if (this->_clock.getElapsedTime().asSeconds() > 0.02) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            this->_playerVelocity.x -= PLAYER_SPEED;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            this->_playerVelocity.x += PLAYER_SPEED;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            this->_playerVelocity.y -= PLAYER_SPEED;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            this->_playerVelocity.y += PLAYER_SPEED;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return "menu";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            this->_cmptQuestion++;
        }
        _spritePlayer.move(_playerVelocity);
        this->_clock.restart();
    }

    int textHeight = this->_textQuestions[0].getGlobalBounds().height;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        sf::Vector2i tiboltPos = {(int)this->_spritePlayer.getGlobalBounds().left + 96, (int)this->_spritePlayer.getGlobalBounds().top + 96};
        for (int i = 1; i < 5; i++) {
            if (tiboltPos.x >= this->_textQuestions[i].getGlobalBounds().left && tiboltPos.x <= this->_textQuestions[i].getGlobalBounds().left + this->_textQuestions[i].getGlobalBounds().width && tiboltPos.y >= this->_textQuestions[i].getGlobalBounds().top && tiboltPos.y <= this->_textQuestions[i].getGlobalBounds().top + textHeight) {
                if (i - 1 == this->_correctAnswers[this->_cmptQuestion % this->_questions.size()]) {
                    this->_cmptQuestion++;
                    this->score++;
                    this->_textScore.setString("Score : " + std::to_string(this->score));
                    this->_spritePlayer.setTexture(this->_texturePlayerStatic);
                    this->_spritePlayer.setPosition(250, 250);
                    this->_playerVelocity = {0, 0};
                    this->_textQuestions[0].setString(this->_questions[this->_cmptQuestion % this->_questions.size()]);
                    this->_textQuestions[1].setString(this->_answers[this->_cmptQuestion % this->_questions.size()][0]);
                    this->_textQuestions[2].setString(this->_answers[this->_cmptQuestion % this->_questions.size()][1]);
                    this->_textQuestions[3].setString(this->_answers[this->_cmptQuestion % this->_questions.size()][2]);
                    this->_textQuestions[4].setString(this->_answers[this->_cmptQuestion % this->_questions.size()][3]);
                }
                else {
                    this->life--;
                    this->_spritePlayer.setTexture(this->_texturePlayerStatic);
                    this->_spritePlayer.setPosition(250, 250);
                    this->_playerVelocity = {0, 0};
                    this->score = 0;
                    this->_textScore.setString("Score : " + std::to_string(this->score));
                    this->_cmptQuestion = 0;
                    this->_textQuestions[0].setString(this->_questions[this->_cmptQuestion % this->_questions.size()]);
                }
            }
        }

    }
    if (this->score == this->_questions.size()) {
        return "win";
    }
    if (this->life <= 0) {
        return "loose";
    }
    if (currentQuestion != this->_cmptQuestion % this->_questions.size()) {
        this->_textQuestions[0].setString(this->_questions[this->_cmptQuestion % this->_questions.size()]);
        this->_textQuestions[1].setString(this->_answers[this->_cmptQuestion % this->_questions.size()][0]);
        this->_textQuestions[2].setString(this->_answers[this->_cmptQuestion % this->_questions.size()][1]);
        this->_textQuestions[3].setString(this->_answers[this->_cmptQuestion % this->_questions.size()][2]);
        this->_textQuestions[4].setString(this->_answers[this->_cmptQuestion % this->_questions.size()][3]);
    }
    this->_spriteLife.setTextureRect(sf::IntRect(0, 0, 64 * this->life, 64));
    _playerVelocity.x = 0;
    _playerVelocity.y = 0;

    auto playerPos = this->_spritePlayer.getPosition();

    return "";
}

void GameScene::draw(std::shared_ptr<sf::RenderWindow> window)
{
    // window->draw(this->_spriteBgScene);
    window->draw(this->_spriteLife);
    window->draw(this->_spriteQuestion);
    window->draw(this->_textQuestions[0]);
    window->draw(this->_textQuestions[1]);
    window->draw(this->_textQuestions[2]);
    window->draw(this->_textQuestions[3]);
    window->draw(this->_textQuestions[4]);
    window->draw(this->_textScore);
    window->draw(this->_spritePlayer);
}

GameScene::~GameScene()
{
}
