#pragma once

#include <string>

const std::string invalidCharErrorMessage = "Invalid equation, unexpected character in input string.";
const std::string numWhereOperErrorMessage = "Invalid equation, there is a number where a ) or operator is expected.";
const std::string decWhereOperErrorMessage = "Invalid equation, there is a decimal point where a ) or operator is expected.";
const std::string doubleDecErrorMessage = "Invalid equation, there are two decimal points in a single number.";