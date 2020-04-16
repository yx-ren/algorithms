#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void insert_sort(int arr[], size_t len)
{
    for (int unsort_index = 1; unsort_index != len; unsort_index++)
    {
        int sort_max_index = unsort_index - 1;

        // find the insert pos
        int insert_pos = 0; // init the unsort_element was min
        int unsort_element = arr[unsort_index];
        for (int sort_index = sort_max_index; sort_index >=0; sort_index--)
        {
            int sort_element = arr[sort_index];
            if (unsort_element >= sort_element)
            {
                insert_pos = sort_index + 1;
                break;
            }
        }

        // insert arr[index] to {arr[0], arr[index - 1]}
        int next_insert_element = unsort_element;
        for (int pos = insert_pos; pos <= unsort_index; pos++)
            std::swap(next_insert_element, arr[pos]);

        // dump
        for (int index = 0; index != len; index++)
            std::cout << arr[index] << (index == unsort_index ? "| " : ", ");
        std::cout << std::endl;
    }
}
