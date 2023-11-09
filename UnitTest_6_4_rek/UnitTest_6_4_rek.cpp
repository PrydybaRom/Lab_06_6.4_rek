#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06.4_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rek
{
	TEST_CLASS(UnitTest64rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a = 1;
			double b = 1;

			const int SIZE = 1;

			vector <double> arr(SIZE);
			fillArrayWithRandomNumbers(arr, SIZE, a, b);
			double result = sumElements(arr, SIZE);

			Assert::AreEqual(result, 1.00);
		}
	};
}
