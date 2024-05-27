import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
from  collections import deque

n, m, v = map(int, input().split())

nodes = [[] for _ in range(n + 1)]
graph = [[0] * (n + 1) for _ in range(n + 1)]
visit = [False for _ in range(n + 1)]
visit_b = [False for _ in range(n + 1)]

for i in range(m):
    x, y = map(int, input().split())
    nodes[x].append(y)
    nodes[y].append(x)
    graph[x][y] = 1
    graph[y][x] = 1


for i in range(n + 1):
    nodes[i].sort()

def dfs(node):
    visit[node] = True
    print(node, end=' ')

    for i in nodes[node]:
        if visit[i] == False:
            dfs(i)

def bfs(node):
    q = deque([node])
    visit_b[node] = True

    while q:
        node = q.popleft()
        print(node, end=' ')
        for i in range(1, n + 1):
            if visit_b[i] == False and graph[node][i] == 1:
                q.append(i)
                visit_b[i] = True

dfs(v)
print()
bfs(v)
