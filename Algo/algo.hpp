#pragma once
#include <vector>
int binarySearch(const std::vector<int> arr, const int key);
void quickSort(std::vector<int>& arr);
void quickSortHelper(std::vector<int> & arr, int left, int right);
int partition(std::vector<int>& arr,int left, int right);
void insertionSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr);
void mergeHelper(std::vector<int>& arr,int left, int right);
void mergeArray(std::vector<int>& arr,int left,int right, int middle);