import sys

rpt = int(sys.stdin.readline())

for _ in range(rpt):
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    max = 0

    if n >= m:
        for i in range(n - m + 1):
            ans = 0
            for j in range(m):
                ans += a[j + i] * b[j]
            if ans > max:
                max = ans
    else:
        for i in range(m - n + 1):
            ans = 0
            for j in range(n):
                ans += a[j] * b[j+i]
            if ans > max:
                max = ans

    print(f"#{_+1} {max}")

"""
# input()을 사용한 표준 입력
rpt = int(input())

for _ in range(rpt):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    max = 0

    if n >= m:
        for i in range(n - m + 1):
            ans = 0
            for j in range(m):
                ans += a[j + i] * b[j]
            if ans > max:
                max = ans
    else:
        for i in range(m - n + 1):
            ans = 0
            for j in range(n):
                ans += a[j] * b[j+i]
            if ans > max:
                max = ans

    print(f"#{_+1} {max}")

"""
