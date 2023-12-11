def partition(low, arr, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[high], arr[i + 1] = arr[i + 1], arr[high]
    return i + 1

def quick_sort(low, arr, high):
    if low < high:
        pivot = partition(low, arr, high)
        quick_sort(low, arr, pivot - 1)
        quick_sort(pivot + 1, arr, high)

no = [29, 10, 14, 37, 13]
quick_sort(0, no, len(no) - 1)
print(no)
