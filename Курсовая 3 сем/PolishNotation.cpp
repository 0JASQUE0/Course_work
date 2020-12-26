#include "PolishNotation.h"
#include <iostream>
#include <cmath>

const double PI = 3.1415926535;
const double E = 2.7182818284;

PolishNotation::PolishNotation()
{
}

PolishNotation::~PolishNotation()
{
}

void PolishNotation::input()
{
	getline(cin, infixString);
}

void PolishNotation::infixToPrefix()
{
	string temp;
	for (int i = infixString.length() - 1; i >= 0; i--) {
		if (infixString[i] == '0' || infixString[i] == '1' || infixString[i] == '2' || infixString[i] == '3' || infixString[i] == '4' || infixString[i] == '5' || infixString[i] == '6' || infixString[i] == '7' || infixString[i] == '8'
			|| infixString[i] == '9' || infixString[i] == '.') {
			prefixString = infixString[i] + prefixString;
		}

		else if (infixString[i] == '+' || infixString[i] == '-' || infixString[i] == '*' || infixString[i] == '/' || infixString[i] == '^') {
			temp = infixString[i];
			while (getPriority(temp) <= getPriority(stack.getTop())) {
				prefixString = stack.pop_back() + space + prefixString;
			}
			stack.push_back(temp);
			prefixString = space + prefixString;
		}

		else if (infixString[i] == 'n') {
			if (infixString[i - 1] == 'i' && infixString[i - 2] == 's') {
				temp = infixString[i];
				while (getPriority(temp) <= getPriority(stack.getTop())) {
					prefixString = stack.pop_back() + space + prefixString;
				}
				stack.push_back("sin");
				prefixString = space + prefixString;
				i -= 2;
			}
			else if (infixString[i - 1] == 'l') {
				temp = infixString[i];
				while (getPriority(temp) <= getPriority(stack.getTop())) {
					prefixString = stack.pop_back() + space + prefixString;
				}
				stack.push_back("ln");
				prefixString = space + prefixString;
				i--;
			}
		}

		else if (infixString[i] == 's') {
			if (infixString[i - 1] == 'o' && infixString[i - 2] == 'c') {
				temp = infixString[i];
				while (getPriority(temp) <= getPriority(stack.getTop())) {
					prefixString = stack.pop_back() + space + prefixString;
				}
				stack.push_back("cos");
				prefixString = space + prefixString;
				i -= 2;
			}
		}

		else if (infixString[i] == 'g') {
			if (infixString[i - 1] == 'o' && infixString[i - 2] == 'l') {
				temp = infixString[i];
				while (getPriority(temp) <= getPriority(stack.getTop())) {
					prefixString = stack.pop_back() + space + prefixString;
				}
				stack.push_back("log");
				prefixString = space + prefixString;
				i -= 2;
			}
			else if (i > 1 && infixString[i - 1] == 't' && infixString[i - 2] == 'c') {
				temp = infixString[i];
				while (getPriority(temp) <= getPriority(stack.getTop())) {
					prefixString = stack.pop_back() + space + prefixString;
				}
				stack.push_back("ctg");
				prefixString = space + prefixString;
				i -= 2;
			}
			else if (infixString[i - 1] == 't') {
				temp = infixString[i];
				while (getPriority(temp) <= getPriority(stack.getTop())) {
					prefixString = stack.pop_back() + space + prefixString;
				}
				stack.push_back("tg");
				prefixString = space + prefixString;
				i--;
			}
		}

		else if (infixString[i] == 't') {
			if (infixString[i - 1] == 'r' && infixString[i - 2] == 'q' && infixString[i - 3] == 's') {
				temp = infixString[i];
				while (getPriority(temp) <= getPriority(stack.getTop())) {
					prefixString = stack.pop_back() + space + prefixString;
				}
				stack.push_back("sqrt");
				prefixString = space + prefixString;
				i -= 3;
			}
		}

		else if (infixString[i] == 'h') {
			if (infixString[i - 1] == 's') {
				temp = infixString[i];
				while (getPriority(temp) <= getPriority(stack.getTop())) {
					prefixString = stack.pop_back() + space + prefixString;
				}
				stack.push_back("sh");
				prefixString = space + prefixString;
				i--;
			}
		}

		else if (infixString[i] == 'e') {
			prefixString = infixString[i] + prefixString;
		}

		else if (infixString[i] == 'i') {
			if (infixString[i - 1] == 'p') {
				prefixString = "pi" + prefixString;
			}
			i--;
		}

		else if (infixString[i] == ')') {
			temp = infixString[i];
			stack.push_back(temp);
		}

		else if (infixString[i] == '(') {
			temp = stack.pop_back();
			while (temp != ")") {
				prefixString = temp + space + prefixString;
				temp = stack.pop_back();
			}
		}
		else {
			cout << "Incorrect input in " << i + 1 << " position";
			return;
		}
	}

	while (!stack.isEmpty()) {
		prefixString = stack.pop_back() + space + prefixString;
	}
}

