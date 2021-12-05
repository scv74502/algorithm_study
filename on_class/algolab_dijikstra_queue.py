import heapq
import sys

def solution(graph, N):
    result = []
    for i in range(1, N+1):
        distance = [99999999] * (N + 1)
        q = []
        heapq.heappush(q, (0, i))
        distance[i] = 0
        while q:
            dist, now = heapq.heappop(q)
            if distance[now] < dist:
                continue
            for i in graph[now]:
                cost = dist + i[1]
                if cost < distance[i[0]]:
                    distance[i[0]] = cost
                    heapq.heappush(q, (cost, i[0]))

        if
            distance.remove(0)
        result.append(min(distance))

    return result

if __name__ == '__main__':
    rpt = int(sys.stdin.readline()) # time to repeat
    for _ in range(rpt):
        n = int(sys.stdin.readline()) # number of node
        graph = [[] for _ in range(n + 1)]
        for _ in range(n):
            adj = list(map(int, sys.stdin.readline().split()))
            node = adj[0]   # number of current line node
            vernum = adj[1] # number of vertexes
            adj = adj[2:]   # data is [2:]
            for i in range(0, vernum * 2, 2):
                graph[node].append((adj[i], adj[i+1]))
        print(solution(graph,n))


