#pragma once

#include <vector>
#include "../Matrix/Matrix.h"
#include "../Core/Core.h"

namespace NN {

	class SimplePerceptron {
	public:
		SimplePerceptron(size_t inputLayerNumber, size_t hiddenLayerNumber, size_t outputLayerNumber, double learningRate);
		std::vector<double> query(const std::vector<double>& input);
		void train(const std::vector<double>& input, const std::vector<double>& target);
	private:
		Matrix weightsHidden_Input, weightsOutput_Hidden;
		size_t inputLayerNumber, hiddenLayerNumber, outputLayerNumber;
		double learningRate;
	};

}
