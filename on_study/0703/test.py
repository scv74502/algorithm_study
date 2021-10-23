import sys

def partition(arr, l, h):
    pivot = arr[l]
    i = l
    j = h
    count = 0
    while i < j:
        while arr[i] <= pivot and i < h:
            i += 1
        while arr[j] >= pivot and j > l:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
    arr[l], arr[j] = arr[j], arr[l]
    return arr, j

def quicksort(arr, l, h):
    if l < h:
        arr, fix = partition(arr, l, h)
        quicksort(arr, l, fix-1)
        quicksort(arr, fix+1, h)

arr = [7, 3, 5, 6, 89, 1, 2, 8]
quicksort(arr, 0, len(arr)-1)
print(arr)




