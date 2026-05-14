```c
int kthElement(int arr1[], int m, int arr2[], int n, int k)
{
    int arr3[m+n];

    int i = 0, j = 0, index = 0;

    while(i < m && j < n)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[index] = arr1[i];
            i++;
        }
        else
        {
            arr3[index] = arr2[j];
            j++;
        }

        index++;
    }

    while(i < m)
    {
        arr3[index] = arr1[i];
        i++;
        index++;
    }

    while(j < n)
    {
        arr3[index] = arr2[j];
        j++;
        index++;
    }

    return arr3[k - 1];
}
```

## Time Complexity

```text
O(m + n)
```
