#include "pch.h"
#include "CppUnitTest.h"

#include "equation.h"
#include "equationErrorMessages.h"

#include <string>
#include <vector>
#include <math.h>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestsNamespace
{
	double testTolerance = 1e-6;

	string whiteSpaceTestEquation1 = "2+2";
	string whiteSpaceTestEquation2 = "2 + \t\n2";
	double whiteSpaceTestAnswer = 4;

	string negativeTestEquation = "2 / -2";
	double negativeTestAnswer = -1;

	string decimalTestEquation = "2.4 * 2";
	double decimalTestAnswer = 4.8;

	string divByZeroEquation = "5/0";

	// Make sure the order is correct for each possible combination of operators where order matters
	vector<string> orderOperatorEquations = { "2+3-5", "2+3*5", "2+3/5", "2+3^5",
		"2-3+5", "2-3-5", "2-3*5", "2-3/5", "2-3^5",
		"2*3+5", "2*3-5", "2*3/5", "2*3^5",
		"2/3+5", "2/3-5", "2/3*5", "2/3/5", "2/3^5",
		"2^3+5", "2^3-5", "2^3*5", "2^3/5", "2^3^5" };

	vector<double> orderOperatorAnswers = { 0, 17, 2.6, 245,
		4, -6, -13, 1.4, -241,
		11, 1, 1.2, 486,
		5 + 2.0/3.0, 2.0/3.0 - 5, 10.0/3.0, 2.0/15.0, 2.0/243.0, 
		13, 3, 40, 1.6, 32768};

	// Make sure parentheses overrides the normal order
	vector<string> orderParenthesesEquations = {"2*(3+5)", "2^(3+5)", "2^(3*5)", "2-(3-5)", "2/(3/5)"};
	vector<double> orderParenthesesAnswers = {16, 256, 32768, 4, 10.0/3.0};

	// Make sure nested parentheses are handled correctly
	string nestedParenthesesEquation = "(11/(7-((2+3)*5)))^2";
	double nestedParenthesesAnswer = pow(11.0/18.0, 2);

	// Due to the way equation.cpp is structured, these often need to be tested separately for expectingOperator = true and false
	// Also need to test cases with a '-' differently than other operators sometimes because it can be either an operator or the start of a number

	string invalidCharString1 = "5 whee";
	string invalidCharString2 = "5 + whee";

	// Number where an operator is expected
	string numWhereOperString = "5 6";

	// Decimal where an operator is expected
	string decWhereOperString = "5 .";

	// Multiple decimals in one number
	string doubleDecString = "5 + 6.4.3";

	// Right where number expected
	string rightWhereNumString = "(5 + )";
	// Left or Right where digits expected after decimal or negative sign
	string leftWhereDigString1 = "5 + .(3+4)";
	string leftWhereDigString2 = "5 + -(3+4)";
	string rightWhereDigString1 = "(5 + -)";
	string rightWhereDigString2 = "(5 + .)";
	// Left where operator expected
	string leftWhereOperString = "5 (3+4)";
	// Rights > Lefts
	string tooManyRightString = "(5 + 6) * 7)";

	// Operator where a number expected
	string operWhereNumString1 = "5 -*4";
	string operWhereNumString2 = "5 +*3";
	string operWhereDigString1 = "5 +--4";
	string operWhereDigString2 = "5 +-*4";
	string operWhereDigString3 = "5 + .*";

	// White space immediately after a negative sign or lone decimal
	string whiteWhereDigString1 = "5 + - ";
	string whiteWhereDigString2 = "5 + . ";

	// String ends with a number expected
	string endWhereNumString1 = "5 +";
	string endWhereNumString2 = "5 + .";
	string endWhereNumString3 = "5 + -";
	// String ends with unmatched parentheses (too many Lefts)
	string tooManyLeftString = "(5 + 6";

	void EquationTest(string testEquation, double testAnswer)
	{
		equation testEq = equation(testEquation);
		string errorMessage = "Test failed for equation: " + testEquation + "\nIt gave an answer of " + to_string(testEq.Answer());
		wstring errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
		Assert::AreEqual(testAnswer, testEq.Answer(), testTolerance, errorMessageWstring.c_str());
	}

	TEST_CLASS(BasicTestClass)
	{
	public:

		TEST_METHOD(WhiteSpaceTest)
		{
			EquationTest(whiteSpaceTestEquation1, whiteSpaceTestAnswer);
			EquationTest(whiteSpaceTestEquation2, whiteSpaceTestAnswer);
		}

		TEST_METHOD(NegativeTest)
		{
			EquationTest(negativeTestEquation, negativeTestAnswer);
		}
		TEST_METHOD(DecimalTest)
		{
			EquationTest(decimalTestEquation, decimalTestAnswer);
		}

		TEST_METHOD(isValidTest) {
			equation testEq;
			string errorMessage = "isValid is not false upon empty initialization";
			wstring errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
			Assert::IsFalse(testEq.IsValid(), errorMessageWstring.c_str());

			errorMessage = "isValid is not true with valid equation";
			errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
			testEq.NewEquation("2+2");
			Assert::IsTrue(testEq.IsValid(), errorMessageWstring.c_str());

			errorMessage = "isValid is not false with invalid equation";
			errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
			testEq.NewEquation("This is not an equation");
			Assert::IsFalse(testEq.IsValid(), errorMessageWstring.c_str());
		}

		TEST_METHOD(divByZeroTest) {
			equation testEq = equation(divByZeroEquation);
			string errorMessage = "Division by zero doesn't return nan";
			wstring errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
			Assert::IsTrue(isnan(testEq.Answer()));
		}
	};

	TEST_CLASS(OrderOfOperationsTestClass)
	{
	public:

		TEST_METHOD(OrderOperatorTest)
		{
			for (int i = 0; i < orderOperatorEquations.size(); i++)
				EquationTest(orderOperatorEquations[i], orderOperatorAnswers[i]);
		}

		TEST_METHOD(OrderParenthesesTest)
		{
			for (int i = 0; i < orderParenthesesEquations.size(); i++)
				EquationTest(orderParenthesesEquations[i], orderParenthesesAnswers[i]);
		}

		TEST_METHOD(nestedParenthesesTest)
		{
			EquationTest(nestedParenthesesEquation, nestedParenthesesAnswer);
		}
	};

	TEST_CLASS(ParsingTestClass)
	{
	public:

		void InvalidEquationTest(string testEquation, string testErrorMessage)
		{
			equation testEq = equation(testEquation);
			string errorMessage = "Test failed for string: " + testEquation + "\nIt was incorrectly seen as a valid string.";
			wstring errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
			Assert::IsFalse(testEq.IsValid(), errorMessageWstring.c_str());

			errorMessage = "Test failed for string: " + testEquation + "\nIt gave this incorrect error message: " + testEq.GetErrorMessage();
			errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
			Assert::AreEqual(testEq.GetErrorMessage(), testErrorMessage, errorMessageWstring.c_str());
		}

		TEST_METHOD(invalidCharTest)
		{
			InvalidEquationTest(invalidCharString1, invalidCharErrorMessage);
			InvalidEquationTest(invalidCharString2, invalidCharErrorMessage);
		}

		TEST_METHOD(numWhereOperTest)
		{
			InvalidEquationTest(numWhereOperString, numWhereOperErrorMessage);
		}

		TEST_METHOD(badDecTest)
		{
			InvalidEquationTest(decWhereOperString, decWhereOperErrorMessage);
			InvalidEquationTest(doubleDecString, doubleDecErrorMessage);
		}

		TEST_METHOD(badParanthesesTest)
		{
			InvalidEquationTest(rightWhereNumString, rightWhereNumErrorMessage);
			InvalidEquationTest(leftWhereDigString1, leftWhereDigErrorMessage);
			InvalidEquationTest(leftWhereDigString2, leftWhereDigErrorMessage);
			InvalidEquationTest(rightWhereDigString1, rightWhereDigErrorMessage);
			InvalidEquationTest(rightWhereDigString2, rightWhereDigErrorMessage);
			InvalidEquationTest(leftWhereOperString, leftWhereOperErrorMessage);
			InvalidEquationTest(tooManyRightString, tooManyRightErrorMessage);
		}

		TEST_METHOD(badOperTest)
		{
			InvalidEquationTest(operWhereNumString1, operWhereNumErrorMessage);
			InvalidEquationTest(operWhereNumString2, operWhereNumErrorMessage);
			InvalidEquationTest(operWhereDigString1, operWhereDigErrorMessage);
			InvalidEquationTest(operWhereDigString2, operWhereDigErrorMessage);
			InvalidEquationTest(operWhereDigString3, operWhereDigErrorMessage);
		}

		TEST_METHOD(badWhiteTest)
		{
			InvalidEquationTest(whiteWhereDigString1, whiteWhereDigErrorMessage);
			InvalidEquationTest(whiteWhereDigString2, whiteWhereDigErrorMessage);
		}

		TEST_METHOD(badStringEndTest)
		{
			InvalidEquationTest(endWhereNumString1, endWhereNumErrorMessage);
			InvalidEquationTest(endWhereNumString2, endWhereNumErrorMessage);
			InvalidEquationTest(endWhereNumString3, endWhereNumErrorMessage);
			InvalidEquationTest(tooManyLeftString, tooManyLeftErrorMessage);
		}
	};
}