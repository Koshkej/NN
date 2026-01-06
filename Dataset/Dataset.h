#pragma once

#include "../Core/Core.h"

#include <vector>
#include <fstream>

class Dataset 
{
public:
	size_t input_size, output_size;
	Dataset(std::string path, size_t input_size, size_t output_size);
private:
	std::vector<double> body;
};
