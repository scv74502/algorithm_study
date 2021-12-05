import sys

def maketable(pattern):
    table = [0 for _ in range(len(pattern))]
    tSize = len(pattern)
    i, j = 1, 0
    while(i < tSize):
        while(j > 0 and pattern[i] != pattern[j]):
            j = table[j-1]
        if(pattern[i] == pattern[j]):
            j += 1
            table[i] = j
        i += 1

    return table

def KMP(pattern, text):
    table = maketable(pattern)
    textSize = len(text)
    patternSize = len(pattern)
    j = 0
    cnt = 0
    for i in range(0, textSize):
        while(j > 0 and text[i] != pattern[j]):
            j = table[j - 1]
        if(text[i] == pattern[j]):
            if(j == patternSize - 1):
                cnt += 1
                j = table[j]
            else:
                j += 1

    return cnt, table

if __name__ == '__main__':
    rpt = int(sys.stdin.readline())
    for _ in range(rpt):
        pattern, text = map(str, sys.stdin.readline().split())
        cnt, sol = KMP(pattern, text)
        sol = [str(_) for _ in sol]
        print(" ".join(sol))
        print(cnt)