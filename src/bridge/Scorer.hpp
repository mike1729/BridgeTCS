#ifndef BRIDGE_SCORER_HPP
#define BRIDGE_SCORER_HPP

#include "Deal.hpp"

namespace bridge {

class TeamScore {
public:
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
	
	bool finishedRubber() const
	{
		return rubber;
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
		rubber = vulnerable && newVulnerability;
		vulnerable = newVulnerability;
	}
private:
	int aboveTheLine = 0;
	int belowTheLine = 0;
	bool vulnerable = false;
	bool rubber = false;
};

class Scorer
{
public:
	void update(const DealResult & result);
	
	const TeamScore& getFirstTeam() const
	{
		return firstTeam;
	}
	
	const TeamScore& getSecondTeam() const
	{
		return secondTeam;
	}
	
	bool gameOver() const
	{
		return firstTeam.finishedRubber() || secondTeam.finishedRubber();
	}

private:
	TeamScore firstTeam, secondTeam;
};

}
#endif
