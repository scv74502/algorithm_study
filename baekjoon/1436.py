import sys

"""
1. 1부터 10000까지 모든 수에 666이 들어가는 수만 남기고 sotring
2. 666에 prenum, postnum을 두고 붙이는 식으로(1666, 6661)
"""
n = int(sys.stdin.readline())

def solution(n):


##first method
# first = 666
# while n != 0:
    # if '666' in str(first):
        # n = n - 1
        # if n == 0:
            # break
    # first += 1
#
# print(first)

# secound method
if n > 1:
    solution(n)
else:
    print(666)
