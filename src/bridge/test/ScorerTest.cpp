#include <gtest/gtest.h>
#include "bridge/Scorer.hpp"

namespace bridge {

class ScorerTest: public ::testing::Test
{
public:
	Scorer *scorer;
	DealResult result;
	
	void SetUp()
	{
		scorer = new Scorer();
	}
	
	void TearDown()
	{
		delete scorer;
	}
};

TEST_F(ScorerTest, WonMinorExact) 
{
	Contract con;
	con.denomination = Denomination::CLUBS;
	con.declarer = 0;
	
	for ( int i = 1; i <= 7; i++ )
	{
		delete scorer;
		scorer = new Scorer();
		con.level = i;
		result.contract = con;
		result.tricksWon = 6 + i;
		scorer->update(result);
		EXPECT_EQ(false, scorer->gameOver());
		EXPECT_EQ(20*i, scorer->getFirstTeam().getPointsBelow());
		
		if ( i < 5 )
		{
			EXPECT_EQ(false, scorer->getFirstTeam().isVulnerable());
		}
		else
		{
			EXPECT_EQ(true, scorer->getFirstTeam().isVulnerable());
		}
		
		if ( i < 6 )
		{
			EXPECT_EQ(0, scorer->getFirstTeam().getPointsAbove());
		}
		else
		{
			EXPECT_EQ(500*(i - 5), scorer->getFirstTeam().getPointsAbove());
		}
		
		EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());
		EXPECT_EQ(0, scorer->getSecondTeam().getPointsAbove());
	}
	
	con.denomination = Denomination::DIAMONDS;
	
	for ( int i = 1; i <= 7; i++ )
	{
		delete scorer;
		scorer = new Scorer();
		con.level = i;
		result.contract = con;
		result.tricksWon = 6 + i;
		scorer->update(result);
		EXPECT_EQ(false, scorer->gameOver());
		EXPECT_EQ(20*i, scorer->getFirstTeam().getPointsBelow());
		
		if ( i < 5 )
		{
			EXPECT_EQ(false, scorer->getFirstTeam().isVulnerable());
		}
		else
		{
			EXPECT_EQ(true, scorer->getFirstTeam().isVulnerable());
		}
		
		if ( i < 6 )
		{
			EXPECT_EQ(0, scorer->getFirstTeam().getPointsAbove());
		}
		else
		{
			EXPECT_EQ(500*(i - 5), scorer->getFirstTeam().getPointsAbove());
		}
		EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());
		EXPECT_EQ(0, scorer->getSecondTeam().getPointsAbove());
	}
}

TEST_F(ScorerTest, WonMajorExact) 
{
	Contract con;
	con.denomination = Denomination::HEARTS;
	con.declarer = 0;
	for ( int i = 1; i <= 7; i++ )
	{
		delete scorer;
		scorer = new Scorer();
		con.level = i;
		result.contract = con;
		result.tricksWon = 6 + i;
		scorer->update(result);
		EXPECT_EQ(false, scorer->gameOver());
		EXPECT_EQ(30*i, scorer->getFirstTeam().getPointsBelow());
		
		if ( i < 4 )
		{
			EXPECT_EQ(false, scorer->getFirstTeam().isVulnerable());
		}
		else
		{
			EXPECT_EQ(true, scorer->getFirstTeam().isVulnerable());
		}
		
		if ( i < 6 )
		{
			EXPECT_EQ(0, scorer->getFirstTeam().getPointsAbove());
		}
		else
		{
			EXPECT_EQ(500*(i - 5), scorer->getFirstTeam().getPointsAbove());
		}
		
		EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());
		EXPECT_EQ(0, scorer->getSecondTeam().getPointsAbove());
	}
	
	con.denomination = Denomination::SPADES;
	
	for ( int i = 1; i <= 7; i++ )
	{
		delete scorer;
		scorer = new Scorer();
		con.level = i;
		result.contract = con;
		result.tricksWon = 6 + i;
		scorer->update(result);
		EXPECT_EQ(false, scorer->gameOver());
		EXPECT_EQ(30*i, scorer->getFirstTeam().getPointsBelow());
		
		if ( i < 4 )
		{
			EXPECT_EQ(false, scorer->getFirstTeam().isVulnerable());
		}
		else
		{
			EXPECT_EQ(true, scorer->getFirstTeam().isVulnerable());
		}
		
		if ( i < 6 )
		{
			EXPECT_EQ(0, scorer->getFirstTeam().getPointsAbove());
		}
		else
		{
			EXPECT_EQ(500*(i - 5), scorer->getFirstTeam().getPointsAbove());
		}
		
		EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());
		EXPECT_EQ(0, scorer->getSecondTeam().getPointsAbove());
	}
}

TEST_F(ScorerTest, WonNoTrumpExact) 
{
	Contract con;
	con.denomination = Denomination::NT;
	con.declarer = 0;
	
	for ( int i = 1; i <= 7; i++ )
	{
		delete scorer;
		scorer = new Scorer();
		con.level = i;
		result.contract = con;
		result.tricksWon = 6 + i;
		scorer->update(result);
		EXPECT_EQ(false, scorer->gameOver());
		EXPECT_EQ(40 + 30*(i-1), scorer->getFirstTeam().getPointsBelow());
		
		if ( i < 3 )
		{
			EXPECT_EQ(false, scorer->getFirstTeam().isVulnerable());
		}
		else
		{
			EXPECT_EQ(true, scorer->getFirstTeam().isVulnerable());
		}
		
		if ( i < 6 )
		{
			EXPECT_EQ(0, scorer->getFirstTeam().getPointsAbove());
		}
		else
		{
			EXPECT_EQ(500*(i - 5), scorer->getFirstTeam().getPointsAbove());
		}
		
		EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());
		EXPECT_EQ(0, scorer->getSecondTeam().getPointsAbove());
	}
}

TEST_F(ScorerTest, TwoDealsGame) 
{ 
	Contract con;
	con.denomination = Denomination::NT;
	con.declarer = 0;
	con.level = 3;
	result.contract = con;
	result.tricksWon = 9;
	
	scorer->update(result);
	
	EXPECT_EQ(false, scorer->gameOver());
	EXPECT_EQ(100, scorer->getFirstTeam().getPointsBelow());
	EXPECT_EQ(true, scorer->getFirstTeam().isVulnerable());
	EXPECT_EQ(0, scorer->getFirstTeam().getPointsAbove());
	EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());
	EXPECT_EQ(0, scorer->getSecondTeam().getPointsAbove());
	
	scorer->update(result);
	
	EXPECT_EQ(true, scorer->gameOver());
	EXPECT_EQ(100, scorer->getFirstTeam().getPointsBelow());
	EXPECT_EQ(800, scorer->getFirstTeam().getPointsAbove());
	EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());
	EXPECT_EQ(0, scorer->getSecondTeam().getPointsAbove());
}

} //namespace bridge
