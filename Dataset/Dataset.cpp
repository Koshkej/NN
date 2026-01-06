#include "Dataset.h"

Dataset::Dataset(std::string path, size_t input_size, size_t output_size) : input_size(input_size), output_size(output_size) {
	std::ifstream file(path);
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream sline(line);
		std::string token;
		while (std::getline(sline, token, ',')) 
			body.push_back(std::stod(token));
	}
	file.close();
}
