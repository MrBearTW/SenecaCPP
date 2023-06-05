#include "pch.h"
#include "CppUnitTest.h"
#include "mathfuncs_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*
namespace MathTestSuite
{

    TEST_CLASS(MathTest)
    {
    public:

        TEST_METHOD(SquareTest)
        {
            double d = square(8.0);
            Assert::AreEqual(64.0, d);
        }

        TEST_METHOD(CubeTest)
        {
            double d = cube(3.0);
            Assert::AreEqual(27.0, d);
        }

    };

    TEST_CLASS(MathIntegrationTest)
    {
    public:

        TEST_METHOD(AdditionTest)
        {
            double d = square(8.0);
            double d1 = cube(3.0);
            Assert::AreEqual(91.0, d + d1);
        }
    };
}
*/

namespace WorkshopTestSuite
{
    TEST_CLASS(NotEmpty)
    {
    public:

        TEST_METHOD(isEmpty)
        {
            char test[] = {"\0"};
            double d = notEmpty(test);
            Assert::AreEqual(0.0, d);
        }
        TEST_METHOD(isnotEmpty)
        {
            char test[] = { "ABC" };
            double d = notEmpty(test);
            Assert::AreEqual(1.0, d);
        }
    };

    TEST_CLASS(CenterIsSpace)
    {
    public:

        TEST_METHOD(centerIsNotSpace)
        {
            char test[] = { "abcdef" };
            double d = centerIsSpace(test);
            Assert::AreEqual(1.0, d);
        }
        TEST_METHOD(centerisSpace)
        {
            char test[] = { "abc def" };
            double d = centerIsSpace(test);
            Assert::AreEqual(0.0, d);
        }
    };

    
}
