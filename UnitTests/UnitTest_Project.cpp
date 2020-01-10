#include "pch.h"
#include "CppUnitTest.h"

#include "equation.h"
#include <string>
#include <vector>
#include <math.h>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestsNamespace
{
	const double testTolerance = 1e-6;

	const string basicTestEquation = "2+2";
	const double basicTestAnswer = 4;

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

	string divByZeroEquation = "5/0";

	TEST_CLASS(UnitTestsClass)
	{
	public:

		TEST_METHOD(BasicTest)
		{
			equation testEq = equation(basicTestEquation);
			string errorMessage = "Test failed for equation: " + basicTestEquation + "\nIt gave an answer of " + to_string(testEq.Answer());
			wstring errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
			Assert::AreEqual(basicTestAnswer, testEq.Answer(), testTolerance, errorMessageWstring.c_str());
		}

		TEST_METHOD(OrderOperatorTest)
		{
			equation testEq;
			string errorMessage;
			for (int i = 0; i < orderOperatorEquations.size(); i++) {
				testEq.NewEquation(orderOperatorEquations[i]);
				errorMessage = "Test failed for equation: " + orderOperatorEquations[i] + "\nIt gave an answer of " + to_string(testEq.Answer());
				wstring errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
				Assert::AreEqual(orderOperatorAnswers[i], testEq.Answer(), testTolerance, errorMessageWstring.c_str());
			}
		}

		TEST_METHOD(OrderParenthesesTest)
		{
			equation testEq;
			string errorMessage;
			for (int i = 0; i < orderParenthesesEquations.size(); i++) {
				testEq.NewEquation(orderParenthesesEquations[i]);
				errorMessage = "Test failed for equation: " + orderParenthesesEquations[i] + "\nIt gave an answer of " + to_string(testEq.Answer());
				wstring errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
				Assert::AreEqual(orderParenthesesAnswers[i], testEq.Answer(), testTolerance, errorMessageWstring.c_str());
			}
		}

		TEST_METHOD(nestedParenthesesTest)
		{
			equation testEq = equation(nestedParenthesesEquation);
			string errorMessage = "Test failed for equation: " + nestedParenthesesEquation + "\nIt gave an answer of " + to_string(testEq.Answer());
			wstring errorMessageWstring = wstring(errorMessage.begin(), errorMessage.end());
			Assert::AreEqual(nestedParenthesesAnswer, testEq.Answer(), testTolerance, errorMessageWstring.c_str());
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
			Assert::IsTrue(isnan(testEq.Answer()));
		}
	};
}