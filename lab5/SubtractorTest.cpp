#include "pch.h"
#include"Subtractor.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(SubtactorTest)
	{
	public:
		
		TEST_METHOD(CreateSubtractorTest)
		{
			Subtractor a;
			a.CreateSubtractor();
		}
	};
}
