FUNCTION max(a, b)
    IF a > b THEN
        RETURN a
    ELSE
        RETURN b

FUNCTION min(a, b)
    IF a < b THEN
        RETURN a
    ELSE
        RETURN b

FUNCTION kthElement(arr1, arr2, m, n, k)
    IF k < 1 OR k > (m + n) THEN
        RETURN -1  
    IF m > n THEN
        RETURN kthElement(arr2, arr1, n, m, k)
Declare high ,low  , cut1,cut2
    low  <-- max(0, k - n)
    high <-- min(k, m)

    WHILE low <= high DO
        cut1 <-- low + (high - low) 
        cut2 <-- k - cut1
              
        IF cut1 == 0 THEN
            l1 <-- -infinity
        ELSE
            l1 <-- arr1[cut1 - 1]

        IF cut2 == 0 THEN
            l2 <-- -infinity
        ELSE
            l2 <-- arr2[cut2 - 1]

        IF cut1 == m THEN
            r1 <-- +infinity
        ELSE
            r1 <-- arr1[cut1]

        IF cut2 == n THEN
            r2 <-- +infinity
        ELSE
            r2 <-- arr2[cut2]

        IF l1 <= r2 AND l2 <= r1 THEN
            RETURN max(l1, l2)
        ELSE IF l1 > r2 THEN
            high = cut1 - 1
        ELSE
            low = cut1 + 1
    END WHILE

    RETURN -1
MAIN PROGRAM
    DECLARE m, n, k

    PRINT "Enter size of first array: "
    READ m
    DECLARE arr1 of size m

    PRINT "Enter elements of first array in sorted order:"
    FOR i FROM 0 TO m-1 DO
        READ arr1[i]
    END FOR

    PRINT "Enter size of second array: "
    READ n
    DECLARE arr2 of size n

    PRINT "Enter elements of second array in sorted order:"
    FOR i FROM 0 TO n-1 DO
        READ arr2[i]
    END FOR

    PRINT "Enter k: "
    READ k

    result <-- kthElement(arr1, arr2, m, n, k)

    IF result == -1 THEN
        PRINT "Invalid k value!"
    ELSE
        PRINT "The ", k, "-th element is: " + result
