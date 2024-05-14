index = [False, False, False, False, False, False, False, False]

n, m = input().split()
n = int(n)
m = int(m)

def print_index():
    for j in range(n):
        if index[j]:
            print(j + 1, end=' ')
    print()

def dfs(cnt, idx):
    if cnt == m:
        print_index()
        return

    for i in range(idx, n):
        if index[i] != True:
            index[i] = True
            dfs(cnt + 1, i)
            index[i] = False

dfs(0, 0)
