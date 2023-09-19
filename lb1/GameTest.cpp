#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

static std::wstring ToString(const Puzzle& game) {
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
			Puzzle game;
			Puzzle notExpected = game;
			notExpected.movementUp();
			Assert::AreNotEqual(notExpected, game);
		}

		TEST_METHOD(TestMethod2)
		{
			Puzzle game;
			Puzzle expected = game;
			expected.movementUp();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod3)
		{
			Puzzle game;
			Puzzle expected = game;
			expected.movementLeft();
			expected.movementRight();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod4)
		{
			Puzzle game;
			Puzzle notExpected = game;
			notExpected.movementUp();
			notExpected.movementLeft();
			notExpected.movementDown();
			notExpected.movementRight();
			Assert::AreNotEqual(notExpected, game);
		}

		TEST_METHOD(TestMethod5)
		{
			Puzzle game;
			Puzzle expected = game;
			expected.movementUp();
			expected.movementUp();
			expected.movementDown();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod6)
		{
			Puzzle game;
			Puzzle notExpected = game;
			notExpected.movementUp();
			notExpected.movementUp();
			Assert::AreNotEqual(notExpected, game);
		}

		TEST_METHOD(TestMethod7)
		{
			Puzzle game;
			Puzzle expected = game;
			expected.movementRight();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod8)
		{
			Puzzle game;
			Puzzle expected = game;
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod9)
		{
			Puzzle game;
			Puzzle expected = game;
			expected.movementDown();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod10)
		{
			Puzzle game;
			game.showField();
			Puzzle expected = game;
			expected.movementDown();
			expected.movementDown();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}
	};
}
