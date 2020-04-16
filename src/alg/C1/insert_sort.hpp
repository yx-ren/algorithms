#include <stdlib.h>
#include <iostream>

template<typename T>
void insert_sort(T& arr, size_t len, bool enbale_dump = false)
{
    if (len <= 1)
        return;

    for (size_t unsort_index = 1; unsort_index != len; unsort_index++)
    {
        auto& unsort_element = arr[unsort_index];

        // find insert pos, in sort range, first element
        size_t insert_pos = 0; // 0 means the unsort_element was min element
        for (int sort_index = unsort_index - 1; sort_index >= 0; sort_index--)
        {
            if (unsort_element > arr[sort_index])
            {
                insert_pos = sort_index + 1;
                break;
            }
        }

        // insert element to sort range(arr[0]~arr[unsort_index])
        auto next_insert_element = unsort_element;
        for (size_t pos = insert_pos; pos <= unsort_index; pos++)
            std::swap(next_insert_element, arr[pos]);

        if (enbale_dump)
        {
            for (int i = 0; i != len; i++)
                std::cout << arr[i] << (i == unsort_index ? "|" : ",");
            std::cout << std::endl;
        }
    }
}
