/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Graphical asbtract class
*/

#ifndef GRAPHICAL_HPP_
#define GRAPHICAL_HPP_

#include "../cppIncludes.hpp"
#include "ASprite.hpp"

namespace etib {
    class Graphical {
        public:
            Graphical();
            virtual ~Graphical() = default;

            virtual void init() = 0;
            virtual void stop() = 0;

            virtual void createWindow(std::uint32_t width, std::uint32_t height, std::string title) = 0;
            virtual void destroyWindow() = 0;

            virtual void clear() = 0;
            virtual void draw() = 0;

            virtual void createSprite() = 0;
            virtual void destroySprite() = 0;
            virtual void setSpriteTexture() = 0;
            virtual void setSpritePosition() = 0;
            virtual void setSpriteRotation() = 0;
            virtual void setSpriteScale() = 0;
            virtual void drawSprite() = 0;

            virtual void createText() = 0;
            virtual void destroyText() = 0;
            virtual void setTextString() = 0;
            virtual void setTextFont() = 0;
            virtual void setTextPosition() = 0;
            virtual void setTextRotation() = 0;
            virtual void setTextScale() = 0;
            virtual void drawText() = 0;

            std::uint32_t getWidth() const;
            std::uint32_t getHeight() const;
            std::string getTitle() const;

        private:
            std::uint32_t _width;
            std::uint32_t _height;
            std::string _title;
            std::map<std::string, std::shared_ptr<ASprite>> _sprites;
    };
}

#endif /* !GRAPHICAL_HPP_ */