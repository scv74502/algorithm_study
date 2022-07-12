import sys


plans = ["100 1 3", "500 4", "2000 5"]
clients = ["300 3 5", "1500 1", "100 1 3", "50 1 2"]
def solution(n, plans, clients):
    answer = []
    plans = [list(map(int, plan.split())) for plan in plans]
    for i in range(0, len(plans)-1):
        plans[i+1].extend(plans[i][1:])
    clients = [list(map(int, client.split())) for client in clients]

    for i in range(0, len(clients)):
        datas = list(filter(lambda x:x[0] > clients[i][0], plans))
        service = list(filter(lambda x:set(x[1:]) < set(clients[i][1:]) ,datas))
        if len(service) == 0:
            answer.append(0)
            continue
        else:
            answer.append(plans.index(service[0])+1)


    return answer

print(solution(5, plans, clients))



















