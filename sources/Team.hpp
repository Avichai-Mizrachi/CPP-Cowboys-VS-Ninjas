#pragma once

#include <vector>
#include <cfloat>
#include <stdexcept>
#include <vector>
#include <iostream>

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

namespace ariel
{
    class Team
    {

    private:
        Character *leader;
        vector<Character *> team;

    public:
        Team(Character *leader);
        Team(const Team &enemyTeam);
        Team(Team &&enemyTeam) noexcept;
        Team &operator=(const Team &enemyTeam);
        Team &operator=(Team &&enemyTeam) noexcept;
        virtual ~Team(){};
        Character *closest(vector<Character *> &, const Point &);

        int stillAlive();
        void attack(Team *otherTeam);
        virtual void add(Character *);
        void print() const;
        Character *getLeader() { return leader; }
        vector<Character *> &getTeam() { return team; }
    };
}