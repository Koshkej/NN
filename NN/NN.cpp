#include "NN.h"

NN::SimplePerceptron::SimplePerceptron(size_t inputLayerNumber, size_t hiddenLayerNumber, size_t outputLayerNumber, double learningRate)
	: inputLayerNumber(inputLayerNumber)
	, hiddenLayerNumber(hiddenLayerNumber)
	, outputLayerNumber(outputLayerNumber)
	, learningRate(learningRate)
	, weightsHidden_Input(hiddenLayerNumber, inputLayerNumber)
	, weightsOutput_Hidden(outputLayerNumber, hiddenLayerNumber)
{}

std::vector<double> NN::SimplePerceptron::query(const std::vector<double>& input) {

#ifdef DEBUG
	if (input.size() != inputLayerNumber) throw std::invalid_argument("Wrong input size");
#endif

	Matrix hidden = weightsHidden_Input  * input;
	hidden.todoeach(&sigmoid);

	Matrix output = weightsOutput_Hidden * hidden;
	output.todoeach(&sigmoid);

	return output.getbody();

}

void NN::SimplePerceptron::train(const std::vector<double>& input, const std::vector<double>& target) {

#ifdef DEBUG
	if (input.size()  != inputLayerNumber)  throw std::invalid_argument("Wrong input size");
	if (target.size() != outputLayerNumber) throw std::invalid_argument("Wrong target size");
#endif

	Matrix hidden = weightsHidden_Input * input;
	hidden.todoeach(&sigmoid);

	Matrix output = weightsOutput_Hidden * hidden;
	output.todoeach(&sigmoid);

	Matrix outputErrors = target - output;
	Matrix hiddenErrors = weightsOutput_Hidden.transposed() * outputErrors;

	/* - - - - - - */

	Matrix outputDerivative = output.todoeach(&sigmoidDerivative, true);
	Matrix outputGradient = outputErrors.elementWiseMultiply(outputDerivative);

	Matrix D_weightsOutput_Hidden = outputGradient * hidden.transposed();

	weightsOutput_Hidden += D_weightsOutput_Hidden * learningRate;

	/* - - - - - - */

	Matrix hiddenDerivative = hidden.todoeach(&sigmoidDerivative, true);
	Matrix hiddenGradient = hiddenErrors.elementWiseMultiply(hiddenDerivative);

	Matrix D_weightsHidden_Input = hiddenGradient * Matrix(input).transposed();

	weightsHidden_Input += D_weightsHidden_Input * learningRate;

}
