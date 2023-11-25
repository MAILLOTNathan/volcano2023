/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "cppIncludes.hpp"
#include "Graphical/Event.hpp"

class Window {
    public:
        Window();
        ~Window();

        void init(std::uint32_t width, std::uint32_t height, std::string title);
        void stop();

        void clear();
        void draw();
        void pollEvent();

        bool isOpen();

        std::uint32_t getWidth() const;
        std::uint32_t getHeight() const;
        std::string getTitle() const;
        sf::Event getEvent() const;
        Event& getEventManager();
        std::shared_ptr<sf::RenderWindow> getWindow() { return _window; }

    private:
        std::shared_ptr<sf::RenderWindow> _window;
        std::uint32_t _width;
        std::uint32_t _height;
        std::string _title;
        sf::Event _event;
        Event _eventManager;
};

#endif /* !WINDOW_HPP_ */
