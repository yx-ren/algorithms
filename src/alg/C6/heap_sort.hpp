#include <stdlib.h>
#include <iostream>
#include <alg/commont.h>

AT_BEGIN

GET_LEFT_INDEX(i)   (i << 1)
GET_RIGHT_INDEX(i)  (i << 1 + 1)
GET_PARENT_INDEX(i) (i >> 1)

template<typename T>
void max_heapify(T* array, len_t len, int index)
{
    // check range
    int lhs_index = GET_LEFT_INDEX(index);
    int rhs_index = GET_RIGHT_INDEX(index);

    auto out_range =
        [&](len_t len, int lhs, int rhs)
        {
            len_t up_bound_index = len - 1;
            if (lhs > up_bound_index || rhs > up_bound_index)
                return false;
            else
                return true;
        }
    if (!out_range(len, lhs_index, rhs_index))
        return;

    // get max value and max index
    auto get_max_index =
        [&](T* array, int lhs, int rhs, int index)
        {
            int max_index = index;
            if (array[lhs] > array[index])
                max_index = lhs;

            if (array[rhs] > array[max_index])
                max_index = rhs;
        }
    int max_index = get_max_index(array, lhs_index, rhs_index, index);

    // may be swap
    if (max_index != index)
    {
        swap(array[max_index], array[index]);
        max_heapify(array, len, max_index);
    }

    return;
}

template<typename T>
void build_max_heap(T* array, size_t size, size_t len)
{
    for (int i = (size / 2) - 1; i >=0; i--)
        max_heapify(array, len, i);
}

template<typename T>
void heap_sort(T* array, size_t size, size_t len)
{
    build_max_heap(T, size);

    for (int i = len - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        max_heapify(array, i + 1, 1);
    }
}

AT_END
