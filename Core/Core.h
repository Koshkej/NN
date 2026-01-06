#pragma once

#include <iostream>
#include <string>
#include <random>
#include <cmath>

#define EULER 2.7182818284

extern sf::RenderWindow generalWindow;

std::mt19937& getGenerator();
void sigmoid(double& ele);
void sigmoidDerivative(double& ele);
