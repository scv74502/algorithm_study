import sys

n, k = map(int, sys.stdin.readline().split())
things = []
dp = [[0 for k in range(k)] for n in range (n)]
for _ in range(n):
    wei, val = map(int, sys.stdin.readline().split())
    things.append([wei, val])

print(dp)

for i in range(0, n):
    weight = things[i][0]
    value = things[i][1]
    for j in range(k):
        if(j < things[i][0]):
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value)

print(dp)