#include <iostream>
#include <vector>
#include <time.h>
#include <alg/C1/insert_sort.hpp>
#include <algorithm>

int main(int argc, const char* argv[])
{
    srand(0);
    int arr[] = {7, 4, 1, 6, 7, 9, 0, 0, 0};
    insert_sort(arr, sizeof(arr) / sizeof(arr[0]), true);

    std::vector<int> vecs;
    int len = 10;
    for (int i = 0; i != len; i++)
        vecs.push_back(rand() % len);

    std::cout << "dump origin random vals:" << std::endl;
    std::for_each(vecs.begin(), vecs.end(), [&](const int& e){std::cout << e << ",";});
    std::cout << std::endl;

    insert_sort(vecs, vecs.size(), true);

    return 0;
}
