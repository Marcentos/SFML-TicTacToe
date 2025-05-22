#pragma once

#include "Stdafx.h"

namespace TicTacToe
{
	class Instance; 

	class Label
	{
	public:
		Label(std::string paramPlayerName, std::string paramOpponentName, Instance& paramInstance);
		~Label();

		sf::Text& getLabelText();
		void updateLabelText();
	private:
		std::string playerName;
		std::string opponentName;

		TicTacToe::Instance* instanceReference;

		sf::Font fontHandler;
		sf::Text textHandler;
	};
}