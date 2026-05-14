#include <stdio.h>

// Function to find k-th element after merging
int kthElementMethod2(int arr1[], int m,
                      int arr2[], int n,
                      int k)
{
    int merged[m + n];

    int i = 0, j = 0, index = 0;

    // Merge both arrays
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            merged[index] = arr1[i];
            i++;
        }
        else
        {
            merged[index] = arr2[j];
            j++;
        }

        index++;
    }

    // Remaining elements of arr1
    while (i < m)
    {
        merged[index] = arr1[i];
        i++;
        index++;
    }

    // Remaining elements of arr2
    while (j < n)
    {
        merged[index] = arr2[j];
        j++;
        index++;
    }

    // Return k-th element
    return merged[k - 1];
}

int main()
{
    int m, n, k;

    // Input size of first array
    printf("Enter size of first array: ");
    scanf("%d", &m);

    int arr1[m];

    // Input first array elements
    printf("Enter elements of first sorted array:\n");

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }

    // Input size of second array
    printf("Enter size of second array: ");
    scanf("%d", &n);

    int arr2[n];

    // Input second array elements
    printf("Enter elements of second sorted array:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    // Input k
    printf("Enter k: ");
    scanf("%d", &k);

    // Validate k
    if(k < 1 || k > (m + n))
    {
        printf("Invalid k value!\n");
        return 0;
    }

    // Call function
    int result = kthElementMethod2(arr1, m,
                                   arr2, n,
                                   k);

    // Print result
    printf("The %d-th element is: %d\n", k, result);

    return 0;
}
