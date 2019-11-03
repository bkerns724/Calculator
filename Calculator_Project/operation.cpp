#include "operation.h"

operation::operation()
{
	symbol = 'E';
	priority = 0;
}

operation::operation(char inputSymbol, int inputPriority)
{
	symbol = inputSymbol;
	priority = inputPriority;
}