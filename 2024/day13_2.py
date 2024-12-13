#!/usr/bin/env python3

data = []
with open('/home/ahmet/coding/advent-of-code/2024/a.in', 'r') as file:
    lines = file.read().strip('\n').split('\n')
    data = []
    for i in range(0, len(lines), 4):
        bax = int(lines[i].split()[2][2:].rstrip(','))
        bay = int(lines[i].split()[3][2:].rstrip(','))
        bbx = int(lines[i+1].split()[2][2:].rstrip(','))
        bby = int(lines[i+1].split()[3][2:].rstrip(','))
        sumx = int(lines[i+2].split()[1][2:].rstrip(','))
        sumy = int(lines[i+2].split()[2][2:].rstrip(','))
        data.append((bax, bay, bbx, bby, 10000000000000 + sumx, 10000000000000 + sumy))

sum = 0

for (bax, bay, bbx, bby, sumx, sumy) in data:
    fbax = bax
    bax *= bay
    bbx *= bay
    sumx *= bay
    bay *= fbax
    bby *= fbax
    sumy *= fbax
    buttonB = -1
    buttonA = -1
    if sumx <= sumy:
        buttonB = (sumy - sumx) / (bby - bbx)
        buttonA = (sumx - bbx * buttonB) / bax
    else:
        buttonB = (sumx - sumy) / (bbx - bby)
        buttonA = (sumx - bbx * buttonB) / bax
    if buttonA >= 0 and buttonB >= 0 and buttonA.is_integer() and buttonB.is_integer():
        sum += buttonA * 3 + buttonB

print(sum)

