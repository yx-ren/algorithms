#include <iostream>
#include <sstream>

template<typename T>
struct arr_range
{
    arr_range() {}

    arr_range(T* _arr, T _sum, int _low, int _high)
        : arr(_arr)
        , sum(_sum)
        , low(_low)
        , high(_high)
    {}

    std::string toString()
    {
        std::ostringstream oss;
        oss << "sum:[" << sum << "], low index:[" << low <<"], high index:[" << high << "]" << std::endl;
        return oss.str();
    }

    T* arr;
    T sum;
    int low;
    int high;
};

template<typename T>
arr_range<T> find_sub_max_arr_cross_mid(T* arr, int low, int mid, int high)
{
    int lhs_max_index = mid;
    int lhs_max_sum = 0;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > lhs_max_sum)
        {
            lhs_max_index = i;
            lhs_max_sum = sum;
        }
    }

    int rhs_max_index = mid + 1;
    int rhs_max_sum = 0;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > rhs_max_sum)
        {
            rhs_max_index = i;
            rhs_max_sum = sum;
        }
    }

    return arr_range<T>(arr, lhs_max_sum + rhs_max_sum, lhs_max_index, rhs_max_index);
}

template<typename T>
arr_range<T> find_sub_max_arr(T* arr, int low, int high)
{
    std::cout << "calculate arr[" << low << ", " << high << "]" <<std::endl;

    if (low == high)
    {
        return arr_range<T>(arr, arr[low], low, high);
    }
    else
    {
        int mid = low + (high - low) / 2;
        arr_range<T> lhs_range = find_sub_max_arr(arr, low, mid);
        arr_range<T> rhs_range = find_sub_max_arr(arr, mid + 1, high);
        arr_range<T> cross_mid_range  = find_sub_max_arr_cross_mid(arr, low, mid, high);

        if (lhs_range.sum >= rhs_range.sum && lhs_range.sum >= cross_mid_range.sum)
            return lhs_range;
        else if (rhs_range.sum >= lhs_range.sum && rhs_range.sum >= cross_mid_range.sum)
            return rhs_range;
        else
            return cross_mid_range;
    }
}
