
add_tinytest_executable(admHeapTest test_heap.c)
target_link_libraries(admHeapTest admChapter4)
add_test(NAME "ADM::Chapter4::HeapTest" COMMAND admHeapTest)

add_executable(admHeapProf test_heap_prof.c)
target_link_libraries(admHeapProf admChapter4)

add_tinytest_executable(admMergesortTest test_mergesort.c)
target_link_libraries(admMergesortTest admChapter4)
add_test(NAME "ADM::Chapter4::Mergesort" COMMAND admMergesortTest)

add_executable(compareSortAlgo compare_sort_algo.c)
target_link_libraries(compareSortAlgo admChapter4)

add_tinytest_executable(admQuicksortTest test_quicksort.c)
target_link_libraries(admQuicksortTest admChapter4)
add_test(NAME "ADM::Chapter4::Quicksort" COMMAND admQuicksortTest)