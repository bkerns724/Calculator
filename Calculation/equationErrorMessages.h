#pragma once

#include <string>

// Make \'\(' or left parentheses consistent?

const std::string noEquationErrorMessage = "No equation.";

const std::string invalidCharErrorMessage = "Invalid equation, unexpected character in input string.";

const std::string numWhereOperErrorMessage = "Invalid equation, there is a number where a \')\' or operator is expected.";

const std::string decWhereOperErrorMessage = "Invalid equation, there is a decimal point where a \')\' or operator is expected.";
const std::string doubleDecErrorMessage = "Invalid equation, there are two decimal points in a single number.";

const std::string rightWhereNumErrorMessage = "Invalid equation, there is a \')\' where a \'(\' or number is expected.";
const std::string rightWhereDigErrorMessage = "Invalid equation, there is a \')\' where there should be digits after a negative sign or decimal point.";
const std::string leftWhereDigErrorMessage = "Invalid equation, there is a \'(\' where digits are expected after a decimal point or negative sign.";
const std::string leftWhereOperErrorMessage = "Invalid equation, there is a \'(\' where a \')\' or operator is expected.";
const std::string tooManyRightErrorMessage = "Invalid equation, unmatched right parentheses.";

const std::string operWhereNumErrorMessage = "Invalid equation, there is an operator where a number is expected.";
const std::string operWhereDigErrorMessage = "Invalid equation, there is an operator where digits should be after a negative sign or decimal point.";

const std::string whiteWhereDigErrorMessage = "Invalid equation, white space where there should be digits after a negative sign or decimal point.";

const std::string endWhereNumErrorMessage = "Invalid equation, another number expected at the end of the equation.";
const std::string tooManyLeftErrorMessage = "Invalid equation, unmatched left parentheses.";