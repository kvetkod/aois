#include "pch.h"
#include "CppUnitTest.h"
#include"Logic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(LogicTest1)
	{
	public:
		
		
		
		
		TEST_METHOD(CreateTable1Test)
		{
			Logic a;
			a.TableOfTruth("!a");
			
		}
		TEST_METHOD(DisTest)
		{
			Logic a;
			a.TableOfTruth("(a|b)");
			a.IndexForm();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			a.PrintIndexForm();

			string b = buf.str();
			//Assert::AreEqual(b.c_str(), "0001");
			Assert::AreEqual(b[0], '0');
			Assert::AreEqual(b[1], '1');
			Assert::AreEqual(b[2], '1');
			Assert::AreEqual(b[3], '1');

		}
		TEST_METHOD(EqualTest)
		{
			Logic a;
			a.TableOfTruth("(a~b)");
			a.IndexForm();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			a.PrintIndexForm();

			string b = buf.str();
			Assert::AreEqual(b[0], '1');
			Assert::AreEqual(b[1], '0');
			Assert::AreEqual(b[2], '0');
			Assert::AreEqual(b[3], '1');

		}
		TEST_METHOD(IndexTest) {
			Logic a;
			a.TableOfTruth("(a->b)");
			a.IndexForm();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			a.PrintIndexForm();

			string b = buf.str();
			Assert::AreEqual(b[0], '1');
			Assert::AreEqual(b[1], '1');
			Assert::AreEqual(b[2], '0');
			Assert::AreEqual(b[3], '1');
		}
		TEST_METHOD(CreateTable5Test)
		{
			Logic a;
			a.TableOfTruth("(a&b)");
			a.IndexForm();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			a.PrintIndexForm();

			string b = buf.str();
			Assert::AreEqual(b[0], '0');
			Assert::AreEqual(b[1], '0');
			Assert::AreEqual(b[2], '0');
			Assert::AreEqual(b[3], '1');
		}
		TEST_METHOD(IndexFormTest) {
			Logic a;
			a.TableOfTruth("(a&b)");
			a.IndexForm();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			a.PrintIndexForm();

			string b = buf.str();
			Assert::AreEqual(b[0], '0');
			Assert::AreEqual(b[1], '0');
			Assert::AreEqual(b[2], '0');
			Assert::AreEqual(b[3], '1');
		}
		TEST_METHOD(NumericFormTest) {
			Logic a;
			a.TableOfTruth("(a&b)");
			a.NumericForm();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			a.PrintNumericForm();

			string b = buf.str();

			Assert::AreEqual(b[0], '0');
			Assert::AreEqual(b[1], ' ');
			Assert::AreEqual(b[2], '1');
			Assert::AreEqual(b[3], ' ');
			Assert::AreEqual(b[4], '2');
			Assert::AreEqual(b[5], ' ');
			Assert::AreEqual(b[6], '&');
		}

		TEST_METHOD(SKNFTest) {
			Logic a;
			a.TableOfTruth("(a&b)");
			
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			a.SKNF();

			string b = buf.str();

			Assert::AreEqual(b[0], '(');
			Assert::AreEqual(b[1], 'a');
			Assert::AreEqual(b[2], '|');
			Assert::AreEqual(b[3], 'b');
			Assert::AreEqual(b[4], ')');
		}

		TEST_METHOD(SDNFTest) {
			Logic a;
			a.TableOfTruth("(a&b)");

			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			a.SDNF();

			string b = buf.str();

			Assert::AreEqual(b[0], '(');
			Assert::AreEqual(b[1], 'a');
			Assert::AreEqual(b[2], '&');
			Assert::AreEqual(b[3], 'b');
			Assert::AreEqual(b[4], ')');

		}
	};
}
