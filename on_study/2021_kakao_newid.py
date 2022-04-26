import sys
import re

def solution(new_id):
    new_id = new_id.lower()
    answer = ''

    for i in range(len(new_id)):
        if (new_id[i] >= 'a' and new_id[i] <= 'z') or (new_id[i] > '0' and new_id[i] <= '9') or (new_id[i] == '-' or new_id[i] == '.' or new_id[i] == '_'):
            answer += new_id[i]


    answer = re.sub('(([.])\\2{1,})', '.', answer)

    if len(answer) >= 1 and answer[0] == ".":
        answer = answer.lstrip(".")
    if len(answer) >= 1 and  answer[-1] == ".":
        answer = answer.rstrip(".")
    if len(answer) == 0:
        answer += "a"
    if len(answer) >= 16:
        answer = answer[:15]
        if answer[-1] == ".":
            answer = answer.rstrip(".")
    if len(answer) <= 2:
        answer += answer[-1] * (3 - len(answer))

    return answer

print(solution(sys.stdin.readline()))