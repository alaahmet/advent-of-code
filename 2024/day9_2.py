#!/usr/bin/env python3

with open(('/home/ahmet/coding/advent-of-code/2024/a.in'), 'r') as file:
    data = file.read().strip()
    char_array = list(data)

int_array = [int(char) for char in char_array]
a = []
for i in range(len(int_array)):
    a.append([int_array[i], (i // 2) if i % 2 == 0 else -1])

r = len(a) - 1
h = {}
while 0 < r:
    if a[r][1] != -1:
        l = 0
        while l < r:
            if a[l][1] == -1 and a[l][0] >= a[r][0]:
                if l not in h:
                    h[l] = []
                h[l].append([a[r][0], a[r][1]])
                a[l][0] -= a[r][0]
                a[r][1] = -1
                break
            l += 1
    r -= 1

ans = 0
idx = 0

def sum (l, r):
    return (r * (r + 1) - l * (l - 1)) // 2

for i in range(len(a)):
    if a[i][1] != -1:
        ans += a[i][1] * sum(idx, idx + a[i][0] - 1)
        idx += a[i][0]
    elif i not in h or len(h[i]) == 0:
        idx += a[i][0]
    else:
        for [times, key] in h[i]:
            ans += key * sum(idx, idx + times - 1)
            idx += times
        idx += a[i][0]
    
print(ans)