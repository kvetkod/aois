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
	
	
}
