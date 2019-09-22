# Python Program for recursive binary search.
def binarySearchRecursive (arr, l, r, x): 
    if r >= l:
        mid = l + (r - l)//2    # double slash is floor division is py3+
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binarySearchRecursive(arr, l, mid-1, x)
        else:
            return binarySearchRecursive(arr, mid+1, r, x)
    else:
        return -1


# Iterative Binary Search Function.
def binarySearchIterative(arr, l, r, x):
    while l <= r:
        mid = int(l + (r - l)/2);
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return -1
 
# Test
arr = [ 2, 3, 4, 10, 40 ]
x = 10

# result = binarySearchRecursive(arr, 0, len(arr)-1, x)
result = binarySearchIterative(arr, 0, len(arr)-1, int(x))

if result != -1:
    print ("Element is present at index",result)
else:
    print ("Element is not present in array")