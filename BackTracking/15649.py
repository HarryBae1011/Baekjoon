import sys

index = [False, False, False, False, False, False, False, False]
stack = []
top = -1

n, m = input().split()
n = int(n)
m = int(m)

def push(value):
    global top
    global stack
    top = top + 1
    stack.append(value)
    return

def pop():
    global top
    global stack
    if top != -1:
        stack.pop()
        top -= 1
    return

def print_index():
    global stack
    for j in range(len(stack)):
        print(stack[j], end=' ')
    print()

def dfs(cnt, idx):
    if cnt == m:
        print_index()
        return

    for i in range(n):
        if index[i] != True:
            index[i] = True
            push(i + 1)
            dfs(cnt + 1, i)
            pop()
            index[i] = False

dfs(0, 0)
