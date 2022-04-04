import sys

def comp(li1, li2):
    if li1[0] > li2[0] and li1[1] > li2[1]:
        return True
    else:
        return False

n = int(sys.stdin.readline())
peoples = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
result = []

for i,p in enumerate(peoples):
    count = 0
    for j in range(n):
        if p[0] < peoples[j][0] and p[1] < peoples[j][1]:
            count += 1
    result.append(count+1)
for i in result:
    print(i,end=" ")