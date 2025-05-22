#include "Stdafx.h"
#include "ScoreLabel.h"
#include "GameInstance.h"

TicTacToe::Label::Label(std::string paramPlayerName, std::string paramOpponentName, Instance& paramInstance) :
	playerName(std::move(paramPlayerName)),
	opponentName(std::move(paramOpponentName)),

	instanceReference(&paramInstance),

	fontHandler(FONT_PATH),
	textHandler(fontHandler)
{
	textHandler.setPosition({0, WINDOW_HEIGHT - 70});
	textHandler.setCharacterSize(FONT_CHARACTER_SIZE);
	textHandler.setFillColor(sf::Color::White);

	textHandler.setString("Player:\nOpponent:");
	updateLabelText();
}

TicTacToe::Label::~Label()
{ delete instanceReference;	}

sf::Text& TicTacToe::Label::getLabelText()
{ return textHandler; }

void TicTacToe::Label::updateLabelText()
{ 
	textHandler.setString("Player: " + std::to_string(instanceReference->getPlayerScore()) + 
                          "\nOpponent: " + std::to_string(instanceReference->getOpponentScore())); 
}