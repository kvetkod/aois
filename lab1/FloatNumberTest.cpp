#include "pch.h"
#include "CppUnitTest.h"
#include "Binary.h"
#include"FloatBinary.h"
#include"Operation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
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
}