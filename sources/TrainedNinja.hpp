#pragma once
#include "Ninja.hpp"

namespace ariel{
        class TrainedNinja : public Ninja{
        public:
            // This constructor allows the creation of a TrainedNinja object
            // by initializing both the TrainedNinja part
            // and the base class Ninja part using the given name,
            // location, and default values for HP and speed.
            TrainedNinja(string name,Point location) : Ninja(std::move(name), location, 120, 12){}
    };
}