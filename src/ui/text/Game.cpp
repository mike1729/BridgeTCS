#include "Game.hpp"
#include <iostream>

namespace ui 
{
namespace text 
{

void Game::showScore(const bridge::Game & game)
{
	//std::cout << "Here is place for score or sth\n";
	const bridge::Scorer & scorer = game.getScorer();
	std:: cout << "Points:\nFirst team score below the line " << scorer.getFirstTeam().getPointsBelow() << "and above the line " << scorer.getFirstTeam().getPointsAbove() << ".\n";
	std:: cout << "Points:\nSecond team score below the line " << scorer.getSecondTeam().getPointsBelow() << "and above the line " << scorer.getSecondTeam().getPointsAbove() << ".\n";
}
void Game::registerDeal(const bridge::Game & game)
{
	game.getDeal().sigModified.connect([this](bridge::Deal const & deal) {
		this->dealView.notify(deal);
	});
	
}

} // namespace text
} // namespace ui
