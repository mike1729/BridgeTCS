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

TEST_F(ScorerTest, DoubleTest) {
	Contract con;
	
	// Team 0: 7HX
	con.denomination = Denomination::HEARTS;
	con.declarer = 0;
	con.pointMultiplier = 2;
	con.level = 7;
	result.contract = con;
	result.tricksWon = 5;	// 5-7-6 = -8 -> 8 undertricks
	
	scorer->update(result);
	
	EXPECT_EQ(false, scorer->gameOver());
	
	EXPECT_EQ(0, scorer->getFirstTeam().getPointsBelow());
	EXPECT_EQ(0, scorer->getFirstTeam().getPointsAbove());
	EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());
	EXPECT_EQ(2000, scorer->getSecondTeam().getPointsAbove());	// 50*2*8 + 50*2*7 + 50*2*5
	EXPECT_EQ(false, scorer->getFirstTeam().isVulnerable());
	EXPECT_EQ(false, scorer->getSecondTeam().isVulnerable());

	// Team 1: 2SX
	con.denomination = Denomination::SPADES;
	con.declarer = 1;
	con.pointMultiplier = 2;
	con.level = 2;
	result.contract = con;
	result.tricksWon = 7;	// 7-2-6 = -1 -> 1 undertrick
	
	scorer->update(result);
	
	EXPECT_EQ(0, scorer->getFirstTeam().getPointsBelow());
	EXPECT_EQ(100, scorer->getFirstTeam().getPointsAbove());	// 50*2*1
	EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());
	EXPECT_EQ(2000, scorer->getSecondTeam().getPointsAbove());
	EXPECT_EQ(false, scorer->getFirstTeam().isVulnerable());
	EXPECT_EQ(false, scorer->getSecondTeam().isVulnerable());
	
	// Team 0: 6NTX
	con.denomination = Denomination::NT;
	con.declarer = 0;
	con.pointMultiplier = 2;
	con.level = 6;
	result.contract = con;
	result.tricksWon = 13;// 13-6-6 = 1 -> 1 overtrick
	
	scorer->update(result);
	
	EXPECT_EQ(380, scorer->getFirstTeam().getPointsBelow());	// (40+30*5)*2
	EXPECT_EQ(750, scorer->getFirstTeam().getPointsAbove());	// 50*2*1+25*2+500
	EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());
	EXPECT_EQ(2000, scorer->getSecondTeam().getPointsAbove());
	EXPECT_EQ(true, scorer->getFirstTeam().isVulnerable());
	EXPECT_EQ(false, scorer->getSecondTeam().isVulnerable());
	
	//Team 1: 4S
	con.denomination = Denomination::SPADES;
	con.declarer = 1;
	con.pointMultiplier = 1;
	con.level = 4;
	result.contract = con;
	result.tricksWon = 11;// 11-4-6 = 1 -> 1 overtrick
	
	scorer->update(result);
	
	EXPECT_EQ(0, scorer->getFirstTeam().getPointsBelow());		//-380
	EXPECT_EQ(1130, scorer->getFirstTeam().getPointsAbove());	//+380
	EXPECT_EQ(120, scorer->getSecondTeam().getPointsBelow());	//30*4=120
	EXPECT_EQ(2030, scorer->getSecondTeam().getPointsAbove());	//30*1=30
	EXPECT_EQ(true, scorer->getFirstTeam().isVulnerable());
	EXPECT_EQ(true, scorer->getSecondTeam().isVulnerable());
	
	//Team 0: 7D
	con.denomination = Denomination::DIAMONDS;
	con.declarer = 0;
	con.pointMultiplier = 1;
	con.level = 7;
	result.contract = con;
	result.tricksWon = 13;// 13-7-6=0
	
	scorer->update(result);
	
	EXPECT_EQ(140, scorer->getFirstTeam().getPointsBelow());	//20*7=140
	EXPECT_EQ(3130, scorer->getFirstTeam().getPointsAbove());	//1000+500+500=2000
	EXPECT_EQ(0, scorer->getSecondTeam().getPointsBelow());		//-120
	EXPECT_EQ(2150, scorer->getSecondTeam().getPointsAbove());	//+120
	EXPECT_EQ(true, scorer->getFirstTeam().isVulnerable());
	EXPECT_EQ(true, scorer->getSecondTeam().isVulnerable());
	
	EXPECT_EQ(true, scorer->gameOver());
}

} //namespace bridge
