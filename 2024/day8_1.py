with open(('/home/ahmet/coding/advent-of-code/2024/a.in'), 'r') as file:
    data = file.read().strip()
a = [list(line) for line in data.split('\n')]
n = len(a)
m = len(a[0])
hm = {}
for i in range(n):
    for j in range(m):
        if a[i][j] != '.':
            if a[i][j] not in hm:
                hm[a[i][j]] = []
            hm[a[i][j]].append((i, j))

def check(i, j):
    if i < 0 or i >= n or j < 0 or j >= m:
        return False
    return True

ans = set()

for key in hm:
    for (i, j) in hm[key]:
        for (k, l) in hm[key]:
            if i == k  and j == l:
                continue
            x = i + i - k
            y = j + j - l
            if check(x, y):
                ans.add((x, y))
            x = k + k - i
            y = l + l - j
            if check(x, y):
                ans.add((x, y))

print(len(ans))