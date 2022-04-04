from collections import Counter
import sys

n = int(sys.stdin.readline())
nums = []
for _ in range(n):
    nums.append(int(sys.stdin.readline()))

# mean
print(round(sum(nums) / n))

# middle
nums.sort()
print(nums[int((n-1)/2)])

# most frequent
cnt_li = Counter(nums).most_common()
if len(cnt_li) > 1 and cnt_li[0][1] == cnt_li[1][1]:
    print(cnt_li[1][0])
else:
    print(cnt_li[0][0])

# variance
print(nums[-1] - nums[0])
