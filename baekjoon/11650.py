import sys

n = int(sys.stdin.readline())
# make list
points = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
points.sort(key=lambda x: (x[0], x[1]))

for point in points:
    print(f"{point[0]} {point[1]}")
