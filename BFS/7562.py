import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
from collections import deque

def bfs(start_x, start_y, chess):
    q = deque([(start_x, start_y)])

    dx = [1, 1, 2, 2, -1, -1, -2, -2]
    dy = [2, -2, 1, -1, 2, -2, 1, -1]

    while q:
        x, y = q.popleft()

        if x == des_x and y == des_y:
            print(chess[x][y])
            break

        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < len(chess) and 0 <= ny < len(chess[0]) and chess[nx][ny] == 0:
                    chess[nx][ny] = chess[x][y] + 1
                    q.append((nx, ny))

    return -1

n = int(input())

for i in range(n):
    i = int(input())
    chess = [[0] * i for _ in range(i)]
    knight_nx, knight_ny = map(int, input().split())
    des_x, des_y = map(int, input().split())

    bfs(knight_nx, knight_ny, chess)
