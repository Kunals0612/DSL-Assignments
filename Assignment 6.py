def quicksort(array):
    if(len(array)<=1):
        return array
    else:
        n = len(array)
        pivot = array.pop()
        greater = []
        lesser = []
        for i in array:
            if(i>=pivot):
                greater.append(i)
            else:
                lesser.append(i)
    return quicksort(lesser)+ [pivot] + quicksort(greater)
print(quicksort([10,30,20,50,40]))