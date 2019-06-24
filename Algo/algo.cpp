#include "algo.hpp"
int binarySearch(const std::vector<int> arr, const int key)
{
    int l = 0;
    int r = arr.size() - 1;
    int mid = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }

        if (key > mid)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}
