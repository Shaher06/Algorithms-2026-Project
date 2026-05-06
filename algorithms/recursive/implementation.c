#include <stdio.h>
#include <limits.h>

int kth(int* arr1, int start1, int len1,
        int* arr2, int start2, int len2, int k) {

    if (start1 >= len1)
        return arr2[start2 + k - 1];

    if (start2 >= len2)
        return arr1[start1 + k - 1];

    if (k == 1)
        return (arr1[start1] < arr2[start2]) ? arr1[start1] : arr2[start2];

    
    int half = k / 2;  

    int mid1 = (start1 + half - 1 < len1) ? arr1[start1 + half - 1] : INT_MAX;
    int mid2 = (start2 + half - 1 < len2) ? arr2[start2 + half - 1] : INT_MAX;

    if (mid1 < mid2)
        return kth(arr1, start1 + half, len1, arr2, start2, len2, k - half);
    else
        return kth(arr1, start1, len1, arr2, start2 + half, len2, k - half);
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int len1 = 4, len2 = 4;
    int k = 5;

    printf("The %dth element is: %d\n", k, kth(arr1, 0, len1, arr2, 0, len2, k));
    return 0;
}
