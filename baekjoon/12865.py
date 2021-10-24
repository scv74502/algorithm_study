import sys

num, lim = map(int, sys.stdin.readline().split())
things = []

# 가방의 최대 무게 + 1 크기의 열(가로), 물건의 숫자만큼의 행
dp = [[0 for lim in range(lim+1)] for num in range(num)]
for _ in range(num):
    w, v = map(int, sys.stdin.readline().split())
    things.append([w, v])

# print(dp)

# 가방에 물건을 넣거나, 혹은 넣지 않거나
# DP[i][j]=max((DP[i][j-해당차례 물건 무게]+해당차례 물건 가치),DP[i-1][j]) (배낭에 해당차례 물건을 넣거나, 넣지 않거나)
for i in range(0, num):
    weight, value = things[i][0], things[i][1]
    for j in range(0, lim+1):
        if(j < things[i][0]): dp[i][j] = dp[i-1][j]
        else: dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight] + value)
print(dp[num-1][lim])