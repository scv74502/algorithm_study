import sys

num = int(sys.stdin.readline())
d = [0] * (num+1)
print(d)

for i in range(2, num+1):
    d[i] = d[i-1] + 1
    if i % 3 == 0:
        d[i] = min(d[i], d[i//3] + 1)
    if i % 2 == 0:
        d[i] = min(d[i], d[i//2] + 1)

print(d[num])

