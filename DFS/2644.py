import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

n = int(input())
a, b = map(int, input().split())
m = int(input())
family = [[] for _ in range(n + 1)]
visit = [0] * (n + 1)

for _ in range(m):
    x, y = map(int, input().split())
    family[x].append(y)
    family[y].append(x)

find = 0

def dfs(node, count):
    global find
    visit[node] = 1

    if node == b:
        find = 1
        print(count)

    for i in family[node]:
        if visit[i] == 0:
            dfs(i, count + 1)

dfs(a, 0)

if find == 0:
    print(-1)
