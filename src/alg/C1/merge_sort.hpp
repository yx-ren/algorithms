#include <iostream>

int global_count = 0;
template<typename T>
void merge(T* arr, int lhs_bound, int mid, int rhs_bound)
{
#if 1
    if (lhs_bound >= rhs_bound)
        return;
#else
    if (mid == 0)
        return;
#endif

    int element_size = rhs_bound - lhs_bound + 1;
    int lhs_element_size = mid - lhs_bound + 1;
    int rhs_element_size = rhs_bound - mid;

    int index = 0;
    T lhs_arr[lhs_element_size] = {0};
    for (int i = lhs_bound; i <= mid; i++, index++)
        lhs_arr[index] = arr[i];

    index = 0;
    T rhs_arr[rhs_element_size] = {0};
    for (int i = mid + 1; i < rhs_bound; i++, index++)
        rhs_arr[index] = arr[i];

    int lhs_index = 0;
    int rhs_index = 0;
    //index = 0;
#if 0
    while (lhs_index < lhs_element_size || rhs_index < rhs_element_size)
    {
        if (lhs_arr[lhs_index] < rhs_arr[rhs_index])
        {
            arr[index] = lhs_arr[lhs_index];
            lhs_index++;
        }
        else
        {
            arr[index] = rhs_arr[rhs_index];
            rhs_index++;
        }

        index++;
    }
#else
    for (int index = 0; index != element_size; index++)
    {
        if (lhs_arr[lhs_index] < rhs_arr[rhs_index])
        {
            arr[index] = lhs_arr[lhs_index];
            lhs_index++;
        }
        else
        {
            arr[index] = rhs_arr[rhs_index];
            rhs_index++;
        }
    }
#endif

    return;
}

template<typename T>
void merge_sort(T arr, int lhs_bound, int rhs_bound)
{
    std::cout << global_count++ << std::endl;
    int mid = lhs_bound + ((rhs_bound - lhs_bound) / 2);

#if 0
    merge(arr, 0, mid / 2, mid);
    merge(arr, mid + 1, (len - (mid + 1)) / 2, len);
#else
    merge_sort(arr, lhs_bound, mid);
    merge_sort(arr, mid + 1, rhs_bound);
#endif

    merge(arr, lhs_bound, mid, rhs_bound);
}
