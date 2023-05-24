#include "Cowboy.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>

using namespace std;

namespace ariel
{
    // Cowboy functions
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), numOfBullets(6) {}

    bool Cowboy::hasboolets()
    {
        if (this->numOfBullets > 0)
        {
            return true;
        }
        return false;
    }

    void Cowboy::reload()
    {
        if (this->isAlive() == false)
        {
            throw runtime_error("The cowboy is dead");
        }
        this->numOfBullets = 6;
    }

    void Cowboy::shoot(Character *enemy)
    {
        if (this->isAlive() == false)
        {
            throw runtime_error("The cowboy is dead");
        }
        if (enemy->isAlive() == false)
        {
            throw runtime_error("The enemy is dead");
        }
        if (this == enemy)
        {
            throw runtime_error("The cowboy cannot be the enemy");
        }
        if (this->hasboolets() == true)
        {
            enemy->hit(10);
            setAmoutOfBullets();
        }
    }

    void Cowboy::attack(Character *enemy)
    {
        if (isAlive() == false || enemy->isAlive() == false)
            return;
        if (hasboolets() == true)
            shoot(enemy);
        else
            reload();
    }

    string Cowboy::print()
    {
        string name = "Character name is :" + this->getName();
        string location = "\nhis location is :" + this->getLocation().print();
        string health = "\nand he has a " + to_string(this->getHealth()) + " hit points\n\n\n";
        if (isAlive() == false)
        {
            name = "Character name is : " + this->getName();
            health = "\n\n\n";
        }
        return (name + location + health);
    }
}