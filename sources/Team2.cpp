#include "Team2.hpp"
#include <vector>

using namespace std;

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader) {}

    void Team2::add(Character *newPlayer)
    {
        if (newPlayer != nullptr && newPlayer->isAlive() && !newPlayer->inTeam() && getTeam().size() < 10)
        {
            getTeam().push_back(newPlayer);
            newPlayer->setInTeam(true);
        }
        else
        {
            throw runtime_error("This character cannot be added");
        }
    }
}