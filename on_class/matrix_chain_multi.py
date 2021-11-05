import sys

def mcm(p):
    n = len(p) - 1
    # create n*n size of m, n-1*n-1 size of s
    m = [[None for _ in range(n)] for _ in range(n)]
    s = [[None for _ in range(n-1)] for _ in range(n-1)]

    # i is 0 to n-1
    for i in range(0, n):
        m[i][i] = 0
    # l is 1 to n-1
    for l in range(1, n):
        for i in range(0, n - l):
            j = i + l
            m[i][j] = sys.maxsize
            for k in range(i, j):
                q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j])
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j-1] = k

    return m[0][n-1]



num = int(sys.stdin.readline())
p = [int(sys.stdin.readline()) for _ in range(num + 1)]
print(mcm(p))