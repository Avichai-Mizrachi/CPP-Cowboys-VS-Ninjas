#pragma once
#include "Team.hpp"

namespace ariel
{
    class smartTeam : public Team
    {
    public:
        smartTeam(Character *leader) : Team(leader){};
    };
}