from collections import Counter
# import collections

def solution1(participant, completion):
    participant.sort()
    completion.sort()

    for p, c in zip(participant, completion):
        if p != c:
            return p
    print(participant[-1])
    return participant[-1]

def solution2(participant, completion):
    answer = Counter(participant) - Counter(completion)
    return list(answer.keys())[0]
    # answer = list(collections.Counter(participant) - collections.Counter(completion))
    # if len(answer) != 0:
        # return answer[0]
    # else:
        # participant.sort()
        # return participant[-1]

#test case
participants1 = ["leo", "kiki", "eden"]
participants2 = ["marina", "josipa", "nikola", "vinko", "filipa"]
participants3 = ["mislav", "stanko", "mislav", "ana"]
completion1 = ["eden", "kiki"]
completion2 = ["josipa", "filipa", "marina", "nikola"]
completion3 = ["stanko", "ana", "mislav"]

# print(solution1(participants1, completion1))
# print(solution1(participants2, completion2))
# print(solution1(participants3, completion3))

print(solution2(participants1, completion1))
print(solution2(participants2, completion2))
print(solution2(participants3, completion3))
