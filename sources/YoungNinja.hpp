#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        // This constructor allows the creation of a YoungNinja object
        // by initializing both the YoungNinja part
        // and the base class Ninja part using the given name,
        // location, and default values for HP and speed.
        YoungNinja(string name, const Point &location) : Ninja(std::move(name), location, 100, 14) {}
    };
}