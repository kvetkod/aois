#include "pch.h"
#include"Synthesis.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(SynthesisTest)
	{
	public:

		TEST_METHOD(MakeSyntesisTest)
		{
			Synthesis a;
			a.MakeSynthesis();
		}
	};
}
