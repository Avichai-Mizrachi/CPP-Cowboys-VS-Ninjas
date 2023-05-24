#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character{

        private:
            Point location;
            int health;
            string name;
            bool gotATeam;

        public:
            Character(const string &name, const Point &location, int health);
            Character(const Character &other);
            Character(Character &&other) noexcept;
            Character &operator=(const Character &other);
            Character &operator=(Character &&other) noexcept;

            bool inTeam(){return this->gotATeam;}
            void setInTeam(bool flag){this->gotATeam = flag;}
            double distance(Character* other);
            bool isAlive();
            void hit(int damage);
            Point getLocation(){return location;}
            void setLocation(Point newLoc){location = newLoc;}
            int getHealth(){return health;}
            void setHealth(int updated){health = updated;}
            string getName(){return name;}
            virtual string print() = 0;
            virtual void attack(Character *) = 0;
    };
}