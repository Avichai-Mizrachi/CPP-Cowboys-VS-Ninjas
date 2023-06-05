#include "Cowboy.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>

using namespace std;

namespace ariel
{
    // Cowboy functions
    // Constructor
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), numOfBullets(6) {}

    // Check if the cowboy still have bullets
    bool Cowboy::hasboolets()
    {
        if (this->numOfBullets > 0)
        {
            return true;
        }
        return false;
    }

    // Reload the gun
    void Cowboy::reload()
    {
        if (this->isAlive() == false)
        {
            throw runtime_error("The cowboy is dead");
        }
        this->numOfBullets = 6;
    }

    // Shoot the enemy
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

    // Attacking and enemy by using the shoot method
    void Cowboy::attack(Character *enemy)
    {
        if (isAlive() == false || enemy->isAlive() == false)
            return;
        if (hasboolets() == true)
            shoot(enemy);
        else
            reload();
    }

    // Return the cowboy details
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