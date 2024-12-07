with open(('/home/ahmet/coding/advent-of-code/2024/a.in'), 'r') as file:
    data = file.read().strip()
lines = data.split('\n')

def f(goal, curr, nums, idx):
    if idx == len(nums):
        if curr == goal:
            return curr
        else:
            return 0
    num = nums[idx]
    val1 = f(goal, curr + num, nums, idx + 1)
    val2 = f(goal, curr * num, nums, idx + 1)
    return max(val1, val2)

sum = 0

for line in lines:
    parts = line.split(':')
    goal = int(parts[0])
    nums = list(map(int, parts[1][1:].split(' ')))
    sum += f(goal, 0, nums, 0)

print(sum)