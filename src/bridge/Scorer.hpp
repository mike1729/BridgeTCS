#ifndef BRIDGE_SCORER_HPP
#define BRIDGE_SCORER_HPP

#include "Deal.hpp"

namespace bridge {

struct TeamScore {
    TeamScore(): aboveTheLine(0), belowTheLine(0) {}
    int getPointsAbove() {
        return aboveTheLine;
    }
    int getPointsBelow() {
        return belowTheLine;
    }
    int updatePointsAbove(int points) 
    {
        aboveTheLine += points;
    }
    int updatePointsBelow(int points)
    {
        belowTheLine += points;
    }
private:
    int aboveTheLine;
    int belowTheLine;
}

struct Scorer
{
    Scorer() {}
    void update(const DealResult & result) 
    {
        TeamScore team = (result.declarer % 2 == 0) ? firstTeam : secondTeam;
        //TODO: Compute score result to bridge rules
        if (result.contract.level >= result.declarerTakenTricks) {
            team.updatePointsBelow(result.contract.level*10);
            team.updatePointsAbove( (result.declarerTakenTricks - result.contract.level)*20);
        }
        printf("first:%d %d\n",firstTeam.getPointsAbove(),firstTeam.getPointsBelow());
        printf("second:%d %d\n",secondTeam.getPointsAbove(),firstTeam.getPointsBelow());

    }
private:
    TeamScore fistTeam, secondTeam;
}
    
}

#endif
