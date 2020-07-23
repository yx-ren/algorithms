#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <functional>
#include <alg/common.h>

AT_BEGIN

template<typename T>
int caculate_split_index(T* array, int len, int begin_index, int end_index)
{
    T split_val = array[end_index]; 
    int less_bound_index = begin_index - 1;
    int greate_bound_index = begin_index;
    for (; greate_bound_index != end_index; greate_bound_index++)
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
    auto dump_array = [&](T* array, int split_index, int begin_index, int end_index)
    {
        std::cout << "split_index:[ " << split_index << " ], split val:[" << array[split_index]<< "], "
            << "begin_index:[ " << begin_index << " ], "
            << "end_index:[ " << end_index << " ]"
            << std::endl;
        std::ostringstream oss;
#if 0
        for (int i = 0; i != splite_index; i++)
            oss << array[i] << ", ";
        oss << " | ";

        for (int i = begin_index; i <= end_index; i++)
            oss << array[i] << ", ";
#else

#if 1
        for (int i = 0; i <= end_index; i++)
        {
            if (i == split_index)
                oss << "[" << array[i] <<"], ";
            else
                oss << array[i] << ", ";
        }
#endif


#if 0
        std::ostringstream oss;
        for (int i = 0; i != split_index; i++)
            oss << array[i] << ", ";
        oss_dump << "sort range:[" << oss.str() << "]; ";

        oss.clear();
        oss.str("");
#endif



#endif

        std::cout << oss.str() << std::endl;
    };

    if (begin_index < end_index
        && begin_index >= 0
        && end_index <= len - 1
        )
    {
        int split_index = caculate_split_index(array, len, begin_index, end_index);
        dump_array(array, split_index, begin_index, end_index);
        quick_sort(array, len, begin_index, split_index - 1);
        quick_sort(array, len, split_index + 1, end_index);
    }
}

AT_END
