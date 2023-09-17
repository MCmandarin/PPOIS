#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

static std::wstring ToString(const puzzle& game) {
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
			puzzle game;
			puzzle notExpected = game;
			notExpected.movementUp();
			Assert::AreNotEqual(notExpected, game);
		}

		TEST_METHOD(TestMethod2)
		{
			puzzle game;
			puzzle expected = game;
			expected.movementUp();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod3)
		{
			puzzle game;
			puzzle expected = game;
			expected.movementLeft();
			expected.movementRight();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod4)
		{
			puzzle game;
			puzzle notExpected = game;
			notExpected.movementUp();
			notExpected.movementLeft();
			notExpected.movementDown();
			notExpected.movementRight();
			Assert::AreNotEqual(notExpected, game);
		}

		TEST_METHOD(TestMethod5)
		{
			puzzle game;
			puzzle expected = game;
			expected.movementUp();
			expected.movementUp();
			expected.movementDown();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod6)
		{
			puzzle game;
			puzzle notExpected = game;
			notExpected.movementUp();
			notExpected.movementUp();
			Assert::AreNotEqual(notExpected, game);
		}

		TEST_METHOD(TestMethod7)
		{
			puzzle game;
			puzzle expected = game;
			expected.movementRight();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod8)
		{
			puzzle game;
			puzzle expected = game;
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod9)
		{
			puzzle game;
			puzzle expected = game;
			expected.movementDown();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}

		TEST_METHOD(TestMethod10)
		{
			puzzle game;
			game.showField();
			puzzle expected = game;
			expected.movementDown();
			expected.movementDown();
			expected.movementDown();
			Assert::AreEqual(expected, game);
		}
	};
}
