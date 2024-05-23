import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

n = int(input())

land = []
max_num = 0
res = 1

for i in range(n):
    num = list(map(int, input().split()))
    land.append(num)

    for j in num:
        if j > max_num:
            max_num = j

def dfs(x, y, height):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < n and visit[nx][ny] == False and land[nx][ny] > height:
            visit[nx][ny] = True
            dfs(nx, ny, height)

for i in range(max_num):
    visit = [[False] * n for _ in range(n)]
    count = 0

    for j in range(n):
        for k in range(n):
            if land[j][k] > i and visit[j][k] == False:
                count += 1
                visit[j][k] = True
                dfs(j, k, i)

    res = max(res, count)

print(res)
