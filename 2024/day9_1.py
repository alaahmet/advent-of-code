#!/usr/bin/env python3

with open(('/home/ahmet/coding/advent-of-code/2024/a.in'), 'r') as file:
    data = file.read().strip()
    char_array = list(data)

int_array = [int(char) for char in char_array]
a = []
for i in range(len(int_array)):
    a.extend([(i // 2) if i % 2 == 0 else -1] * int_array[i])

r = len(a) - 1
l = 0
while l < r:
    if a[r] == -1:
        r -= 1
    elif a[l] != -1:
        l += 1
    elif a[l] == a[r]:
        break
    else:
        a[l] = a[r]
        a[r] = -1
        l += 1
        r -= 1
ans = 0
for i in range(len(a)):
    if a[i] != -1:
        ans += i * a[i]
print(ans)
