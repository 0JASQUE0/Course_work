#include "pch.h"
#include "CppUnitTest.h"
#include "..\Курсовая 3 сем\PolishNotation.cpp"
#include "..\Курсовая 3 сем\LinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod0)
		{
			PolishNotation pl;
			pl.infixString = "2+2";
			pl.infixToPrefix();
			Assert::IsTrue(pl.prefixString == "+ 2 2");

		}

		TEST_METHOD(TestMethod01)
		{
			PolishNotation pl;
			pl.infixString = "2+2^2";
			pl.infixToPrefix();
			Assert::IsTrue(pl.prefixString == "+ 2 ^ 2 2");
		}

		TEST_METHOD(TestMethod02)
		{
			PolishNotation pl;
			pl.infixString = "sin(pi)";
			pl.infixToPrefix();
			Assert::IsTrue(pl.prefixString == "sin  pi");
		}

		TEST_METHOD(TestMethod03)
		{
			PolishNotation pl;
			pl.infixString = "2*2^3";
			pl.infixToPrefix();
			Assert::IsTrue(pl.prefixString == "* 2 ^ 2 3");
		}

		TEST_METHOD(TestMethod1)
		{
			PolishNotation pl;
			pl.infixString = "(3+3*2-2^3)/0.1";
			pl.infixToPrefix();
			double result = pl.calculation();
			Assert::IsTrue(result == 10);
		}

		TEST_METHOD(TestMethod2)
		{
			PolishNotation pl;
			pl.infixString = "cos(pi)";
			pl.infixToPrefix();
			double result = pl.calculation();
			Assert::IsTrue(result == -1);
		}

		TEST_METHOD(TestMethod3)
		{
			PolishNotation pl;
			pl.infixString = "sin(pi/2)";
			pl.infixToPrefix();
			double result = pl.calculation();
			Assert::IsTrue(result == 1);
		}

		TEST_METHOD(TestMethod4)
		{
			PolishNotation pl;
			pl.infixString = "ln(e^3)";
			pl.infixToPrefix();
			double result = pl.calculation();
			Assert::IsTrue(result == 3);
		}

		TEST_METHOD(TestMethod5)
		{
			PolishNotation pl;
			pl.infixString = "log(10000)";
			pl.infixToPrefix();
			double result = pl.calculation();
			Assert::IsTrue(result == 4);
		}

		TEST_METHOD(TestMethod6)
		{
			PolishNotation pl;
			pl.infixString = "sqrt(576)";
			pl.infixToPrefix();
			double result = pl.calculation();
			Assert::IsTrue(result == 24);
		}

		TEST_METHOD(TestMethod7)
		{
			PolishNotation pl;
			pl.infixString = "sh(0)";
			pl.infixToPrefix();
			double result = pl.calculation();
			Assert::IsTrue(result == 0);
		}

		TEST_METHOD(TestMethod8)
		{
			PolishNotation pl;
			pl.infixString = "tg(pi)";
			pl.infixToPrefix();
			double result = pl.calculation();
			Assert::IsTrue(result == 0);
		}

		TEST_METHOD(TestMethod9)
		{
			PolishNotation pl;
			pl.infixString = "(((log(10)+ln(e)+cos(0)+sin(pi)-6)*3)+3^3)/0.5";
			pl.infixToPrefix();
			double result = pl.calculation();
			Assert::IsTrue(result == 36);
		}
	};
}
