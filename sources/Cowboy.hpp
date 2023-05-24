#pragma once
#include "Character.hpp"
#include <iostream>
#include <string>

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int numOfBullets;

    public:
        Cowboy(string name, Point location);
        bool hasboolets();
        void reload();
        void shoot(Character *enemy);
        void attack(Character *) override;
        string print() override;
        int getAmountOfBullets() { return numOfBullets; }
        void setAmoutOfBullets() { this->numOfBullets -= 1; }
    };
}