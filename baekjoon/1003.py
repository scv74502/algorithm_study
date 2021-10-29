import sys


def fibo(n):
    dp = [[1, 0], [0, 1]]
    if n == 0:
        return dp[0]
    elif n == 1:
        return dp[1]
    else:
        for i in range(2, n+1):
            if len(dp) < i:
                dp[i] = [x + y for x, y in zip(dp[i-2], dp[i-1])]
            else:
                dp.append([x + y for x, y in zip(dp[i-2], dp[i-1])])
    return dp[n]

t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    a, b = fibo(n)
    print("{} {}".format(a, b))
