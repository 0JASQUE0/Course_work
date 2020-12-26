#pragma once

#include <string>
#include "LinkedList.h"

using namespace std;

class PolishNotation {
private:
	LinkedList stack;
	string space = " ";

public:
	string infixString;
	string prefixString;
	PolishNotation();
	~PolishNotation();
	void input();
	void infixToPrefix();
	int getPriority(string c);
	void printToConsole();
	double calculation();
};