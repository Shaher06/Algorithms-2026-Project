FUNCTION kthElement(arr1, m, arr2, n, k)
    Declare arr3 as an array of size m+n
    Declare i = 0, j = 0, index = 0

    WHILE i < m AND j < n DO
        IF arr1[i] < arr2[j] THEN
            arr3[index] <-- arr1[i]
            i <-- i + 1
        ELSE
            arr3[index] <-- arr2[j]
            j <-- j + 1
        END IF
        index <-- index + 1
    END WHILE

    WHILE i < m DO
        arr3[index] <-- arr1[i]
        i <-- i + 1
        index <-- index + 1
    END WHILE

    WHILE j < n DO
        arr3[index] <-- arr2[j]
        j <-- j + 1
        index <-- index + 1
    END WHILE


MAIN PROGRAM
    DECLARE m, n, k

    PRINT "Enter size of first array: "
    READ m
    DECLARE arr1 of size m

    PRINT "Enter elements of first sorted array:"
    FOR i FROM 0 TO m-1 DO
        READ arr1[i]
    END FOR

    PRINT "Enter size of second array: "
    READ n
    DECLARE arr2 of size n

    PRINT "Enter elements of second sorted array:"
    FOR i FROM 0 TO n-1 DO
        READ arr2[i]
    END FOR

    PRINT "Enter k: "
    READ k

    IF k < 1 OR k > (m + n) THEN
        PRINT "Invalid k value!"
        RETURN
    END IF

    result = kthElement(arr1, m, arr2, n, k)

    PRINT "The ", k, "-th element is: " + result
END MAIN
