import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

n = int(input())
node_map = [[] for _ in range(n + 1)]
visit = [0] * (n + 1)

for _ in range(n - 1):
    x, y = map(int, input().split())
    node_map[x].append(y)
    node_map[y].append(x)

def dfs(node):
    for i in node_map[node]:
        if visit[i] == 0:
            visit[i] = node
            dfs(i)

dfs(1)

for i in range(2, n + 1):
    print(visit[i])
