#include <iostream>
#include <functional>
#include <alg/C7/quick_sort.hpp>

using ALG_TEST_NAMESPACE;
int main(int argc, const char* argv[])
{
    int array[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int len = sizeof(array) / sizeof(array[0]);
    quick_sort(array, len, 0, len - 1);

    auto dump_array = [&](int* array, int len)
    {
        for (int i = 0; i != len; i++)
            std::cout << array[i] << ", ";
    };

    dump_array(array, len);
    std::cout << std::endl;

    return 0;
}
