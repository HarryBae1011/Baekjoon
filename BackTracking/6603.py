import sys
input = sys.stdin.readline

def dfs(depth, i):
    if depth == 6:
        print(*res)
        return

    for i in range(i, k):
        if depth + k - i < 6:
            return
        res.append(s[i])
        dfs(depth + 1, i + 1)
        res.pop()


while True:
    lotto = list(map(int, input().split()))

    k = lotto[0]
    s = lotto[1:]

    if k == 0:
        break

    res = []

    dfs(0, 0)
    print()
