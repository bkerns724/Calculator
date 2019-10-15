#pragma once

struct operation
{
public:
	operation();
	operation(char, int);

	char symbol;
	int priority;
};
