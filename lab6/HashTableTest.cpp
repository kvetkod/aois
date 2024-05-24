#include "pch.h"
#include "CppUnitTest.h"
#include"HashTable.h"
#include"Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(HashTableTest)
	{
	public:
		
		TEST_METHOD(AddElementTest)
		{
			HashTable a(20);
			a.AddElement("Гора", "Гора это возвышенность");
			a.AddElement("Горка", "Гора это возвышенность");
			a.AddElement("Город", "Гора это возвышенность");
			a.PrintTable();
			Node b("1", "2", 2);
			b.SetTerminalFalse();
		}

		TEST_METHOD(ReadTest)
		{
			HashTable a(20);
			a.AddElement("Гора", "Гора это возвышенность");
			a.Read("Гора");
			a.AddElement("Горка", "Гора это возвышенность");
			a.AddElement("Город", "Гора это возвышенность");
			a.Read("Город");
		}

		TEST_METHOD(DeleteTest)
		{
			HashTable a(20);
			a.AddElement("Гора", "Гора это возвышенность");
			a.Delete("Горка");
			a.Delete("Гора");
			a.AddElement("Гора", "Гора это возвышенность");
			a.AddElement("Горка", "Гора это возвышенность");
			a.Delete("Горка");
		}

		TEST_METHOD(UpdateTest)
		{
			HashTable a(20);
			a.AddElement("Гора", "Гора это возвышенность");
			a.Update("Гора", "asd", "asddf");
			a.AddElement("Горка", "Гора это возвышенность");
			a.Update("Горка", "asd", "asddf");
		}
	};
}
