#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

static std::wstring ToString(const pazle& game) {
	wstringstream _s;
	_s << game.returnField();
	return _s.str();
}

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			pazle game;
			pazle notExpected = game;
			notExpected.movementUp();
			Assert::AreNotEqual(notExpected, game);
		}

		TEST_METHOD(TestMethod2)
		{
			pazle game;
			pazle expected = game;
			expected.movementUp();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod3)
		{
			pazle game;
			pazle expected = game;
			expected.movementLeft();
			expected.movementRight();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod4)
		{
			pazle game;
			pazle notExpected = game;
			notExpected.movementUp();
			notExpected.movementLeft();
			notExpected.movementDown();
			notExpected.movementRight();
			Assert::AreNotEqual(notExpected, game);
		}

		TEST_METHOD(TestMethod5)
		{
			pazle game;
			pazle expected = game;
			expected.movementUp();
			expected.movementUp();
			expected.movementDown();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod6)
		{
			pazle game;
			pazle notExpected = game;
			notExpected.movementUp();
			notExpected.movementUp();
			Assert::AreNotEqual(notExpected, game);
		}

		TEST_METHOD(TestMethod7)
		{
			pazle game;
			pazle expected = game;
			expected.movementRight();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod8)
		{
			pazle game;
			pazle expected = game;
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod9)
		{
			pazle game;
			pazle expected = game;
			expected.movementDown();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod10)
		{
			pazle game;
			game.showField();
			pazle expected = game;
			expected.movementDown();
			expected.movementDown();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}
	};
}
