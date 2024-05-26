import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

m, n, k = map(int, input().split())

visit = [[False] * n for _ in range(m)]

for _ in range(k):
    start_x, start_y, end_x, end_y = map(int, input().split())

    for i in range(start_y, end_y):
        for j in range(start_x, end_x):
            visit[i][j] = True

def dfs(x, y, cnt):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    visit[x][y] = True

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < m and 0 <= ny < n and visit[nx][ny] == False:
            cnt = dfs(nx, ny, cnt + 1)

    return cnt

area = []

for i in range(m):
    for j in range(n):
        if visit[i][j] == False:
            area.append(dfs(i, j, 1))

print(len(area))
print(*sorted(area))
