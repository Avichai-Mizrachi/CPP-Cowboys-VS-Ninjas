#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        // This constructor allows the creation of a OldNinja object
        // by initializing both the OldNinja part
        // and the base class Ninja part using the given name,
        // location, and default values for HP and speed.
        OldNinja(string name, Point location) : Ninja(std::move(name), location, 150, 8) {}
    };
}