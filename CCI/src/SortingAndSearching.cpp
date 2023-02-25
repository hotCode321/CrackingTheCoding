#include "SortingAndSearching.cpp"

void mergesort(std::vector<int> array)
{
    auto helper = std::vector<int>(array.size());
    mergesort(array, helper, 0, array.length - 1);
}

void mergesort(std::vector<int> array, std::vector<int> helper, int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;
        mergesort(array, helper, low, middle);      // Sort left half
        mergesort(array, helper, middle + l, high); // Sort right half
        merge(array, helper, low, middle, high);    // Merge them
    }
}

void merge(std::vector<int> array, std::vector<int> helper, int low, int middle, int high)
{
    /* Copy both halves into a helper array*/
    for (int i = low; i <= high; i++)
    {
        helper[i] = array[i];
    }

    int helperleft = low;
    int helperRight = middle + 1;
    int current = low;

    /* Iterate through helper array. Compare the left and right half, copying back
    * the smaller element from the two halves into the original array. */
    while (helperLeft <= middle && helperRight <= high)
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
        current++;
    }

    /* Copy the rest of the left side of the array into the target array*/
    int remaining = middle - helperleft;
    for (int i = 0; i <= remaining; i++)
    {
        array[current + i] = helper[helperleft + i];
    }
}