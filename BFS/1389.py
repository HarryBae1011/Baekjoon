import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
from collections import deque

n, m = map(int, input().split())
friend = [[] * (n + 1) for _ in range(n + 1)]
baccon = [] * (n + 1)

for i in range(m):
    a, b = map(int, input().split())
    friend[a].append(b)
    friend[b].append(a)

def bfs(start_node):
    q = deque([start_node])
    visit[start_node] = 1

    while q:
        current_node = q.popleft()

        for i in friend[current_node]:
            if not visit[i]:
                visit[i] = visit[current_node] + 1
                q.append(i)

res = []

for i in range(1, n + 1):
    visit = [0] * (n + 1)
    bfs(i)
    res.append(sum(visit))

print(res.index(min(res)) + 1)
