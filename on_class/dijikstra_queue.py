import heapq
import sys

def solution(N, road, K):
    # init graph
    graph = [[] for _ in range(N + 1)]
    for ele in road:
        graph[ele[0]].append((ele[1], ele[2]))
        graph[ele[1]].append((ele[0], ele[2]))
    print(graph)
    distance = [99999999] * (N + 1)
    q = []
    heapq.heappush(q, (0, 1))
    distance[1] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    print(distance)
    return len(list(filter(lambda x: x <= K, distance)))