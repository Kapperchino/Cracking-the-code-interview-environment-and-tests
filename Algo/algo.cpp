#include "algo.hpp"
#include <algorithm>
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

void quickSort(std::vector<int> &arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);
}

void quickSortHelper(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int index = partition(arr, left, right);
    quickSortHelper(arr, left, index - 1);
    quickSortHelper(arr, index + 1, right);
}

int partition(std::vector<int> &arr, int left, int right)
{
    int pivoit = arr[right];
    int tail = left - 1;
    for (int x = left; x < right; x++)
    {
        if (arr[x] <= pivoit)
        {
            ++tail;
            std::swap(arr[tail], arr[x]);
        }
    }
    ++tail;
    std::swap(arr[tail], arr[right]);
    return tail;
}

void insertionSort(std::vector<int> &arr)
{
    int sorted = 0;
    for (int x = 1; x < arr.size(); x++)
    {
        sorted = x;
        while (sorted > 0 && arr[sorted - 1] > arr[sorted])
        {
            std::swap(arr[sorted], arr[sorted - 1]);
            sorted--;
        }
    }
}

void selectionSort(std::vector<int> &arr)
{
    for (int x = 0; x < arr.size() - 1; x++)
    {
        int minIndex = x;
        for (int y = x + 1; y < arr.size(); y++)
        {
            if (arr[y] < arr[minIndex])
            {
                minIndex = y;
            }
        }
        std::swap(arr[minIndex], arr[x]);
    }
}

void mergeSort(std::vector<int> &arr)
{
    mergeHelper(arr, 0, arr.size() - 1);
}

void mergeHelper(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeHelper(arr, left, mid);
        mergeHelper(arr, mid + 1, right);
        mergeArray(arr, left, right, mid);
    }
}

void mergeArray(std::vector<int> &arr, int left, int right, int middle)
{
    int leftLength = middle - left + 1;
    int rightLength = right - middle;
    std::vector<int> leftArr(leftLength,0);
    std::vector<int> rightArr(rightLength,0);

    for (int x = 0; x < leftArr.size(); x++)
    {
        leftArr[x] = arr[x + left];
    }

    for (int x = 0; x < rightArr.size(); x++)
    {
        rightArr[x] = arr[x + right];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = leftIndex;

    while (leftIndex < leftLength && rightIndex < rightLength)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex])
        {
            arr[mergedIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mergedIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    while (leftIndex < leftLength)
    {
        arr[mergedIndex] = leftArr[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    while (rightIndex < rightLength)
    {
        arr[mergedIndex] = rightArr[rightIndex];
        rightIndex++;
        mergedIndex++;
    }
}