import networkx as nx

#!/usr/bin/env python3

with open(('/home/ahmet/coding/advent-of-code/2024/a.in'), 'r') as file:
    inp = [line.split('-') for line in file.read().strip().split('\n')]

g = {}
for (x, y) in inp:
    if x not in g:
        g[x] = []
    if y not in g:
        g[y] = []
    g[x].append(y)
    g[y].append(x)


G = nx.Graph(g)
max_clique = max(nx.find_cliques(G), key=len)
print(sorted(max_clique))

