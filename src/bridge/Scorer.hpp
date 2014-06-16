#ifndef BRIDGE_SCORER_HPP
#define BRIDGE_SCORER_HPP

#include "Deal.hpp"

namespace bridge {

struct TeamScore {
	TeamScore(): aboveTheLine(0), belowTheLine(0) {}
	int getPointsAbove() const {
		return aboveTheLine;
	}
	int getPointsBelow() const {
		return belowTheLine;
	}
	void updatePointsAbove(int points) 
	{
		aboveTheLine += points;
	}
	void updatePointsBelow(int points)
	{
		belowTheLine += points;
	}
	private:
	int aboveTheLine;
	int belowTheLine;
};

struct Scorer
{
	Scorer() {}
	void update(const DealResult & result) 
	{
		//TODO: Compute score result to bridge rules

		TeamScore & team1 = (result.contract.declarer % 2 == 0) ? firstTeam : secondTeam;
		TeamScore & team2 = (result.contract.declarer % 2 == 0) ? secondTeam : firstTeam;
		int extra = result.contract.level - result.declarerTakenTricks - 6;
		if ( extra >= 0) {
			team1.updatePointsBelow(result.contract.level*10);
			team1.updatePointsAbove(extra*20);
		} else {
			team2.updatePointsBelow(100);
		}
	}

	const TeamScore& getFirstTeam() const { return firstTeam; }
	const TeamScore& getSecondTeam() const { return secondTeam; }

	private:
	TeamScore firstTeam, secondTeam;
};

}
#endif
