# http://www.geeksforgeeks.org/print-left-rotation-array/

# Given an array of size n and multiple values around which we need to left rotate the array.
# How to quickly print multiple left rotations?


def rotateArray(arr, num):
    arrLen = len(arr)
    mod = num % arrLen
    tempArr = []
    for x in range(mod, mod + arrLen):
        tempArr.append(arr[x % arrLen])
    return tempArr


def solution(arr, rotate):
    for rotCount in rotate:
        print('Rotating ' + str(rotCount) + ' times -->', rotateArray(arr, rotCount))


if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9]
    rotate = [1, 3, 4, 6, 14]
    solution(arr, rotate)
