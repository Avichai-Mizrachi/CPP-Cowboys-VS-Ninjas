#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <string>
#include <iostream>

using namespace std;

namespace ariel
{
    // General ninja functions
    // Constructor
    Ninja ::Ninja(string name, const Point &location, int health, int speed) : Character(name, location, health), speed(speed) {}

    // Moving the ninja toward the enemy
    void Ninja ::move(Character *enemy)
    {
        if (isAlive() == false)
        {
            return;
        }
        Point source = this->getLocation();
        Point destination = enemy->getLocation();
        Point temp = Point::moveTowards(source, destination, this->getSpeed());
        this->setLocation(temp);
    }

    // Slash the enemy
    void Ninja ::slash(Character *other)
    {
        if (isAlive() == false)
        {
            throw runtime_error("Ninja is not alive");
        }

        if (other->isAlive() == false)
        {
            throw runtime_error("Target is not alive");
        }

        if (this == other)
        {
            throw runtime_error("Cannot attack itself");
        }
        if (isAlive() && this->getLocation().distance(other->getLocation()) < 1)
        {
            other->hit(40);
        }
    }

    // Attack the enemy by using the "slash" method
    void Ninja::attack(Character *other)
    {
        if (!isAlive() || !other->isAlive())
            return;
        if (distance(other) <= 1)
            slash(other);
        else
            move(other);
    }

    // Return the ninja details
    string Ninja ::print()
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