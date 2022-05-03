import sys
import math

n = int(sys.stdin.readline())
for i in range(n):
    garden, cooler = map(int, sys.stdin.readline().split())
    print(f"#{i+1} {math.ceil(garden / (cooler * 2 + 1))}")

# 제출본은 표준 입출력 제한으로 input 사용함
# import math
#
# n = int(input())
# for i in range(n):
    # garden, cooler = map(int, input().split())
    # print(f"#{i+1} {math.ceil(garden / (cooler * 2 + 1))}")

