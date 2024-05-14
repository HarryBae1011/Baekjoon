index = [0, 0, 0, 0, 0, 0, 0]
stack = []

n, m = input().split()
n = int(n)
m = int(m)

def print_stack():
    for j in range(len(stack)):
        print(stack[j], end=' ')
    print()

def dfs(cnt, idx):
    if cnt == m:
        print_stack()
        return

    for i in range(n):
        index[i] += 1
        stack.append(i + 1)
        dfs(cnt + 1, i)
        stack.pop()
        index[i] -= 1

dfs(0, 0)
