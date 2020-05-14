#include <iostream>
#include <alg/C4/find_sub_max_arr.hpp>

int main(int argc, const char* argv[])
{
    int arr[] = {-1, -10, 1, -1, 0, 2, 4, 5, 6, 1, -5, -6, 1, 2, 3, 10};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    auto range_info = find_sub_max_arr(arr, 0, arr_len - 1);

    std::cout << range_info.toString() << std::endl;

    return 0;
}
