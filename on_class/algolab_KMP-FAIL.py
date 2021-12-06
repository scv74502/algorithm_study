import sys

def kmp_fail(patt, text):
    result = []

if __name__ == '__main__':
    rpt = int(sys.stdin.readline())
    for _ in range(rpt):
        patt, text = map(str, sys.stdin.readline().split())
        print(patt, text)