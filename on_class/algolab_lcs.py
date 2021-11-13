import sys

def lcs(a, b):
    width = len(a) + 1
    height = len(b) + 1
    dp = [['' for col in range(width)] for row in range(height)]

    for blen in range(1, height):
        for alen in range(1, width):
            if a[alen-1] == b[blen-1]:
                dp[blen][alen] = dp[blen -1][alen - 1] + a[alen - 1]
                continue
            a_lcs, b_lcs = dp[blen - 1][alen], dp[blen][alen - 1]
            if len(a_lcs) > len(b_lcs):
                dp[blen][alen] = a_lcs
            else:
                dp[blen][alen] = b_lcs

    return len(dp[blen][alen])

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    for _ in range (n):
        a, b = map(str, sys.stdin.readline().split())
        print(lcs(a, b))