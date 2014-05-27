#include "Game.hpp"
#include <iostream>

namespace ui 
{
namespace text 
{

void Game::showScore(const bridge::Game & game)
{
	std::cout << "Here is place for score or sth\n";
}
void Game::registerDeal(const bridge::Game & game)
{
	game.getDeal().sigModified.connect([this](bridge::Deal const & deal) {
		this->dealView.notify(deal);
	});
	
}

} // namespace text
} // namespace ui
