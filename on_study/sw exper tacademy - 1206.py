import sys

# 제출 시에는 sys 대신 input 사용함
for sec in range(10):
    cnt = 0
    num = int(sys.stdin.readline())
    buildings = list(map(int, sys.stdin.readline().split()))
    for i in range(2, len(buildings)-2):
        if max(buildings[i-2], buildings[i-1], buildings[i], buildings[i+1], buildings[i+2]) == buildings[i]:
            cnt += (buildings[i] - max(buildings[i-2], buildings[i-1], buildings[i+1], buildings[i+2]))
    print(f"#{sec + 1} {cnt}")

