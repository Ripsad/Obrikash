def greatestNumber(array):
    i = array[0]
    for j in array:
        if(j > i):
            i = j
    return i

array = [15,11,13,159,91,159,98]
print(greatestNumber(array))