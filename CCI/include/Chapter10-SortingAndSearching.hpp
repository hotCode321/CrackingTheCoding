#include <vector>

void mergesort(std::vector<int> array);
void mergesort(std::vector<int> array, std::vector<int> helper, int low, int high);
void merge(std::vector<int> array, std::vector<int> helper, int low, int middle, int high);
void quickSort(std::vector<int>, int left, int right);
int partition(std::vector<int> arr, int left, int right);
int binarySearch(std::vector<int> a, int x);
int binarySearchRecursive(std::vector<int> a, int x, int low, int high);
void sortValleyPeak(std::vector<int> array);
void swap(std::vector<int> array, int left, int right);