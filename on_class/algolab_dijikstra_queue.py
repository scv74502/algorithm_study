import heapq
import sys

def solution(graph, n):
    # init graph
    # graph = [[] for _ in range(N + 1)]
    # for ele in road:
        # graph[ele[0]].append((ele[1], ele[2]))
        # graph[ele[1]].append((ele[0], ele[2]))
    distance = [[999999] * (len(graph)) for _ in range(len(graph))]
    for cur in range(1, n+1):
        q = []
        heapq.heappush(q, (0, cur))
        distance[cur][cur] = 0
        while q:
            dist, now = heapq.heappop(q)
            if distance[cur][now] < dist:
                continue
            for i in graph[now]:
                cost = dist + i[1]
                if cost < distance[cur][i[0]]:
                    distance[cur][i[0]] = cost
                    heapq.heappush(q, (cost, i[0]))

    result = 0
    visited = []
    for ele in distance:
        ele.remove(min(ele))
        if min(ele) != 999999:
            result += min(ele)
            visited.append(distance.index(min(ele)))
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

