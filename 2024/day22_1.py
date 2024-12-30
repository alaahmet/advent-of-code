#!/usr/bin/env python3

with open('/home/ahmet/coding/advent-of-code/2024/a.in', 'r') as file:
    asx = file.read().strip().split('\n')
    arr = [int(i) for i in asx]

def mix(a, b):
    return a ^ b

def prune(a):
    return a % 16777216

def next_secret(x):
    x = prune(mix(x, x << 6))
    x = prune(mix(x, x >> 5))
    x = prune(mix(x, x << 11))
    return x

sum = 0
for x in arr:
    for i in range(2000):
        x = next_secret(x)
    sum += x
    # print(x)

print(sum)