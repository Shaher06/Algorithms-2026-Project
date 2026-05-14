#include <stdio.h>

void sortArray(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int kthElementMethod2(int arr1[], int m,
                      int arr2[], int n,
                      int k)
{
    int merged[m + n];

    int i = 0, j = 0, index = 0;

    // Merge both sorted arrays
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

    while (i < m)
    {
        merged[index] = arr1[i];
        i++;
        index++;
    }

    while (j < n)
    {
        merged[index] = arr2[j];
        j++;
        index++;
    }

    printf("\nMerged Sorted Array:\n");

    for(int x = 0; x < m + n; x++)
    {
        printf("%d ", merged[x]);
    }

    return merged[k - 1];
}

int main()
{
    int m, n, k;

    printf("Enter size of first array: ");
    scanf("%d", &m);

    int arr1[m];

    printf("Enter elements of first array:\n");

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n);

    int arr2[n];

    printf("Enter elements of second array:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    sortArray(arr1, m);
    sortArray(arr2, n);
    printf("\nFirst array after sorting:\n");

    for(int i = 0; i < m; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n\nSecond array after sorting:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }

    printf("\n\nEnter k: ");
    scanf("%d", &k);

    if(k < 1 || k > (m + n))
    {
        printf("Invalid k value!\n");
        return 0;
    }

    int result = kthElementMethod2(arr1, m,arr2, n,k);

    printf("\n\nThe %d-th element is: %d\n", k, result);

    return 0;
}
