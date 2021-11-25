import sys

cnt = 0
n, m = map(int, sys.stdin.readline().split())   # n개의 노드와 m개의 vertex
adj = [set() for _ in range(n+1)]   # 0부터 m까지 m+1개의 집합 리스트
for i in range(m):
    u, v = map(int, sys.stdin.readline().split())   # vertex의 점 u, v를 입력받음
    adj[u].add(v) if u < v else adj[v].add(u)   # u번째 집합에 v를 추가하되 u < v를 만족시킴
print(adj)
for set in adj: # 인접 리스트의 각각의 집합에 대하여
    for i in set:   # 집합 내 모든 원소에 대하여
        cnt += len(set.intersection(adj[i]))    # 각 집합의 원소의 교집합을 구해서 카운트

print(cnt)
