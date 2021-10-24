import sys

def generator(num):
    summary = sum(int(ch) for ch in str(num))
    return summary + num

genli = []

number = int(sys.stdin.readline())

for i in range(number//2, number):
    if generator(i) == number:
        genli.append([i, generator(i)])

if len(genli) == 0:
    print("0")
else:
    print(genli[0][0])
