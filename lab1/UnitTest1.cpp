#include "pch.h"
#include "CppUnitTest.h"
#include "Binary.h"
#include"FloatBinary.h"
#include"Operation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(BinaryTest)
	{
	public:
		
		TEST_METHOD(DirectCodeTest)
		{
			Binary a(4);
			a.DirectCode();
			string number = a.GetBinaryNumber();
			Assert::AreEqual(number[0], '0');
			Assert::AreEqual(number[1], '1');
			Assert::AreEqual(number[2], '0');
			Assert::AreEqual(number[3], '0');
		}
		TEST_METHOD(ReverseCodeTest)
		{
			Binary a(4);
			a.ReverseCode();
			string number = a.GetBinaryNumber();
			Assert::AreEqual(number[0], '0');
			Assert::AreEqual(number[1], '0');
			Assert::AreEqual(number[2], '1');
			Assert::AreEqual(number[3], '1');
		}
		TEST_METHOD(AdditionalCodeTest)
		{
			Binary a(4);
			a.AdditionalCode();
			string number = a.GetBinaryNumber();
			Assert::AreEqual(number[0], '0');
			Assert::AreEqual(number[1], '1');
			Assert::AreEqual(number[2], '0');
			Assert::AreEqual(number[3], '0');
		}

		TEST_METHOD(FromBinaryTest)
		{
			Binary a("0100", 1);
			a.FromBinaryToDecimal();
			int number = a.GetDecimalNumber();
			Assert::AreEqual(number, 4);
		}
	};
	TEST_CLASS(FloatNumberTest) 
	{
	public:
		TEST_METHOD(DirectCodeExpTest) {
			FloatNumber a(12.5);
			a.DirectCode();
			string exp = a.GetExp();
			Assert::AreEqual(exp[0], '1');
			Assert::AreEqual(exp[1], '0');
			Assert::AreEqual(exp[2], '0');
			Assert::AreEqual(exp[3], '0');
			Assert::AreEqual(exp[4], '0');
			Assert::AreEqual(exp[5], '0');
			Assert::AreEqual(exp[6], '1');
			Assert::AreEqual(exp[7], '0');

		}
		TEST_METHOD(DirectCodeMantissaTest) {
			FloatNumber a(12.5);
			a.DirectCode();
			string exp = a.GetMantissa();
			Assert::AreEqual(exp[0], '1');
			Assert::AreEqual(exp[1], '0');
			Assert::AreEqual(exp[2], '0');
			Assert::AreEqual(exp[3], '1');
		}
		TEST_METHOD(FrombinaryTest) {
			FloatNumber a(12.5);
			a.DirectCode();
			a.FromBinaryToDecimal();
			double number = a.GetDecimal();
			Assert::AreEqual(number, 12.5);
		}
	};
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
