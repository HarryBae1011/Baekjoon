import sys
sys.setrecursionlimit(100000)
from collections import deque

n = int(input())

picture = [list(input()) for _ in range(n)]
visit = [[False] * n for _ in range(n)]
visit2 = [[False] * n for _ in range(n)]

def bfs(x, y):
    q = deque([(x, y)])
    visit[x][y] = True

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    while q:
        current_x, current_y = q.popleft()

        for i in range(4):
            nx = current_x + dx[i]
            ny = current_y + dy[i]

            if 0 <= nx < n and 0 <= ny < n and visit[nx][ny] == False:
                if picture[nx][ny] == picture[x][y]:
                    visit[nx][ny] = True
                    q.append([nx, ny])

def bfs2(x, y):
    q = deque([(x, y)])
    visit2[x][y] = True

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    while q:
        current_x, current_y = q.popleft()

        for i in range(4):
            nx = current_x + dx[i]
            ny = current_y + dy[i]

            if 0 <= nx < n and 0 <= ny < n and visit2[nx][ny] == False:
                if picture[nx][ny] == picture[x][y]:
                    visit2[nx][ny] = True
                    q.append([nx, ny])
                elif picture[x][y] == 'R' and picture[nx][ny] == 'G':
                    visit2[nx][ny] = True
                    q.append([nx, ny])
                elif picture[x][y] == 'G' and picture[nx][ny] == 'R':
                    visit2[nx][ny] = True
                    q.append([nx, ny])

count = 0

for i in range(n):
    for j in range(n):
        if visit[i][j] == False:
            bfs(i, j)
            count += 1

count2 = 0

for i in range(n):
    for j in range(n):
        if visit2[i][j] == False:
            bfs2(i, j)
            count2 += 1


print(count, count2)
