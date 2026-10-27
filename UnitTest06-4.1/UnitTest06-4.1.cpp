#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_06_4.1/lab06-4.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest0641
{
	TEST_CLASS(UnitTest0641)
	{
	public:
		
		TEST_METHOD(TestCountPositive)
		{
			const int n = 5;
			double a[n] = { 2.0, -3.0, 4.0, -1.0, 5.0 };
			int actual = CountPositive(a, n, 0);
			Assert::AreEqual(3, actual); 
		}

		TEST_METHOD(TestProductPositive)
		{
			const int n = 5;
			double a[n] = { 2.0, -3.0, 4.0, -1.0, 5.0 };
			double actual = ProductPositive(a, n, 0);
			Assert::AreEqual(40.0, actual, 0.0001);
		}

		TEST_METHOD(TestIndexMin)
		{
			const int n = 5;
			double a[n] = { 2.0, -3.0, 4.0, -1.0, 5.0 };
			int actual = IndexMin(a, n, 1, 0);
			Assert::AreEqual(1, actual); 
		}

		TEST_METHOD(TestSumBefore)
		{
			const int n = 5;
			double a[n] = { 2.0, -3.0, 4.0, -1.0, 5.0 };
			int imin = 1;
			double actual = SumBefore(a, imin, 0);
			Assert::AreEqual(2.0, actual, 0.0001); 
		}

		TEST_METHOD(TestSortStep)
		{
			const int n = 4;
			double a[n] = { 5.0, -1.0, 2.0, -3.0 };

			SortStep(a, n, 0); 
			SortStep(a, n, 1); 

			Assert::AreEqual(2.0, a[0], 0.0001);
			Assert::AreEqual(-3.0, a[1], 0.0001);
			Assert::AreEqual(5.0, a[2], 0.0001);
			Assert::AreEqual(-1.0, a[3], 0.0001);
		}
	};
}
