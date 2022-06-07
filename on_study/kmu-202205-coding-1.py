import sys


"""
1. 알람시계
미리 설정해둔 알람 시각으로 바로 설정하는 버튼이 5개 있음.
알람 시계는 24시간제를 사용하며 0시 0분에서 1분 감소 버튼을 누르면 23시 59분을 가리킴
반대로 1분 증가 버튼을 누르면 0시 0분이 됨

첫 줄에는 시험 시각의 시와 분이 공백으로 구분되어 주어짐
두 번째 줄에서 다섯 줄에 걸쳐 미리 설정해둔 알림 시각의 시와 분이 공백으로 주어짐
출력 값으로 첫 번째 줄에 시험 시각 10분 전으로 알람 시각ㅇ르 설저앻야 함

예제 1 입력
13 32
13 20
23 00
1 15
0 10
0 15

예제 1 출력
3
"""


"""
24 * 60 = 1440, 예를 들어 0시 0분이 시험시간이면 -10인데 파이썬에서 -10 % 1440은 음수를 안 만들고 1430이 나온다(모듈러 연산)
c, c++, java 등에서는 -10이 나온다. (-10 + 1440) % 1440으로 연산 시 동일한 결과가 나옴.
참조 링크 : http://blog.bluekyu.me/2011/03/c.html, https://choiseokwon.tistory.com/204
"""

# input, exam time
h, m = map(int, sys.stdin.readline().split())

# 10 20 --> (10*60 + 20) = 620 분, 시험시간 10분 전, 10을 뺀다
target = (h * 60 + m - 10) % 1440

# 미리 설정된 5개의 시간
presets = []

for _ in range(5):
    h, m = map(int, sys.stdin.readline().split())
    presets.append(h * 60 + m)

# 프리셋을 안 누르고 0시 0분에서 시작함, 1분 버튼을 분 수만큼 눌러야 한다
nonpreset_cnt = min(abs(target), abs((-target) % 1440))

# 타겟 - 프리셋은 증가 버튼을 누르는 수, 프리셋 - 타겟은 감소 버튼을 누르는 수
pmin = min( min(abs((target - p) % 1440 ), abs((p - target) % 1440) ) + 1 for p in presets)
preset_first_cnt = 1 + target - presets[0]
preset_second_cnt = 1 + target - presets[1]
preset_third_cnt = 1 + target - presets[2]
preset_fourth_cnt = 1 + target - presets[3]
preset_fifth_cnt = 1 + target - presets[4]

print(min(pmin, nonpreset_cnt))








