/*
** EPITECH PROJECT, 2023
** AGraphical
** File description:
** https://github.com/x4m3/vim-epitech
*/

#pragma once
#include "IGraphical.hpp"


namespace etib {
    class AGraphical : public etib::IGraphical {
        public:
            AGraphical();
            virtual ~AGraphical() = default;


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
