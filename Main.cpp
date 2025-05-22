#include "Stdafx.h"
#include "GameInstance.h"

int main()
{
	// Creating application's window
	sf::RenderWindow gameWindow(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Tic-Tac-Toe");

	// Initializing game
	TicTacToe::Instance gameInstance;

	// Window's main loop
	while (gameWindow.isOpen())
	{
		while (auto eventHandler = gameWindow.pollEvent())
		{
			if (eventHandler->is<sf::Event::Closed>())
			{ gameWindow.close(); }

			if (auto keyHandler = eventHandler->getIf<sf::Event::KeyPressed>())
			{
				if (!gameInstance.getPlayerTurn() && keyHandler->scancode == sf::Keyboard::Scancode::Space)
				{
					gameInstance.doPseudoBotStep(); 

					gameInstance.displayCurrentInputMap(gameWindow);
					gameWindow.display();

					gameInstance.setPlayerTurn(true);
					gameInstance.fullVerify();
				}
			}

			if (auto mouseHandler = eventHandler->getIf<sf::Event::MouseButtonPressed>())
			{
				float mousePositionX = static_cast<float>(mouseHandler->position.x);
				float mousePositionY = static_cast<float>(mouseHandler->position.y);

				if (gameInstance.getGridSprite().getLocalBounds().contains({mousePositionX, mousePositionY}))
				{ 
					uint16_t tilePositionRow = mousePositionX / TILE_WIDTH;
					uint16_t tilePositionColumn = mousePositionY / TILE_WIDTH;

					std::cout << "\n(" << tilePositionRow << "; " << tilePositionColumn << ")\n";

					if (!gameInstance.getCurrentInputMap()[tilePositionColumn][tilePositionRow])
					{
						if (gameInstance.getPlayerTurn())
						{ gameInstance.getCurrentInputMap()[tilePositionColumn][tilePositionRow] = 1; }
						else
						{ gameInstance.getCurrentInputMap()[tilePositionColumn][tilePositionRow] = 2; }

						gameInstance.setPlayerTurn(!gameInstance.getPlayerTurn());
						gameInstance.c_displayCurrentInputMap();
					}
				}
			}
			gameInstance.displayCurrentInputMap(gameWindow);
			gameWindow.display();

			gameInstance.fullVerify();
		}
		gameWindow.clear(sf::Color::Black);

		gameWindow.draw(gameInstance.getGridSprite());
		gameInstance.displayCurrentInputMap(gameWindow);
		gameWindow.draw(gameInstance.getScoreLabel().getLabelText());

		gameWindow.display();
	}
}