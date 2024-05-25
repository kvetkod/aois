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
	TEST_CLASS(MinimizationTest)
	{
	public:
		
		TEST_METHOD(Minimization1)
		{
			Logic a;
			a.TableOfTruth("(a&b)");
			string sknf = a.SKNF();
			MinimizationTable c(sknf);
			c.Minimization();
			Assert::AreEqual(sknf[0], '(');
		}
		
		TEST_METHOD(Minimization2)
		{
			Logic a;
			a.TableOfTruth("(a&b)");
			string sdnf = a.SDNF();
			MinimizationTable c(sdnf);
			c.Minimization();
			Assert::AreEqual(sdnf[0], '(');
		}

		TEST_METHOD(Minimization3)
		{
			Logic a;
			a.TableOfTruth("(a&b)");
			string sknf = a.SKNF();
			MinimizationTable c(sknf);
			c.TableMethod();
			Assert::AreEqual(sknf[0], '(');
		}

		TEST_METHOD(Minimization4)
		{
			Logic a;
			a.TableOfTruth("(a&b)");
			string sdnf = a.SDNF();
			MinimizationTable c(sdnf);
			c.TableMethod();
			Assert::AreEqual(sdnf[0], '(');
		}

	};




}
