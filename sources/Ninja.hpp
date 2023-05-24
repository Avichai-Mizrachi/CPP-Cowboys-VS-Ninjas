#pragma once
#include "Character.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel
{
    class Ninja : public Character
    {

    private:
        int speed;

    public:
        Ninja(string name,const Point& location, int hp, int speed);
        void move(Character *enemy);
        void slash(Character *other);
        void attack(Character *) override;
        int getSpeed(){return speed;}
        string print() override;
    };
}