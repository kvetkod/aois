#include "pch.h"
#include<string>
#include<sstream>
#include<vector>
#include"Logic.h"
#include"MinimizationTable.h"
#include"Karno.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest2
{

	TEST_CLASS(KarnoTest)
	{
	public:

		TEST_METHOD(Karno1Test)
		{
			Logic a;
			a.TableOfTruth("(a&b)");
			string sknf = a.SKNF();
			Karno c(sknf, a.GetTable());
			c.KarnoMethod();
			Assert::AreEqual(sknf[0], '(');
		}

		TEST_METHOD(Karno2Test)
		{
			Logic a;
			a.TableOfTruth("(a&b)");
			string sdnf = a.SDNF();
			Karno c(sdnf, a.GetTable());
			c.KarnoMethod();
			Assert::AreEqual(sdnf[0], '(');
		}



	};
}
