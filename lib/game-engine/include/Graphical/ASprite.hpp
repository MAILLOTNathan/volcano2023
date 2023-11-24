/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** ASprite
*/

#ifndef ASPRITE_HPP_
#define ASPRITE_HPP_

#include "../cppIncludes.hpp"
#include "../Maths/Rect.hpp"
#include "../Maths/Vector2.hpp"

namespace etib {
    class ASprite {
        public:
            ASprite();
            virtual ~ASprite() = default;

            virtual void createSprite(const std::string &path) = 0;
            virtual void destroySprite() = 0;
            virtual void setTextureRect(const Rect &rect) = 0;
            virtual void setPosition(const Vector2 &pos) = 0;
            virtual void drawSprite() = 0;

            virtual void getSprite() = 0;
            virtual std::string getPath();
            virtual Rect getTextureRect();
            virtual Vector2 getPosition();

        protected:
            std::string _path;
            Rect _rect;
            Vector2 _pos;
    };
}

#endif /* !ASPRITE_HPP_ */
