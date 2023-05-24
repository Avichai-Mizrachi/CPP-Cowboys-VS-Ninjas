#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

using namespace std;

namespace ariel
{

    Character::Character(const string &name, const Point &location, int health) : name(name), location(location), health(health), gotATeam(false) {}

    Character::Character(const Character &other) : name(other.name), location(other.location), health(other.health), gotATeam(other.gotATeam) {}

    Character::Character(Character &&other) noexcept : name(other.name), location(other.location), health(other.health), gotATeam(other.gotATeam) {}

    Character &Character::operator=(const Character &other)
    {
        if (this == &other)
        {
            return *this;
        }

        name = other.name;
        location = other.location;
        health = other.health;
        gotATeam = other.gotATeam;

        return *this;
    }

    Character &Character::operator=(Character &&other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        name = move(other.name);
        location = move(other.location);
        health = other.health;
        gotATeam = other.gotATeam;

        return *this;
    }

    double Character::distance(Character *other)
    {
        if (other == nullptr)
        {
            throw invalid_argument("Null can't be a character");
        }

        Point otherPoint = other->getLocation();
        return this->getLocation().distance(otherPoint);
    }

    bool Character::isAlive()
    {
        return (health > 0);
    }

    void Character::hit(int damage)
    {
        if (damage < 0)
        {
            throw invalid_argument("Damage cannot be negative.");
        }

        if ((this->health - damage) < 0)
        {
            this->health = 0;
        }

        health = health - damage;
    }
}