#pragma once
#include "Team.hpp"
#include <vector>

using namespace std;

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *leader);
        void add(Character *newPlayer) override;
    };
}