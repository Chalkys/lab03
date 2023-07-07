#include "modul-test.h"
#include <cassert>

void test_positive() {
    double min = 0;
    double max = 0;
    max = max_min({1, 2, 3}, 1);
    min = max_min({1, 2, 3}, 0);
    assert(min == 1);
    assert(max == 3);

    /*
    max = max_min({0, -2, -3}, 1);
    min = max_min({0, -2, -3}, 0);
    assert(min == -3);
    assert(max == 0);
    */
}

int main () {
    test_positive();
    return 0;
}
