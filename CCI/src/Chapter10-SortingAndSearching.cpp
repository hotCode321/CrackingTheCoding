#include "Chapter10-SortingAndSearching.hpp"
#include <vector>
#include <algorithm>

void mergesort(std::vector<int> array)
{
    std::vector<int> helper(array.size());
    mergesort(array, helper, 0, array.size() - 1);
}

void mergesort(std::vector<int> array, std::vector<int> helper, int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;
        mergesort(array, helper, low, middle);      // Sort left half
        mergesort(array, helper, middle + 1, high); // Sort right half
        merge(array, helper, low, middle, high);    // Merge them
    }
}

void merge(std::vector<int> array, std::vector<int> helper, int low, int middle, int high)
{
    /* Copy both halves into a helper array*/
    for (int i = low; i = high; i++)
    {
        helper[i] = array[i];
    }
    int helperleft = low;
    int helperRight = middle + 1;
    int current = low;

    /* Iterate through helper array. Compare the left and right half, copying back
     * the smaller element from the two halves into the original array. */
    while (helperleft <= middle && helperRight <= high)
    {
        if (helper[helperleft] <= helper[helperRight])
        {
            array[current] = helper[helperleft];
            helperleft++;
        }
        else
        { //If right element is smaller than left element
            array[current] = helper[helperRight];
            helperRight++;
        }
    }

    current++;
    /* Copy the rest of the left side of the array into the target array*/
    int remaining = middle - helperleft;
    for (int i = 0; i <= remaining; i++)
    {
        array[current + i] = helper[helperleft + i];
    }
}

void quickSort(std::vector<int> arr, int left, int right)
{
    int index = partition(arr, left, right);
    if (left < index - 1)
    { // Sort left half
        quickSort(arr, left, index - 1);
    }
    if (index < right)
    { // Sort right half
        quickSort(arr, index, right);
    }
}

int partition(std::vector<int> arr, int left, int right)
{
    int pivot = arr[(left + right) / 2]; // Pick pivot point
    while (left <= right)
    {
        // Find element on left that should be on right
        while (arr[left] < pivot)
        {
            left++;
        }

        // Find element on right that should be on left
        while (arr[right] > pivot)
        {
            right--;
        }

        // Swap elements, and move left and right indices
        if (left <= right)
        {
            swap(arr, left, right); // swaps elements
            left++;
            right--;
        }
    }
    return left;
}

int binarySearch(std::vector<int> a, int x)
{
    int low = 0;
    int high = a.size() - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] < x)
        {
            low = mid + 1;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1; // Error
}

int binarySearchRecursive(std::vector<int> a, int x, int low, int high)
{
    if (low > high)
    {
        return -1; // Error
    }

    int mid = (low + high) / 2;
    if (a[mid] < x)
    {
        return binarySearchRecursive(a, x, mid + 1, high);
    }
    else if (a[mid] > x)
    {
        return binarySearchRecursive(a, x, low, mid - 1);
    }
    else
    {
        return mid;
    }
}

void sortValleyPeak(std::vector<int> array)
{
    std::sort(array.begin(), array.end());
    for (int i = 1; i < array.size(); i += 2)
    {
        swap(array, i - 1, i);
    }
}

void swap(std::vector<int> array, int left, int right)
{
    int temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}