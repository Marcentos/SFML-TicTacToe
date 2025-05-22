#include "Stdafx.h"
#include "GameInstance.h"
#include "ScoreLabel.h"

// Constructors
TicTacToe::Instance::Instance(uint8_t inputMapRowSize, uint8_t inputMapColumnSize) :
	isPlayerTurn(true),
	
	playerScore(0),
	opponentScore(0),

	inputMapRowSize(inputMapRowSize),
	inputMapColumnSize(inputMapColumnSize),
	currentInputMap(new uint16_t*[inputMapRowSize]),

	scoreLabel("Player", "Opponent", *this),

	gridTexture("./textures/grid.png"),
	gridSprite(gridTexture),

	playerSymbolTexture("./textures/symbols.png", false, sf::IntRect({0, 0}, {TILE_WIDTH, TILE_HEIGHT})),
	playerSymbolSprite(playerSymbolTexture),

	opponentSymbolTexture("./textures/symbols.png", false, sf::IntRect({TILE_WIDTH, 0}, {TILE_WIDTH, TILE_HEIGHT})),
	opponentSymbolSprite(opponentSymbolTexture)
{
	for (auto Iteration = 0; Iteration < inputMapRowSize; ++Iteration)
	{ currentInputMap[Iteration] = new uint16_t[inputMapColumnSize](0); }
}

TicTacToe::Instance::Instance() : Instance(3, 3)
{	}

TicTacToe::Instance::~Instance()
{	}

// Get
bool TicTacToe::Instance::getPlayerTurn()
{ return isPlayerTurn; }

uint16_t TicTacToe::Instance::getPlayerScore()
{ return playerScore; }

uint16_t TicTacToe::Instance::getOpponentScore()
{ return opponentScore; }

sf::Sprite TicTacToe::Instance::getGridSprite()
{ return gridSprite; }

TicTacToe::Label& TicTacToe::Instance::getScoreLabel()
{ return scoreLabel; }

uint16_t**& TicTacToe::Instance::getCurrentInputMap()
{ return currentInputMap; }

// Set
void TicTacToe::Instance::setPlayerTurn(bool setValue)
{ isPlayerTurn = setValue; }

void TicTacToe::Instance::setPlayerScore(uint16_t setValue)
{ playerScore = setValue; }

void TicTacToe::Instance::setOpponentScore(uint16_t setValue)
{ opponentScore = setValue; }

// Other
void TicTacToe::Instance::displayCurrentInputMap(sf::RenderWindow& windowHandler)
{
	for (auto rowIteration = 0; rowIteration < inputMapRowSize; ++rowIteration)
	{
		for (auto columnIteration = 0; columnIteration < inputMapColumnSize; ++columnIteration)
		{
			float spritePositionX = columnIteration * TILE_WIDTH;
			float spritePositionY = rowIteration * TILE_HEIGHT;

			if (currentInputMap[rowIteration][columnIteration] == 1)
			{
				playerSymbolSprite.setPosition(sf::Vector2f({spritePositionX, spritePositionY}));
				windowHandler.draw(playerSymbolSprite); 
			}
			else if (currentInputMap[rowIteration][columnIteration] == 2)
			{
				opponentSymbolSprite.setPosition(sf::Vector2f({ spritePositionX, spritePositionY }));
				windowHandler.draw(opponentSymbolSprite);
			}
		}
	}
}

void TicTacToe::Instance::c_displayCurrentInputMap()
{
	for (auto rowIteration = 0; rowIteration < inputMapRowSize; ++rowIteration)
	{
		for (auto columnIteration = 0; columnIteration < inputMapColumnSize; ++columnIteration)
		{ std::cout << currentInputMap[rowIteration][columnIteration] << " "; }
		std::cout << std::endl;
	}
}

bool TicTacToe::Instance::checkIfMapFilled()
{
	for (auto rowIteration = 0; rowIteration < inputMapRowSize; ++rowIteration)
	{
		for (auto columnIteration = 0; columnIteration < inputMapColumnSize; ++columnIteration)
		{
			if (currentInputMap[rowIteration][columnIteration] == 0) return false;
		}
	}
	return true;
}

