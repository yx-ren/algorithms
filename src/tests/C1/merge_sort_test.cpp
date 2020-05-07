#include <iostream>
#include <vector>
#include <time.h>
#include <alg/C1/merge_sort.hpp>
#include <algorithm>

int main(int argc, const char* argv[])
{
#if 1
    int arr[] = {-1, -100, -1000, 0x6fffffff, 1, 3, 8, 0, 2, 4, 9};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    //int mid = arr_len / 2;
    merge_sort(arr, 0, arr_len - 1);

    for (int i = 0; i != arr_len; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
#else
    int arr[] = {1, 3, 8, 0, 2, 4, 9};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    merge(arr, 0, 2, arr_len - 1);

    for (int i = 0; i != arr_len; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
#endif


    return 0;
}
