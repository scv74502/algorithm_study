import sys


def solution(wlen, wcut):
    cut = len(wcut)
    cnt = 0

    lvec = []
    for i in range(cut):
        lvec.append(wcut[i] - cnt)
        cnt = wcut[i]
    lvec.append(wlen - wcut[cut-1])

    dp = [[0 for i in range(1020)] for j in range(1020)]
    sum = [0 for i in range(1020)]

    for i in range(0, len(lvec)):
        sum[i + 1] = sum[i] + lvec[i]

    for i in range(1, len(lvec) + 1):
        for j in range(1, len(lvec) + 1):
            dp[j][i+j] = 99999999999
            for k in range(j, i + j):
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1])

    return dp[1][len(lvec)]

if __name__ == '__main__':
    rpt = int(sys.stdin.readline())
    for _ in range(rpt):
        wlen, cut = map(int, sys.stdin.readline().split())
        wcut = list(map(int, sys.stdin.readline().split()))
        print(solution(wlen, wcut))