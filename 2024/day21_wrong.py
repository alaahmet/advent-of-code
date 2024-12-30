with open('/home/ahmet/coding/advent-of-code/2024/a.in', 'r') as file:
    asx = file.read().strip().split('\n')
    data = [[10 if char == 'A' else int(char) for char in line] for line in asx[:5]]

# 7 8 9
# 4 5 6
# 1 2 3
#   0 10
gn = [[-1, -1, 10, 2], [-1, -1, 2, 4], [1, 0, 3, 5], [2, 10, -1, 6], [-1, 1, 5, 7], [4, 2, 6, 8], [5, 3, -1, 9], [-1, 4, 8, -1], [7, 5, 9, -1], [8, 6, -1, -1], [0, -1, -1, 3]]
#   3 4
# 0 1 2
gd = [[-1, -1, -1, 1], [0, -1, 2, 3], [1, -1, -1, 4], [-1, 1, 4, -1], [3, 2, -1, -1]]


def dfs(len, finidx, armloc, dirloc, numloc):
    if finidx == 4:
        return


    if dirloc == 4:
        dfs(len + 1, finidx, dirloc, 4, numloc)
    elif gd[dirloc][armloc] != -1:
        dfs(len + 1, finidx, armloc, gd[dirloc][armloc], numloc)

    for i in range(4):
        if gd[armloc][i] != -1:
            dfs(len + 1, finidx, gd[armloc][i], dirloc, numloc)


str = data[0]
