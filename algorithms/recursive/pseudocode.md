Function kth(arr1, start1, arr2, start2, k):

    If start1 >= length of arr1:
        Return arr2[start2 + k - 1]

    If start2 >= length of arr2:
        Return arr1[start1 + k - 1]

    If k == 1:
        Return min(arr1[start1], arr2[start2])

    mid1 = value at arr1[start1 + k/2 - 1] (or infinity if out of bounds)
    mid2 = value at arr2[start2 + k/2 - 1] (or infinity if out of bounds)

    If mid1 < mid2:
        Ignore first k/2 elements of arr1
        Recurse with (start1 + k/2, start2, k - k/2)
    Else:
        Ignore first k/2 elements of arr2
        Recurse with (start1, start2 + k/2, k - k/2)
