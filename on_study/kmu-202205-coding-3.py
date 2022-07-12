"""
3. 비상 연락망
그래프가 주어저지고 각 그래프에서 누구에게 비상 연락을 취해야 가장 많ㅇ느 사람에게 재난 상황을 알릴 수 있는자, 연락받는 사람의 수는 몇 명인지 계산하기
비상연락망은 n명이 있으며 0부터 n-1번까지 고유 번호를 갖는다.
1초동안 자신과 인접한 비상연락망 인원에게 전파가 됨.
처음에 쿠민이가 비상연락망에게 있는 단 한 사람에게 재난 상황을 알릴 수 있고 쿠민이의 최초 연락은 시간이 걸리지 않는다.
입력으로 첫 줄에 비상 연락망에 포함한 사람의 수와 지진이 몇 초 뒤에 발생하는지를 나타내는 시간이 공백으로 구분되어 주어짐
두 번째 줄부터 n-1의 줄에 걸쳐서 각 줄마다 서로 연락하기로 한 두 사람의 고유번호가 공백으로 구분되어 주어짐

bfs를 통해서 해답을 찾기, python의 deque(데크) 객체를를 이용하기
"""

import sys
from collections import deque


# t는 몇 초 후에 지진이 발생하는지 시간
def bfs(u, graph, t):

    # 방문했던 노드를 집합으로 추가한다
    visited = set()

    # deque(데크) - 양방향 큐
    q = deque()

    # 오른쪽에 넣는다, 노드와 연락받았을 시에 시간
    q.append((u, t))

    while len(q) != 0:
        # 오른쪽으로 넣고 왼쪽에서 뺀다
        v, vt = q.popleft()
        visited.add(v)
        if vt > 0:
            for w in graph[v]:
                if w not in visited:
                    q.append((w, vt-1))

    return len(visited)


# n이 노드 수, t는 시간
n, t = map(int, sys.stdin.readline().split())
# n * n 형태의 그래프
graph = [[] for _ in range(n)]

"""
graph는 다음과 모양이 같다
[[1], 0번 이웃
 [0, 2, 3], 1번 이웃
 [1], 2번 이웃
....
 [], n번 이웃
]
"""

for line in sys.stdin:
    u, v = map(int, line.split())
    graph[u].append(v)
    graph[v].append(u)

# 방문하는 edge마다 탐색을 수행해야 하기 때문에 시간 복잡도가 커진다
# 노드를 방문하는 과정에서 중복되는 부분이 있음
ans = max(bfs(u, graph, t) for u in range(n))
print(ans)

"""
시간을 줄이기 위하여 다이나믹 프로그래밍을 사용하는 방법이 있음
시간을 0부터 1까지 증가시키며 패턴을 파악하기

노드 u에서 x만큼 시간이 있을 때에 비상 연락이 가능한 사람의 수를 X(u, x)라 한다면

ans = 0
for v in n(u):
    #첫 연락 다음 연락시 노드 수
    ans += x(v, t-1)

# 겹치는 수 * 이웃의 수를 곱함
ans -= x(u, t, 2)
"""


















