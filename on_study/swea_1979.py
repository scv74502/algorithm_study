import sys

def sol(arr:list, k:int):
    ans = 0
    for ele in arr:
        tmp = ''.join(ele).split('0')
        ans += len(list(filter(lambda x:len(x) == 3,tmp)))
    return ans

rpt = int(sys.stdin.readline())

for _ in range(rpt):
    n, k = map(int, sys.stdin.readline().split())
    arr = [list(map(str, sys.stdin.readline().split())) for _ in range(n)]
    ans = sol(arr, k)
    ans += sol(list(zip(*arr)), k)
    print(f"#{_+1} {ans}")




""""
# 표준 input으로 변경한 코드

def sol(arr:list, k:int):
    ans = 0
    for ele in arr:
        tmp = ''.join(ele).split('0')
        ans += len(list(filter(lambda x:len(x) == 3,tmp)))
    return ans

rpt = int(input())

for _ in range(rpt):
    n, k = map(int, input().split())
    arr = [list(map(str, input().split())) for _ in range(n)]
    ans = sol(arr, k)
    ans += sol(list(zip(*arr)), k)
    print(f"#{_+1} {ans}")
"""