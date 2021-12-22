import sys

# 3
# 21 Junkyu
# 21 Dohyun
# 20 Sunyoung

rpt = int(sys.stdin.readline())
li = []
for _ in range(rpt):
    age, name = sys.stdin.readline().split()
    li.append([int(age), name])

li.sort(key=lambda x:(x[0]))
for info in li:
    print("{} {}".format(info[0], info[1]))