int PolishNotation::getPriority(string c)
{
	if (c == "cos" || c == "sin" || c == "tg" || c == "ctg" || c == "log" || c == "ln" || c == "sqrt" || c == "sh") return 4;
	if (c == "n" || c == "s" || c == "g" || c == "t" || c == "h") return 4;
	if (c == "^") return 3;
	if (c == "*" || c == "/") return 2;
	if (c == "+" || c == "-") return 1;
	if (c == "(" || c == ")") return 0;
	return -1;
}

void PolishNotation::printToConsole()
{
	cout << prefixString;
}

double PolishNotation::calculation()
{
	string temp;
	double operand1;
	double operand2;
	for (int i = prefixString.length() - 1; i >= 0; i--)
	{
		if (prefixString[i] == '0' || prefixString[i] == '1' || prefixString[i] == '2' || prefixString[i] == '3' || prefixString[i] == '4' || prefixString[i] == '5' || prefixString[i] == '6' || prefixString[i] == '7' || prefixString[i] == '8'
			|| prefixString[i] == '9' || prefixString[i] == '.') {
			string number;
			while (prefixString[i] == '0' || prefixString[i] == '1' || prefixString[i] == '2' || prefixString[i] == '3' || prefixString[i] == '4' || prefixString[i] == '5' || prefixString[i] == '6' || prefixString[i] == '7' || prefixString[i] == '8'
				|| prefixString[i] == '9' || prefixString[i] == '.') {
				number = prefixString[i] + number;
				i--;
			}
			i++;
			stack.push_back(number);
		}

		if (prefixString[i] == '+') {
			operand1 = atof(stack.pop_back().c_str());
			operand2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(operand1 + operand2));
		}

		if (prefixString[i] == '-') {
			operand1 = atof(stack.pop_back().c_str());
			operand2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(operand1 - operand2));
		}

		if (prefixString[i] == '*') {
			operand1 = atof(stack.pop_back().c_str());
			operand2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(operand1 * operand2));
		}

		if (prefixString[i] == '/') {
			operand1 = atof(stack.pop_back().c_str());
			operand2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(operand1 / operand2));
		}

		if (prefixString[i] == '^') {
			operand1 = atof(stack.pop_back().c_str());
			operand2 = atof(stack.pop_back().c_str());
			stack.push_back(to_string(pow(operand1, operand2)));
		}

		if (prefixString[i] == 's') {
			if (prefixString[i - 1] == 'o' && prefixString[i - 2] == 'c') {
				operand1 = atof(stack.pop_back().c_str());
				stack.push_back(to_string(cos(operand1)));
				i -= 2;
			}
		}

		if (prefixString[i] == 'n' && i > 1) {
			if (prefixString[i - 1] == 'i' && prefixString[i - 2] == 's') {
				operand1 = atof(stack.pop_back().c_str());
				stack.push_back(to_string(sin(operand1)));
				i -= 2;
			}
		}

		if (prefixString[i] == 'n' && i > 0) {
			if (prefixString[i - 1] == 'l') {
				operand1 = atof(stack.pop_back().c_str());
				stack.push_back(to_string(log(operand1)));
				i--;
			}
		}

		if (prefixString[i] == 'g' && i > 1) {
			if (prefixString[i - 1] == 'o' && prefixString[i - 2] == 'l') {
				operand1 = atof(stack.pop_back().c_str());
				stack.push_back(to_string(log10(operand1)));
				i -= 2;
			}
		}

		if (prefixString[i] == 'g' && i > 0) {
			if (prefixString[i - 1] == 't') {
				operand1 = atof(stack.pop_back().c_str());
				stack.push_back(to_string(tan(operand1)));
				i--;
			}
		}

		if (prefixString[i] == 'g' && i > 1) {
			if (prefixString[i - 1] == 't' && prefixString[i - 2] == 'c') {
				operand1 = atof(stack.pop_back().c_str());
				stack.push_back(to_string(1 / tan(operand1)));
				i -= 2;
			}
		}

		if (prefixString[i] == 't' && i > 2) {
			if (prefixString[i - 1] == 'r' && prefixString[i - 2] == 'q' && prefixString[i - 3] == 's') {
				operand1 = atof(stack.pop_back().c_str());
				stack.push_back(to_string(sqrt(operand1)));
				i -= 3;
			}
		}

		if (prefixString[i] == 'h' && i > 0) {
			if (prefixString[i - 1] == 's') {
				operand1 = atof(stack.pop_back().c_str());
				stack.push_back(to_string((pow(E, operand1) - pow(E, -operand1)) / 2));
				i--;
			}
		}

		if (prefixString[i] == 'i' && i > 0) {
			if (prefixString[i - 1] == 'p') {
				temp = to_string(PI);
				stack.push_back(temp);
				i--;
			}
		}

		if (prefixString[i] == 'e') {
			temp = to_string(E);
			stack.push_back(temp);
		}
	}

	double result = atof(stack.pop_back().c_str());

	cout << endl << result;
	return result;
}