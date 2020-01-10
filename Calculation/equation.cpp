#include "pch.h"
#include "framework.h"

#include "Equation.h"
#include <limits>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <math.h>

using namespace std;

equation::equation()
{
	isValid = false;
	answer = 0;
	errorMessage = "No equation";
}

equation::equation(string equationString)
{
	NewEquation(equationString);
}

equation::~equation()
{
}

double equation::Answer()
{
	if (true == IsValid())
	    return answer;
	else
		return numeric_limits<double>::quiet_NaN();
}

bool equation::NewEquation(string equationString)
{
	stringRepresentation = equationString;
	isValid = false;
	operations.resize(0);
	numbers.resize(0);

	bool parseSuccess = ParseString();
	if (parseSuccess)
	{
		answer = CalculateAnswer();
		if (answer == -0.0)
			answer = 0.0;
	}

	return isValid;
}

// This function makes sure the equation is of the form number operator number operator number etc.
// '(' are expected to be on the left side of numbers, ')' are expected to be on the right side of numbers.
// Mismatched parentheses are checked for.
// Negative and decimal numbers are allowed and the program checks to make sure these characters only occur in valid ways.
// Negative sign only at the beginning of the number, and max one decimal point.
// The only white space expectation is that it does not occur partway through a number.
// As ParseString makes these checks it pushes numbers into the numbers vector and operators into the operations vector.
// It also attaches a priority to each operation, based on how deeply nested it is in the parentheses and the order of operations.

bool equation::ParseString()
{
	int parenthesesCount = 0;			// Counts left parentheses - right parentheses

	bool expectingOperator = false;
	bool acceptingDecimal = true;
	bool hasNumeric = false;
	bool numberStarted = false;

	string numberString = "";

	for (int i = 0; i < stringRepresentation.length(); i++)
	{
		char currentChar = stringRepresentation[i];
		if (!expectingOperator)
		{
			int priority;
			operation tempOperation;
			switch (currentChar)
			{
			case '(':
				if (!numberStarted)
				{
					parenthesesCount++;
					continue;
				}
				else
				{
					errorMessage = "Left parenthesis in unexpected location, not a valid equation.";
					return false;
				}
			case ' ':
			case '\n':
			case '\t':
				if (numberStarted)
				{
					expectingOperator = true;
					if (hasNumeric)
					{
						double number = atof(numberString.c_str());
						numbers.push_back(number);
						numberString.clear();
						numberStarted = false;
						acceptingDecimal = true;
						hasNumeric = false;
					}
					else
					{
						errorMessage = "White space where valid number expected, not a valid equation.";
						return false;
					}
				}
				continue;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				numberString += currentChar;
				numberStarted = true;
				hasNumeric = true;

				if (stringRepresentation.length() - 1 == i)
				{
					double number = atof(numberString.c_str());
					numbers.push_back(number);
					numberString.clear();
					numberStarted = false;
					acceptingDecimal = true;
					hasNumeric = false;
				}

				continue;
			case '.':
				if (acceptingDecimal)
				{
					numberString += currentChar;
					numberStarted = true;
					acceptingDecimal = false;
				}
				else
				{
					errorMessage = doubleDecErrorMessage;
					return false;
				}

				if (hasNumeric && stringRepresentation.length() - 1 == i)
				{
					double number = atof(numberString.c_str());
					numbers.push_back(number);
					numberString.clear();
					numberStarted = false;
					acceptingDecimal = true;
					hasNumeric = false;
				}
				else if (stringRepresentation.length() - 1 == i)
				{
					errorMessage = "End of equation where valid number expected, not a valid equation.";
					return false;
				}

				continue;
			case ')':
				if (numberStarted)
				{
					parenthesesCount--;
					if (parenthesesCount < 0)
					{
						errorMessage = "Right parenthesis without matching left parenthesis, not a valid equation.";
						return false;
					}
					if (hasNumeric)
					{
						double number = atof(numberString.c_str());
						numbers.push_back(number);
						numberString.clear();
						numberStarted = false;
						acceptingDecimal = true;
						hasNumeric = false;
						expectingOperator = true;
					}
					else
					{
						errorMessage = "Right parenthesis where valid number expected, not a valid equation.";
						return false;
					}
				}
				else
				{
					errorMessage = "Right parenthesis in unexpected location, not a valid equation.";
					return false;
				}
				continue;
			case '-':		// - can be part of a negative number, or it can be an operator
				if (!numberStarted)
				{
					numberString += currentChar;
					numberStarted = true;

					if (stringRepresentation.length() - 1 == i)
					{
						errorMessage = "End of equation where valid number expected, not a valid equation.";
						return false;
					}

					continue;
				}
			case '+':
			case '/':
			case '*':
			case '^':
				if (!numberStarted)
				{
					errorMessage = "Arithmetic operator in unexpected location, not a valid equation.";
					return false;
				}
				if (hasNumeric)
				{
					double number = atof(numberString.c_str());
					numbers.push_back(number);
					numberString.clear();
					numberStarted = false;
					acceptingDecimal = true;
					hasNumeric = false;
				}
				else
				{
					errorMessage = "Operator where valid number expected, not a valid equation.";
					return false;
				}
				priority = 3 * parenthesesCount;
				if ('*' == currentChar || '/' == currentChar)
					priority++;
				if ('^' == currentChar)
					priority += 2;
				tempOperation = operation(currentChar, priority);
				operations.push_back(tempOperation);
				continue;
			default:
				errorMessage = invalidCharErrorMessage;
				return false;
			}
		}
		else	// if expectingOperator
		{
			int priority;
			operation tempOperation;
			switch (currentChar)
			{
			case '(':
				errorMessage = "Left parenthesis in unexpected location, not a valid equation.";
				return false;
			case ' ':
			case '\n':
			case '\t':
				continue;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				errorMessage = numWhereOperErrorMessage;
				return false;
			case '.':
				errorMessage = decWhereOperErrorMessage;
				return false;
			case ')':
				parenthesesCount--;
				if (parenthesesCount < 0)
				{
					errorMessage = "Right parenthesis without matching left parenthesis, not a valid equation";
					return false;
				}
				continue;
			case '-':
			case '+':
			case '/':
			case '*':
			case '^':
				expectingOperator = false;
				priority = 3 * parenthesesCount;
				if ('*' == currentChar || '/' == currentChar)
					priority++;
				if ('^' == currentChar)
					priority+= 2;
				tempOperation = operation(currentChar, priority);
				operations.push_back(tempOperation);

				numberStarted = false;
				expectingOperator = false;
				acceptingDecimal = true;
				continue;
			default:
				errorMessage = invalidCharErrorMessage;
				return false;
			}
		}
	}

	if (parenthesesCount > 0)
	{
		errorMessage = "More left parentheses than right parentheses, not a valid equation.";
		return false;
	}

	if (operations.size() + 1 != numbers.size() && operations.size() > 0)
	{
		errorMessage = "Operator at end of equation without a number to operate on, not a valid equation.";
		return false;
	}

	if (0 == numbers.size())
		return false;

	operation tempOperation = operation('E', -2);	// This will be lower priority than everything, and the symbol will not be used
													// Adding this just simplifies the CalculateAnswer algorithm a bit
													// To avoid checks for running out of operators
	operations.push_back(tempOperation);

	return true;
}

