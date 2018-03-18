//
// Created by wein on 3/18/18.
//

#include <math.h>

#include <cciValue.h>

#include <assert.h>

void RunTinyTests();

void test_roundTripInt() {
    const int expected[7] = {
        0, 13, 0x37,
        INT32_MAX, INT32_MIN,
    };
    cciValue_t v = newInt(131);
    assert(131 == GETINT(v));
    for (int i=0; i<7; ++i) {
        SETINT(v, expected[i]);
        assert(expected[i] == GETINT(v));
    }
}

#define assertAlmostEqual(lhs,rhs) (assert(fabs((lhs) - (rhs)) < 1e-7))

void test_roundTripFloat() {
    const float expected[7] = {
        0.0f,
        1.1f, 123456778.0f,
        3.1415926f, 4.3e12f,
        -7.62f, 12e-13f,
    };
    cciValue_t v = newFloat(60 / (1001.0));
    assertAlmostEqual((60 / 1001.0), GETFLOAT(v));
    for (int i=0; i<7; ++i) {
        SETFLOAT(v, expected[i]);
        assertAlmostEqual(expected[i], GETFLOAT(v));
    }
}

void test_roundTripChar() {
    const char expected[9] = "doomsday";
    cciValue_t v = newChar('Z');
    assert('Z' == GETCHAR(v));
    for (int i=0; i<9; ++i) {
        SETCHAR(v, expected[i]);
        assert(expected[i] == GETCHAR(v));
    }
}

void test_roundTripMixedTypes() {
    cciValue_t v;
    SETINT(v, 0xBEEFBEEF);
    assert(0xBEEFBEEF == GETINT(v));
    SETCHAR(v, 'z');
    assert('z' == GETCHAR(v));
    SETFLOAT(v, 3.1415926535);
    assertAlmostEqual(3.1415926535, GETFLOAT(v));
    SETCHAR(v, 'A');
    assert('A' == GETCHAR(v));
    SETINT(v, -0xDEAD1001);
    assert(-0xDEAD1001 == GETINT(v));
}

void test_compareIntWithInt() {
    assert(0 == ICOMPARE(newInt(1), newInt(1)));
    assert(0 == ICOMPARE(newInt(2312), newInt(2312)));
    assert(ICOMPARE(newInt(123), newInt(12)) > 0);
    assert(ICOMPARE(newInt(12), newInt(121)) < 0);
}

void test_compareFloatWithFloat() {
    assert(0 == ICOMPARE(newFloat(3.14), newFloat(3.14)));
    assert(0 == ICOMPARE(newFloat(3.1415926535897f),
                         newFloat(3.1415926535898f)));
    assert(ICOMPARE(newFloat(123.123f), newFloat(12.231f)) > 0);
    assert(CompareF(newFloat(-213.1323f), newFloat(121)) < 0);
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}