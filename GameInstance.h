#pragma once

#include "Stdafx.h"
#include "ScoreLabel.h"

namespace TicTacToe
{
	class Instance
	{
	public:
		Instance(uint8_t inputMapSize, uint8_t inputMapRowSize);

		Instance();
		~Instance();

		bool getPlayerTurn();
		void setPlayerTurn(bool);

		uint16_t getPlayerScore();
		void     setPlayerScore(uint16_t);
		uint16_t getOpponentScore();
		void     setOpponentScore(uint16_t);

		sf::Sprite getGridSprite();

		TicTacToe::Label& getScoreLabel();

		uint16_t**& getCurrentInputMap();
		void displayCurrentInputMap(sf::RenderWindow&);
		void c_displayCurrentInputMap(); // Console display 

		bool checkIfMapFilled();
		bool verifyPlayerMap();
		bool verifyOpponentMap();

		void doPseudoBotStep();

		void fullVerify();
		void resetInputMap();

	private:

		bool isPlayerTurn;
		uint16_t playerScore;
		uint16_t opponentScore;

		uint8_t inputMapRowSize;
		uint8_t inputMapColumnSize;
		uint16_t** currentInputMap;

		TicTacToe::Label scoreLabel;

		sf::Texture gridTexture;
		sf::Sprite  gridSprite;

		sf::Texture playerSymbolTexture;
		sf::Sprite  playerSymbolSprite;

		sf::Texture opponentSymbolTexture;
		sf::Sprite  opponentSymbolSprite;
	};
}