// The expected structure of the equation tells us that if we alternate between pushing numbers onto a stack
// and pushing operators onto a different stack
// that operator[i] has number[i] as its left operand and number[i+1] as its right operand
// An operation can be performed by popping two numbers and the operator, then pushing the result, 
// leaving the above relation correct.
// If the priority of an operation is greater than the priority of the operation on the left and 
// at least equal to the priority of the operation on the right, it is safe to do the operation.
// If we perform the operation that is at the top of the stack when the upcoming operation is lower or equal priority, 
// this guarantees that the stack is sorted in ascending order of priority, so such an algorithm ensures that we are always doing safe operations.
// Treating the end of the equation as the lowest priority operator will empty the stack when we reach the end of the equation.

double equation::CalculateAnswer()
{
	vector<double> auxillaryNumbers;
	vector<operation> auxillaryOperations;

	bool divisionByZero = false;

	vector<operation>::iterator iterOp = operations.begin();

	for (vector<double>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		auxillaryNumbers.push_back(*iter);
		
		if (auxillaryOperations.size() > 0)
		{
			while (iterOp->priority <= auxillaryOperations.back().priority)
			{
				char symbol = auxillaryOperations.back().symbol;
				auxillaryOperations.pop_back();
				double tempDouble = auxillaryNumbers.back();
				auxillaryNumbers.pop_back();
				switch (symbol)
				{
				case '+':
					tempDouble = auxillaryNumbers.back() + tempDouble;
					break;
				case '-':
					tempDouble = auxillaryNumbers.back() - tempDouble;
					break;
				case '*':
					tempDouble = auxillaryNumbers.back() * tempDouble;
					break;
				case '/':
					if (0 == tempDouble)		// No division by zero
					{
						errorMessage = "Division by zero.";
						return numeric_limits<double>::quiet_NaN();;
					}
					else
						tempDouble = auxillaryNumbers.back() / tempDouble;
					break;
				case '^':
					tempDouble = pow(auxillaryNumbers.back(), tempDouble);
					break;
				}
				auxillaryNumbers.pop_back();
				auxillaryNumbers.push_back(tempDouble);

				if (auxillaryOperations.empty())
					break;
			}
		}

		auxillaryOperations.push_back(*iterOp);
		iterOp++;
	}

	isValid = true;

	return auxillaryNumbers.back();
}