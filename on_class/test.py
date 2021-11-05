from queue import PriorityQueue
import heapq

def gcd(a, b):
    if (a == 0 or b == 0):
        return max(a, b)
    else:
        gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

def solution(arr):
    if len(arr) == 1:
        return arr[0]
    elif len(arr) >= 2:
        arr.sort()
        arr[1] = lcm(arr[0], arr[1])
        for i in range(1, len(arr)):
            arr[i] = lcm(arr[i-1], arr[i])
    return arr[len(arr)-1]