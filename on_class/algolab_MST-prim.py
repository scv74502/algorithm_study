import heapq
import sys
import collections

def mst_prim(graph, n):
    visited = [0] * (n + 1)
    visited[1] = 1  # start to 1, check visited
    candidate = graph[1]
    heapq.heapify(candidate)
    mst = []
    total_weight = 0

    while candidate:
        weight, u, v = heapq.heappop(candidate)

        if visited[v] == 0:
            visited[v] = 1
            mst.append((u, v))
            total_weight += weight

            if len(candidate) == n-1:
                break

            for edge in graph[v]:
                if visited[edge[2]] == 0:
                    heapq.heappush(candidate, edge)

    return total_weight

if __name__ == '__main__':
    rpt = int(sys.stdin.readline()) # time to repeat
    for _ in range(rpt):
        n = int(sys.stdin.readline()) # number of node
        graph = [[] for _ in range(n+1)]
        for _ in range(n):
            adj = list(map(int, sys.stdin.readline().split()))
            node = adj.pop(0)   # number of current line node
            vernum = adj.pop(0) # number of vertexes
            for i in range(0, vernum * 2, 2):
                graph[node].append([adj[i+1], node, adj[i]])
                graph[adj[i]].append([adj[i+1], adj[i], node])

        print(mst_prim(graph, node))