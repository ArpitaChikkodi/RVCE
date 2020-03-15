def bin_search(a,low,high):
    pos = -1
    found = false
    while(low<=high and not found):
        mid = (low+high)/2
        if(key==a[mid]):
            pos = mid + 1
            found = true
        elif key < a[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return pos