bool TicTacToe::Instance::verifyPlayerMap()
{
	bool verified = false;
	
	// 1 - -
	// 1 - -
	// 1 - -
	if      (currentInputMap[0][0] == 1 && currentInputMap[1][0] == 1 && currentInputMap[2][0] == 1) verified = true;
	else if (currentInputMap[0][1] == 1 && currentInputMap[1][1] == 1 && currentInputMap[2][1] == 1) verified = true;
	else if (currentInputMap[0][2] == 1 && currentInputMap[1][2] == 1 && currentInputMap[2][2] == 1) verified = true;

	// 1 1 1
	// - - -
	// - - -
	else if (currentInputMap[0][0] == 1 && currentInputMap[0][1] == 1 && currentInputMap[0][2] == 1) verified = true;
	else if (currentInputMap[1][0] == 1 && currentInputMap[1][1] == 1 && currentInputMap[1][2] == 1) verified = true;
	else if (currentInputMap[2][0] == 1 && currentInputMap[2][1] == 1 && currentInputMap[2][2] == 1) verified = true;

	// 1 - -
	// - 1 -
	// - - 1
	else if (currentInputMap[0][0] == 1 && currentInputMap[1][1] == 1 && currentInputMap[2][2] == 1) verified = true;

	// - - 1
	// - 1 -
	// 1 - -
	else if (currentInputMap[2][0] == 1 && currentInputMap[1][1] == 1 && currentInputMap[0][2] == 1) verified = true;

	return verified;
}

bool TicTacToe::Instance::verifyOpponentMap()
{
	bool verified = false;
	
	// 2 - -
	// 2 - -
	// 2 - -
	if      (currentInputMap[0][0] == 2 && currentInputMap[1][0] == 2 && currentInputMap[2][0] == 2) verified = true;
	else if (currentInputMap[0][1] == 2 && currentInputMap[1][1] == 2 && currentInputMap[2][1] == 2) verified = true;
	else if (currentInputMap[0][2] == 2 && currentInputMap[1][2] == 2 && currentInputMap[2][2] == 2) verified = true;

	// 2 2 2
	// - - -
	// - - -
	else if (currentInputMap[0][0] == 2 && currentInputMap[0][1] == 2 && currentInputMap[0][2] == 2) verified = true;
	else if (currentInputMap[1][0] == 2 && currentInputMap[1][1] == 2 && currentInputMap[1][2] == 2) verified = true;
	else if (currentInputMap[2][0] == 2 && currentInputMap[2][1] == 2 && currentInputMap[2][2] == 2) verified = true;

	// 2 - -
	// - 2 -
	// - - 2
	else if (currentInputMap[0][0] == 2 && currentInputMap[1][1] == 2 && currentInputMap[2][2] == 2) verified = true;

	// - - 2
	// - 2 -
	// 2 - -
	else if (currentInputMap[2][0] == 2 && currentInputMap[1][1] == 2 && currentInputMap[0][2] == 2) verified = true;

	return verified;
}

void TicTacToe::Instance::doPseudoBotStep()
{
	std::srand(std::time(nullptr));

	int chosenRow = 0, chosenColumn = 0;
	while (currentInputMap[chosenRow][chosenColumn] != 0)
	{ 
		chosenRow = std::rand() % 3; 
		chosenColumn = std::rand() % 3; 
	}

	currentInputMap[chosenRow][chosenColumn] = 2;
}

void TicTacToe::Instance::fullVerify()
{
	if (verifyPlayerMap())
	{
		setPlayerScore(getPlayerScore() + 1);

		sf::sleep(sf::seconds(2.5f));

		resetInputMap();
		setPlayerTurn(true);
	}
	else if (verifyOpponentMap())
	{
		setOpponentScore(getOpponentScore() + 1);

		sf::sleep(sf::seconds(2.5f));

		resetInputMap();
		setPlayerTurn(false);
	}
	else if (checkIfMapFilled())
	{
		sf::sleep(sf::seconds(2.5f));

		resetInputMap();
		setPlayerTurn(true);
	}

	scoreLabel.updateLabelText();
}

void TicTacToe::Instance::resetInputMap()
{
	currentInputMap = new uint16_t*[inputMapRowSize];
	for (auto Iteration = 0; Iteration < inputMapRowSize; ++Iteration)
	{ currentInputMap[Iteration] = new uint16_t[inputMapColumnSize](0); }
}