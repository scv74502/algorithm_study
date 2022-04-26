import sys

n = int(sys.stdin.readline())
points = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
points.sort(key=lambda x: (x[1], x[0]))

for point in points:
    print(f"{point[0]} {point[1]}")
