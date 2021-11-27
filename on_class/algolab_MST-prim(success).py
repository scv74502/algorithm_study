import sys

def mst_prim(weight, numOfNode):
    vnear, e, min = 0, 0, 0
    save = []
    nearest = [0] * (numOfNode + 1)
    distance = [0] * (numOfNode + 1)

    for i in range(2, numOfNode + 1):
        nearest[i] = 1
        distance[i] = weight[1][i]

    for _ in range(0, n-1):
        min = sys.maxsize
        for j in range(2, n+1):
            if 0 <= distance[j] and distance[j] < min:
                min = distance[j]
                vnear = j
        e = weight[vnear][nearest[vnear]]
        save.append(e)

        distance[vnear] = -1

        for j in range(2, n+1):
            if weight[j][vnear] < distance[j]:
                distance[j] = weight[j][vnear]
                nearest[j] = vnear

    return sum(save)

if __name__ == '__main__':
    rpt = int(sys.stdin.readline()) # time to repeat
    node, adjnum = 0, 0
    for _ in range(rpt):
        n = int(sys.stdin.readline()) # number of node
        weight = [[sys.maxsize for ar in range(n+1)] for _ in range(n+1)]
        for _ in range(n):
            adj = list(map(int, sys.stdin.readline().split()))
            node = adj.pop(0)   # number of current line node
            adjnum = adj.pop(0) # number of vertexes

            for i in range(0, adjnum * 2, 2):
                # node, adj[i], adj[i+1] = u, v, weight
                weight[node][adj[i]] = adj[i+1]
        for i in range(0, n+1):
            weight[i][i] = 0
        print(mst_prim(weight, n))