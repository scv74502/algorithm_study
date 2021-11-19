import heapq
import sys

def solution(N, road, start):
    # init graph
    graph = [[] for _ in range(N + 1)]
    for ele in road:
        graph[ele[0]].append((ele[1], ele[2]))
    distance = [sys.maxsize] * (N + 1)
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[start]
            if cost < distance[i[0]] and distance:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


    return distance[1:]

if __name__ == "__main__":
    v, e = map(int, sys.stdin.readline().split())
    start = int(sys.stdin.readline())
    road = []
    for _ in range(e):
        a, b, w = map(int, sys.stdin.readline().split())
        road.append([a, b, w])
    answer = solution(len(road), road, start)
    for ele in answer:
        if ele == sys.maxsize:
            print('INF')
        else:
            print(ele)

