#include "Team.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel
{
    //Constructors
    Team::Team(Character *leader) : leader(leader)
    {
        if (leader->inTeam())
        {
            throw runtime_error("The leader already exists");
        }
        team.push_back(leader);
        leader->setInTeam(true);
    }

    Team::Team(const Team &enemyTeam) : leader(enemyTeam.leader) {}

    Team::Team(Team &&enemyTeam) noexcept
    {
        leader = enemyTeam.leader;
        team = enemyTeam.team;
    }

    Team &Team::operator=(const Team &enemyTeam)
    {
        leader = enemyTeam.leader;
        team = enemyTeam.team;
        return *this;
    }

    Team &Team::operator=(Team &&enemyTeam) noexcept
    {
        leader = enemyTeam.leader;
        team = enemyTeam.team;
        return *this;
    }

    // Check if there is someone alive in the team
    int Team::stillAlive()
    {
        int counter = 0;
        for (Character *member : team)
            if (member->isAlive())
                counter++;
        return counter;
    }

    // Attack the enemy team
    void Team::attack(Team *other)
    {
        if (!other)
            throw invalid_argument("Enemy not found");

        if (stillAlive() == 0 || other->stillAlive() == 0)
            throw runtime_error("One team is dead");

        if (leader->isAlive() == false)
            leader = closest(this->team, leader->getLocation());

        Character *target = nullptr;

        if (other->stillAlive() > 0)
            target = closest(other->team, leader->getLocation());
        else
            return;

        for (auto member : team)
        {
            if (member != nullptr && member->isAlive())
            {
                if (target != nullptr && target->isAlive())
                {
                    member->attack(target);
                }
                else
                {
                    target = closest(other->team, leader->getLocation());
                    if (target != nullptr && target->isAlive())
                    {
                        member->attack(target);
                    }
                }
            }
        }
    }

    // Checking who is the closest enemy nearby the leader
    Character *Team::closest(vector<Character *> &other, const Point &)
    {
        double minDistance = DBL_MAX;
        Character *result = NULL;
        for (Character *member : other)
            if (member->isAlive() && leader->distance(member) < minDistance)
            {
                minDistance = leader->distance(member);
                result = member;
            }
        return result;
    }

    // Print the team details
    void Team::print() const
    {
        for (Character *member : team)
            cout << member->print() << endl;
    }

    // Add character to the team
    void Team::add(Character *newChar)
    {
        if (newChar != nullptr && newChar->isAlive() && !newChar->inTeam() && team.size() < 10)
        {
            if (dynamic_cast<Cowboy *>(newChar) != nullptr)
                team.insert(team.begin(), newChar);
            else
                team.push_back(newChar);
            newChar->setInTeam(true);
        }
        else
        {
            throw runtime_error("This character connot be added");
        }
    }
}