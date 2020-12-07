#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_9.2__/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92
{
	TEST_CLASS(UnitTest92)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int* c;
			int const N = 1;
			student* s = new student[1];
			c = IndexSort(s, 1);
			Assert::AreEqual(*c, 0);
		}
	};
}
