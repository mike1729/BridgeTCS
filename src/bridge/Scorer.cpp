#include "Scorer.hpp"

namespace bridge 
{

void Scorer::update(const DealResult & result)
{
	TeamScore & declaringTeam = (result.contract.declarer % 2 == 0) ? firstTeam : secondTeam;
	TeamScore & defendingTeam = (result.contract.declarer % 2 == 0) ? secondTeam : firstTeam;
	int overtricks = result.declarerTakenTricks - result.contract.level - 6;
	
	if ( overtricks >= 0) // declaring team won
	{
		int contractPoints = 0;
		if ( result.contract.denomination == Denomination::NT )
		{
			contractPoints += 40;
			contractPoints += 30 * (result.contract.level - 1);
		}
		else if ( result.contract.denomination == Denomination::SPADES || result.contract.denomination == Denomination:: HEARTS )
			contractPoints += 30 * result.contract.level;
		else
			contractPoints += 20 * result.contract.level;

		contractPoints *= result.contract.pointMultiplier;
		declaringTeam.updatePointsBelow(contractPoints);
		
		int bonusPoints = 0;
		if ( result.contract.pointMultiplier == 1 ) // not doubled
		{
			if ( result.contract.denomination == Denomination::NT || result.contract.denomination == Denomination::SPADES || result.contract.denomination == Denomination:: HEARTS ) // major suits
				bonusPoints += 30*overtricks;
			else // minor suits
				bonusPoints += 20*overtricks;
		} else //doubled or redoubled
		{
			bonusPoints += 50*result.contract.pointMultiplier * overtricks;
			
			if ( declaringTeam.isVulnerable() ) 
				bonusPoints *= 2;
			bonusPoints += 25*result.contract.pointMultiplier; // bonus for making (re)doubled
		}
		if ( result.contract.level == 6 )
		{
			bonusPoints += 500;
			if ( declaringTeam.isVulnerable() )
				bonusPoints += 250;
		}
		if ( result.contract.level == 7 )
		{
			bonusPoints += 1000;
			if ( declaringTeam.isVulnerable() )
				bonusPoints += 500;
		}
		if ( contractPoints >= 100 ) //becoming vulnerable, possibly finished rubber
		{
			if ( declaringTeam.isVulnerable() ) //finished rubber
			{
				bonusPoints += 500;
				if ( !defendingTeam.isVulnerable() )
					bonusPoints += 200;
			}
			declaringTeam.setVulnerability(true);
		}
		declaringTeam.updatePointsAbove(bonusPoints);
	} else // defending team won
	{
		int undertricks = -overtricks;
		int bonusPoints = 0;
		if ( declaringTeam.isVulnerable() )
		{
			if ( result.contract.pointMultiplier == 1 ) // not doubled
				bonusPoints += 100 * undertricks;
			else //doubled or redoubled
			{
				bonusPoints += 100 * result.contract.pointMultiplier * undertricks;
				if ( undertricks > 1 )
					bonusPoints += 50 * result.contract.pointMultiplier * ( undertricks - 1 );
			}
		} else // declaring team not vulnerable
		{
			if ( result.contract.pointMultiplier == 1 ) // not doubled
				bonusPoints += 50 * undertricks;
			else //doubled or redoubled
			{
				bonusPoints += 50 * result.contract.pointMultiplier * undertricks;
				if ( undertricks > 1 )
					bonusPoints += 50 * result.contract.pointMultiplier * ( undertricks - 1 );
				if ( undertricks > 3 )
					bonusPoints += 50 * result.contract.pointMultiplier * ( undertricks - 3 );
			}
		}
		defendingTeam.updatePointsAbove(bonusPoints);
	}
}

} // namespace bridge
