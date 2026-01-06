#include "Core.h"

sf::RenderWindow generalWindow;

std::mt19937& getGenerator() {
	static std::mt19937 generator{ std::random_device{}() };
	return generator;
}

void sigmoid(double& ele) {
	ele = 1.0 / (1.0 + std::exp(-ele));
}

void sigmoidDerivative(double& ele) {
	ele = ele * (1.0 - ele);
}
