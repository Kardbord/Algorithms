#!/bin/python

def sortSelection(A, k):
    """
    Selects the @k-th smallest number from @A in O(nlogn) time by sorting
    and returning A[k]
    
    Note that indexing begins at 0, so
    call selection(A, 0) to get the smallest number in the list,
    call selection(A, len(A) / 2) to get the median number of the list,
    call selection(A, len(A) - 1) to get the largest number of the list
    
    param A: an unsorted list
    param k: the k-th smallest number of @A to find
    return : the k-th smallest number of @A, or None
    """
    if not A or k < 0 or k >= len(A):
        return None
    B = A[:]
    B.sort()
    return B[k]

def pickPivot(A):
    """
    Picks a pivot by arbitrarily partitioning @A into groups of 5,
    finding the median of each group, and selecting the median of those
    medians as a pivot
    
    param A: an unsorted list
    return : the pivot
    """
    i = 0
    j = 5
    B = []
    for _ in range((len(A) / j) + 1):
        B.append(selection(A[i:j], len(A[i:j]) / 2))
        i += 5
        j += 5
    return selection(B, len(B) / 2)

def selection(A, k):
    """
    Selects the @k-th smallest number from @A in O(n) time
    
    Note that indexing begins at 0, so
    call selection(A, 0) to get the smallest number in the list,
    call selection(A, len(A) / 2) to get the median number of the list,
    call selection(A, len(A) - 1) to get the largest number of the list
    
    param A            : an unsorted list
    param k            : the k-th smallest number of @A to find
    return             : the k-th smallest number of @A, or None
    """
    if not A or k < 0 or k > len(A):
        return None
    if len(A) <= 100:
            return sortSelection(A, k)

    pivot = pickPivot(A)

    A_1 = []
    A_2 = []
    A_3 = []
    for item in A:
        if item < pivot:
            A_1.append(item) # A_1 = items of @A less than pivot
        elif item > pivot:
            A_2.append(item) # A_2 = items of @A greater than pivot
        else:
            A_2.append(item) # items of @A equal to pivot

    i = len(A_1)
    j = len(A_3)
    if i < k <= (i + j):
        return pivot
    if k <= i:
        return selection(A_1, k)
    if k > (i + j):
        return selection(A_2, k - i - j)

