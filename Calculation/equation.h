#pragma once

#include <string>
#include <vector>
#include "operation.h"
#include "equationErrorMessages.h"

class equation final
{
public:
	equation();
	equation(std::string);
	~equation();

	bool NewEquation(std::string);
	double Answer();
	bool IsValid() { return isValid; }
	std::string ToString() { return stringRepresentation; }
	std::string GetErrorMessage() { return errorMessage; }

private:
	bool ParseString();
	double CalculateAnswer();
	
	std::vector<operation> operations;
	std::vector<double> numbers;
	std::string stringRepresentation;
	std::string errorMessage;
	
	double answer;
	bool isValid;
};