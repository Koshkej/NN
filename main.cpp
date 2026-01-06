#include "Core/Core.h"
#include "Matrix/Matrix.h"
#include "NN/NN.h"
#include "Dataset/Dataset.h"

NN::SimplePerceptron numberDeterminingPerceptron(784, 100, 10, 0.3);

int main()
{

	generalWindow.create(sf::VideoMode(VIDEOMODE), TITLE, sf::Style::Close);

	while (generalWindow.isOpen())
	{

		generalWindow.clear(sf::Color::Black);

		while (const std::optional event = generalWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>()) 
			{
				generalWindow.close();
			}
			if (event->is<sf::Event::KeyPressed>())
			{
				if (event->is<sf::Event::KeyPressed>() && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				{
					generalWindow.close();
				}
				if (event->is<sf::Event::KeyPressed>() && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) 
				{

				}
				if (event->is<sf::Event::KeyPressed>() && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) 
				{

				}
			}
		}

		generalWindow.display();

	}

	return 0;
}
