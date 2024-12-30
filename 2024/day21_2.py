#!/usr/bin/env python3
from functools import cache

with open('/home/ahmet/coding/advent-of-code/2024/a.in', 'r') as file:
    arr = file.read().strip().split('\n')

numpad  = {
    '7': (0, 0), '8': (0, 1), '9': (0, 2),
    '4': (1, 0), '5': (1, 1), '6': (1, 2),
    '1': (2, 0), '2': (2, 1), '3': (2, 2),
                    '0': (3, 1), 'A': (3, 2),
}
dirpad = {
                    '^': (0, 1), 'A': (0, 2),
    '<': (1, 0), 'v': (1, 1), '>': (1, 2),
}

def create_graph(keypad, invalid_coords):
    graph = {}
    for a, (x1, y1) in keypad.items():
        for b, (x2, y2) in keypad.items():
            # a -> b
            path = '<' * (y1 - y2) +  'v' * (x2 - x1) + '^' * (x1 - x2) + '>' * (y2 - y1)
            if invalid_coords == (x1, y2) or invalid_coords == (x2, y1):
                path = path[::-1]
            graph[(a, b)] = path + 'A'
    return graph


numpad_graph = create_graph(numpad, (3, 0))
dirpad_graph = create_graph(dirpad, (0, 0))


@cache
def convert_length(start_char, end_char, rest) -> int:
    if rest == 0:
        return len(dirpad_graph[(start_char, end_char)])
    
    path = dirpad_graph[(start_char, end_char)]
    
    length = 0
    
    for i in range(0, len(path)):
            length += convert_length('A' if i == 0 else path[i - 1], path[i], rest - 1) 
    
    return length

ans = 0

for button_presses in arr:
    
    conversion = ""
    prev = 'A' # initial starting point
    
    for char in button_presses:
        conversion += numpad_graph[(prev, char)]
        prev = char
    
    print(conversion)

    length = 0
    
    for i in range(0, len(conversion)):

        length += convert_length('A' if i == 0 else conversion[i - 1], conversion[i], 24)


    ans += length * int(button_presses[:-1])

    # print(length, int(button_presses[:-1]))

print(ans)

# v<<A>>^A<A>AvA<^AA>A<vAAA>^A
# <A^A>^^AvvvA
# 029A
