#include "pch.h"
#include"Sumator.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(SumatorTest)
	{
	public:
		
		TEST_METHOD(CreateSumator1)
		{
			Sumator a;
			a.CreateSumator();
		}
	};
}
