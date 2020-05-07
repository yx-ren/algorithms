#include <iostream>
#include <assert.h>

int global_count = 0;
template<typename T>
void merge(T* arr, int low_bound_index, int splite_index, int up_bound_index)
{
    assert(low_bound_index <= splite_index && splite_index < up_bound_index);

    int lhs_element_size = splite_index - low_bound_index + 1;
    int rhs_element_size = up_bound_index - splite_index;

    T lhs_element[lhs_element_size];
    T rhs_element[rhs_element_size];

    for (int i = 0; i != lhs_element_size; i++)
        lhs_element[i] = arr[low_bound_index + i];
    for (int i = 0; i != rhs_element_size; i++)
        rhs_element[i] = arr[splite_index + 1 + i];

#if 1
    int lhs_index = 0;
    int rhs_index = 0;
    int index = low_bound_index;
    while (lhs_index <= lhs_element_size - 1 && rhs_index <= rhs_element_size - 1)
    {
        if (lhs_element[lhs_index] < rhs_element[rhs_index])
        {
            arr[index] = lhs_element[lhs_index];
            index++;
            lhs_index++;
        }
        else
        {
            arr[index] = rhs_element[rhs_index];
            index++;
            rhs_index++;
        }
    }

    while (lhs_index <= lhs_element_size - 1)
    {
        arr[index] = lhs_element[lhs_index];
        index++;
        lhs_index++;
    }

    while (rhs_index <= rhs_element_size - 1)
    {
        arr[index] = rhs_element[rhs_index];
        index++;
        rhs_index++;
    }

#else
#endif
}

template<typename T>
void merge_sort(T arr, int lhs_bound, int rhs_bound)
{
    std::cout << global_count++ << std::endl;
    if (lhs_bound >= rhs_bound)
        return;

    int mid = lhs_bound + ((rhs_bound - lhs_bound) / 2);

    merge_sort(arr, lhs_bound, mid);
    merge_sort(arr, mid + 1, rhs_bound);

    merge(arr, lhs_bound, mid, rhs_bound);
}
