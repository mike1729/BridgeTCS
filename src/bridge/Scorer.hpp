#ifndef BRIDGE_SCORER_HPP
#define BRIDGE_SCORER_HPP

#include "Deal.hpp"

namespace bridge {

struct TeamScore {
	TeamScore(): aboveTheLine(0), belowTheLine(0), vulnerable(false) {}
	int getPointsAbove() const 
	{
		return aboveTheLine;
	}
	int getPointsBelow() const 
	{
		return belowTheLine;
	}
	bool isVulnerable() const
	{
		return vulnerable;
	}
	void updatePointsAbove(int points) 
	{
		aboveTheLine += points;
	}
	void updatePointsBelow(int points)
	{
		belowTheLine += points;
	}
	void setVulnerability(bool newVulnerability)
	{
		vulnerable = newVulnerability;
	}
	private:
	int aboveTheLine;
	int belowTheLine;
	bool vulnerable;
};

struct Scorer
{
	Scorer() {}
	void update(const DealResult & result);

	const TeamScore& getFirstTeam() const { return firstTeam; }
	const TeamScore& getSecondTeam() const { return secondTeam; }

	private:
	TeamScore firstTeam, secondTeam;
};

}
#endif
