#include "pch.h"
#include "CppUnitTest.h"
#include "Binary.h"
#include"FloatBinary.h"
#include"Operation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(OperationNumber)
	{
	public:
		TEST_METHOD(Sum1Test) {
			Operation a(1, 2);
			string result = a.Sum();
			Binary b(result, 1);
			b.FromBinaryToDecimal();
			Assert::AreEqual(b.GetDecimalNumber(), 3);
		}
		TEST_METHOD(Sum2Test) {
			Operation a(1, -2);
			string result = a.Sum();
			Binary b(result, 1);
			b.FromBinaryToDecimal();
			Assert::AreEqual(b.GetDecimalNumber(), -1);
		}
		TEST_METHOD(Sum3Test) {
			Operation a(-1, 2);
			string result = a.Sum();
			Binary b(result, 1);
			b.FromBinaryToDecimal();
			Assert::AreEqual(b.GetDecimalNumber(), 1);
		}
		TEST_METHOD(Sum4Test) {
			Operation a(-1, -2);
			string result = a.Sum();
			Binary b(result, 1);
			b.FromBinaryToDecimal();
			Assert::AreEqual(b.GetDecimalNumber(), -3);
		}
		TEST_METHOD(SubstractionTest) {
			Operation a(-1, 2);
			string result = a.Subtraction();
			Binary b(result, 1);
			b.FromBinaryToDecimal();
			Assert::AreEqual(b.GetDecimalNumber(), -3);
		}
		TEST_METHOD(MultiplicationTest) {
			Operation a(-1, 2);
			string result = a.Multiplication();
			Binary b(result, 1);
			b.FromBinaryToDecimal();
			Assert::AreEqual(b.GetDecimalNumber(), -2);
		}
		TEST_METHOD(DivisionTest) {
			Operation a(4, 2);
			string result = a.Division();
			Binary b(result, 1);
			b.FromBinaryToDecimal();
			Assert::AreEqual(b.GetDecimalNumber(), 2);
		}
		TEST_METHOD(FloatSumTest) {
			Operation a(12.5, 1.5);
			a.SumForFloat();
		}
	};
}