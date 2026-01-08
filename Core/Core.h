#pragma once

#include <iostream>
#include <string>
#include <random>
#include <cmath>

#define DEBUG // !

#define VERSION "0.1"
#define VIDEOMODE {1000, 500}
#define TITLE "NN Workspace"
#define EULER 2.7182818284

extern sf::RenderWindow generalWindow;

std::mt19937& getGenerator();
void sigmoid(double& ele);
void sigmoidDerivative(double& ele);
