#include <stdlib.h>
#include <iostream>
#include <alg/common.h>

AT_BEGIN

template<typename T>
int caculate_split_index(T* array, int len, int begin_index, int end_index)
{
    T split_val = array[end_index]; 
    int less_bound_index = begin_index - 1;
    int greate_bound_index = begin_index;
    for (; greate_bound_index <= end_index; greate_bound_index++)
    {
        if (array[greate_bound_index] <= split_val)
        {
            less_bound_index++;
            std::swap(array[less_bound_index], array[greate_bound_index]);
        }
    }

    int split_index = less_bound_index + 1;
    std::swap(array[split_index], array[end_index]);
    return split_index;
}

template<typename T>
void quick_sort(T* array, int len, int begin_index, int end_index)
{
    if (begin_index < end_index
        && begin_index >= 0
        && end_index <= len - 1
        )
    {
        int split_index = caculate_split_index(array, len, begin_index, end_index);
        std::cout << "split_index:[ " << split_index << " ]" << std::endl;
        quick_sort(array, len, begin_index, split_index - 1);
        quick_sort(array, len, split_index + 1, end_index);
    }
}

AT_END
