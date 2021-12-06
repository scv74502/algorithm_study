import sys
global DFA

def strToint(text):
    return ord(text) - 65

def construtDFA(text, pattern, DFA):
    i, j, txtLength, patLength = 0, 0, 0, 0
    txtLength = len(text)
    patLength = len(pattern)
    x = 0

    DFA[strToint(pattern[0])][0] = 1
    for j in range(1, patLength):
        for c in range(0, 3):
            DFA[c][j] = DFA[c][x]

        DFA[pattern[j]][j] = j+1
        x = DFA[pattern[j]][x]



def DFAmatching(text, pattern):
    i, j, txtLength, patLength = 0, 0, 0, 0
    txtLength = len(text)
    patLength = len(pattern)
    while(i <= txtLength and j < patLength):
        j = DFA[strToint(text[i])][j]
        if(j == patLength):
            return i - patLength
        else:
            return -1

        i += 1



if __name__ == '__main__':
    rpt = int(sys.stdin.readline())
    for _ in range(rpt):
        DFA = [[0 for col in range(1000)] for row in range(1000)]
        pattern, text = map(str, sys.stdin.readline().split())
        cnt, DFA = construtDFA(pattern, text, DFA)
        result = DFAmatching(pattern, text, DFA)
        print("{} {}".format(cnt, result))
