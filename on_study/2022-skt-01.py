import sys

p = list(map(int, sys.stdin.readline().split()))
p1 = [2 ,5, 3, 1, 4]
p2 = [2, 3, 4, 5, 6, 1]

def solution(p:list):
    answer = [0 for _ in range(len(p))]
    i = 0
    while(True):
        minp = min(p[i:])
        j = p.index(minp)
        if i != j:
            p[i], p[j] = p[j], p[i]
            answer[i] += 1
            answer[j] += 1
        i += 1
        if i == len(p):
            break

    return answer

print(solution(p2))