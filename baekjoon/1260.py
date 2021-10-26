import sys
import queue

def bfs(graph, start):
    visited = []

    tovisit = queue.Queue()
    tovisit.put(start)

    while not tovisit.empty():
        u = tovisit.get()
        if u in visited: continue

        visited.append(u)
        # print("visited : ", u)

        if u in graph:
            for v in graph[u]:
                if v not in visited:
                    tovisit.put(v)

    return visited

def dfs(graph, start):
    need_visit, visited = [start], []

    while need_visit:
        node = need_visit.pop()
        if node not in visited:
            visited.append(node)
            if node in graph:
                need_visit.extend(graph[node][::-1])

    # visited[1:] = visited[1:][::-1]
    return visited

n, m, v = map(int, sys.stdin.readline().split())
graph = {}
for _ in range(m):
    u, k = map(int, sys.stdin.readline().split())
    if u not in graph:
        graph[u] = []
    if k not in graph:
        graph[k] = []

    graph[u].append(k)
    graph[k].append(u)
graph_bfs = sorted(graph.items(), key=lambda x : x[0])
for ele in graph_bfs:
    ele[1].sort()

graph_bfs = dict(graph_bfs)
bfs = bfs(graph_bfs, v)
dfs = dfs(graph, v)
for num in dfs:
    print(num, end=' ')
print()
for num in bfs:
    print(num, end=' ')