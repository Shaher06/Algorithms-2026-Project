#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int kth(int *arr1, int start1, int len1,
        int *arr2, int start2, int len2,
        int k)
{
    // arr1 ended
    if (start1 >= len1)
    {
        return arr2[start2 + k - 1];
    }

    // arr2 ended
    if (start2 >= len2)
    {
        return arr1[start1 + k - 1];
    }

    // smallest remaining element
    if (k == 1)
    {
        return (arr1[start1] < arr2[start2])
               ? arr1[start1]
               : arr2[start2];
    }

    int half = k / 2;

    int mid1 = (start1 + half - 1 < len1)
               ? arr1[start1 + half - 1]
               : INT_MAX;

    int mid2 = (start2 + half - 1 < len2)
               ? arr2[start2 + half - 1]
               : INT_MAX;

    if (mid1 < mid2)
    {
        return kth(arr1, start1 + half, len1,
                   arr2, start2, len2,
                   k - half);
    }
    else
    {
        return kth(arr1, start1, len1,
                   arr2, start2 + half, len2,
                   k - half);
    }
}

// Function to check if array is sorted
int isSorted(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int len1, len2, k;

    // Validate first array size
    printf("Enter size of first array: ");
    if (scanf("%d", &len1) != 1 || len1 <= 0)
    {
        printf("Invalid size for first array.\n");
        return 1;
    }

    int arr1[len1];

    printf("Enter elements of first array (sorted):\n");

    for (int i = 0; i < len1; i++)
    {
        if (scanf("%d", &arr1[i]) != 1)
        {
            printf("Invalid input in first array.\n");
            return 1;
        }
    }

    // Check if first array is sorted
    if (!isSorted(arr1, len1))
    {
        printf("First array is not sorted.\n");
        return 1;
    }

    // Validate second array size
    printf("Enter size of second array: ");
    if (scanf("%d", &len2) != 1 || len2 <= 0)
    {
        printf("Invalid size for second array.\n");
        return 1;
    }

    int arr2[len2];

    printf("Enter elements of second array (sorted):\n");

    for (int i = 0; i < len2; i++)
    {
        if (scanf("%d", &arr2[i]) != 1)
        {
            printf("Invalid input in second array.\n");
            return 1;
        }
    }

    // Check if second array is sorted
    if (!isSorted(arr2, len2))
    {
        printf("Second array is not sorted.\n");
        return 1;
    }

    // Validate k
    printf("Enter k: ");
    if (scanf("%d", &k) != 1)
    {
        printf("Invalid input for k.\n");
        return 1;
    }

    if (k < 1 || k > len1 + len2)
    {
        printf("Invalid k. It must be between 1 and %d\n", len1 + len2);
        return 1;
    }

    int result = kth(arr1, 0, len1,
                     arr2, 0, len2,
                     k);

    printf("The %dth smallest element is: %d\n", k, result);

    return 0;
}
