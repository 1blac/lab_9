#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_9.1_/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91A
{
	TEST_CLASS(UnitTest91A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c;
			int const i = 1;
			Students* S = new Students[1];
			c = Percentage(S, 1);
			Assert::AreEqual(c, 0);
		}
	};
}
