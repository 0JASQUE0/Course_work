#include <iostream>
#include <string>
#include <cmath>
#include "PolishNotation.h"

using namespace std;

int main()
{
	//setprecision(5);

	PolishNotation pl;

	pl.input();
	pl.infixToPrefix();
	pl.printToConsole();
	pl.calculation();
	
	//cout << acos(-1.0);
	//double x = 1.25;
	//string s1 = "asd";
	//s1 += to_string(x);
	//cout << s1;

	//string s = "124.12";
	//double b = atof(s.c_str());
	//cout << b + 1;


	//cout << log10(9) / log10(3) << endl;

	//double x = 0;

	//for (int i = 3; i > -5; i--) {
	//	x += 1 * pow(10, i);
	//}
	//cout.setf(ios::fixed);
	//cout << setw(5) << x;

	//string s1;
	//string s2;
	//char c = '1', b = '2';
	//cout << int(c) + int(b);

	//getline(cin, s1);

	//cout << s1 << endl;

	//for (int i = 0; i < s1.length(); i++) {
	//	c = s1[i];
	//	if (c == 't') {

	//	}
	//}

	return 0;
}