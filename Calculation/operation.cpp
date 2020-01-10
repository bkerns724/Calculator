#include "pch.h"
#include "framework.h"

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