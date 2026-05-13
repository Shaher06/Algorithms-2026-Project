#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;

int min(int a, int b) {
    return (a < b) ? a : b; +
}

int kthElement(int arr1[], int arr2[], int m, int n, int k) {
        if (k < 1 || k > (m + n)) { 
        return -1; 
    }

    if (m > n) {
        return kthElement(arr2, arr1, n, m, k); 
    }

    int low = max(0, k - n); 
    int high = min(k, m);

    while (low <= high) {
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];

        int r1 = (cut1 == m) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == n) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1;
        }
    }

    return -1;
}


int main() {

    int m, n, k;

    printf("Enter size of first array: ");
    scanf("%d", &m);

    int arr1[m];

    printf("Enter elements of first array in sorted order:\n");

    for(int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n);

    int arr2[n];

    printf("Enter elements of second array in sorted order:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = kthElement(arr1, arr2, m, n, k);

    if(result == -1) {
        printf("Invalid k value!\n");
    }
    else {
        printf("The %d-th element is: %d\n", k, result);
    }

    return 0;
}
