#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_9.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest93
{
	TEST_CLASS(UnitTest93)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c;
			int const N = 1;
			const string nameTowar;
			Price* p = new Price[1];
			c = BinSearch(p, 1, nameTowar);
			Assert::AreEqual(c, 0);
		}
	};
}
