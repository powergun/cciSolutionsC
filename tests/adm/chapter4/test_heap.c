//
// Created by wein on 3/29/18.
//

#include <assert.h>
#include <stdio.h>

#include <admHeap.h>

void RunTinyTests();

void test_createDeleteHeap() {
    admHeap_t *hp = CreateAdmHeap(16);
    assert(hp);
    DeleteAdmHeap(hp);
}

void test_givenIndexExpectParentIndex() {
    admHeap_t *hp = CreateAdmHeap(16);
    assert(ADM_HP_INVALID_INDEX == AdmParentIndex(hp, 0));
    assert(0 == AdmParentIndex(hp, 1));
    assert(0 == AdmParentIndex(hp, 2));
    assert(1 == AdmParentIndex(hp, 3));
    assert(1 == AdmParentIndex(hp, 4));
    DeleteAdmHeap(hp);
}

void test_givenIndexExpectChildIndex() {
    admHeap_t *hp = CreateAdmHeap(16);
    assert(ADM_HP_INVALID_INDEX == AdmLeftChildIndex(hp, 17));
    assert(ADM_HP_INVALID_INDEX == AdmLeftChildIndex(hp, 9));
    DeleteAdmHeap(hp);
}

static int intSeqSorted(const int *expected, size_t sz) {
    for (int i=0; i<sz-1; ++i) {
        if (expected[i] > expected[i+1]) {
            return 0;
        }
    }
    return 1;
}

void test_insertExpectNewSequence() {
    admHeap_t *hp = NULL;
    int arr[16] = {3, 1, 4, 15, 9, 26, 53, 58, 97, 9, 32, 38, 462, 6};
    int out[16];
    for (size_t workload=4; workload < 14; ++workload) {
        hp = CreateAdmHeap(workload);
        for (size_t i=workload; i--; AdmHeapInsert(hp, CCIValue_newInt(arr[i]))) ;
        for (size_t i=workload; i--; out[workload - 1 - i] = CCIValue_GETINT(AdmHeapPop(hp))) ;
        DeleteAdmHeap(hp);
        assert(intSeqSorted(out, workload));
    }
}

static void assertIntSeqs(const int *lseq, const int *rseq, size_t sz) {
    for (size_t i=sz; i--; assert(lseq[i] == rseq[i])) ;
}

void test_heapsortInts() {
    int arr[7] = {3, 1, 4, 15, 9, 26, 53};
    int expected[7] = {1, 3, 4, 9, 15, 26, 53};
    AdmHeapsortInts(arr, 7);
    assertIntSeqs(expected, arr, 7);
}

void test_heapify() {
    cciArrayList_t *al = CCI_AlNew();
    int arr[7] = {3, 1, 4, 15, 9, 26, 53};
    for (size_t i=7; i--; CCI_AlEmplaceBack(al, CCIValue_newInt(arr[i]))) ;
    Heapify(al);
    for (size_t i=0; i < 7; printf("%d ", CCIValue_GETINT(CCI_AlGet(al, i))), i++) ;
    CCI_AlDelete(al);
}

static int assertAlAscendingOrder(cciArrayList_t *al) {
    for (size_t i=0; i<al->size - 1; assert(CCIValue_GETINT(CCI_AlGet(al, i)) <= CCIValue_GETINT(CCI_AlGet(al, i + 1))), i++) ;
}

void test_heapsortArrayList() {
    cciArrayList_t *al = CCI_AlNew();
    // empty
    AdmHeapsortAl(al, AdmHeapDirection_Ascending);
    assert(0 == al->size);

    // one element
    CCI_AlEmplaceBack(al, CCIValue_newInt(1));
    AdmHeapsortAl(al, AdmHeapDirection_Ascending);
    assert(1 == al->size);
    assert(CCIValue_ISVALID(CCI_AlGet(al, 0)));
    CCI_AlPopBack(al);

    // many element
    int arr[7] = {3, 1, 4, 15, 9, 26, 53};
    for (size_t i=7; i--; CCI_AlEmplaceBack(al, CCIValue_newInt(arr[i]))) ;
    AdmHeapsortAl(al, AdmHeapDirection_Ascending);
    assertAlAscendingOrder(al);
    CCI_AlDelete(al);
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}
