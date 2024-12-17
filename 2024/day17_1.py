import re

#!/usr/bin/env python3

with open(('/home/ahmet/coding/advent-of-code/2024/a.in'), 'r') as file:
    input = file.read().strip('\n').split('\n')

a = int(input[0].split(' ')[2])
b = int(input[1].split(' ')[2])
c = int(input[2].split(' ')[2])
ip = list(map(int, input[4].split(' ')[1].split(',')))

n = len(ip)

def combo(x):
    if 0 <= x <= 3: return x
    elif x == 4: return a
    elif x == 5: return b
    elif x == 6: return c
    else: assert(False)

i = 0
ans = []
while i < n:
    if ip[i] == 0:
        a = a // (1 << combo(ip[i + 1]))
        i += 2
    elif ip[i] == 1:
        b = b ^ ip[i + 1]
        i += 2
    elif ip[i] == 2:
        b = combo(ip[i + 1]) & 7
        i += 2
    elif ip[i] == 3: #jump
        if a == 0: i += 2
        else: i = ip[i + 1]
    elif ip[i] == 4:
        b = b ^ c
        i += 2
    elif ip[i] == 5:
        ans.append(combo(ip[i + 1]) & 7)
        i += 2
    elif ip[i] == 7:
        c = a >> combo(ip[i + 1])
        i += 2
        
for k in range(len(ans) - 1):
    print(ans[k], end=',')
print(ans[-1], end=',')

       
