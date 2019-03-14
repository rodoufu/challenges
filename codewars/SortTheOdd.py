def sort_array(source_array):
    odds = []
    for x in source_array:
        if x % 2 == 1:
            odds.append(x)
    odds = sorted(odds)
    index = 0
    lens = len(source_array)
    for i in range(len(source_array)):
        if source_array[i] % 2 == 1:
            source_array[i] = odds[index]
            index += 1
    # print(" ".join([str(x) for x in source_array]))
    return source_array
    
