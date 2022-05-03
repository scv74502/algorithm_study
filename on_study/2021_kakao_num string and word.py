import sys

def solution(s):
    #table = {'zero' : '0', 'one' : '1', 'two' : '2', 'three' : '3', 'four' : '4', 'five' : '5', 'six' : '6', 'seven' : '7', 'eight' : '8', 'nine' : '9'}
    table = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    idx = 0
    answer = ''
    word = ''

    for c in s:
        if c.isdigit():
            answer += c
        else:
            word += c
            if word in table:
                answer += str(table.index(word))
                word = ''

    return int(answer)

ipt = sys.stdin.readline().strip()
test1 = "one4seveneight"
print(solution(test1))