//
// Created by wein on 3/24/18.
//

#include <time.h>
#include <stdio.h>
#include <cciList.h>

static void testRoundTripInt() {
    int size = 20000;
    double microsec = 0.0;
    clock_t before, after;
    printf("start integration test: integer round trip (problem size: %d)......", size);
    before = clock();
    cciList_t *l = NewList();
    for (int i=0; i<size; ++i) {
        Append(l, newInt(i));
    }
    after = clock();
    microsec = after - before;
    printf("DONE\n%f s (%f ms)\n", microsec/1000000, microsec/1000);
}

int main(int argc, char **argv) {
    testRoundTripInt();
    return 0;
}