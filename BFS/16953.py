import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
from collections import deque

a, b = map(int, input().split())

def find(num, fin):
    q = deque([(num, 0)])
    cnt = 0

    while q:
        current_num, current_cnt = q.popleft()

        if current_num == fin:
            return current_cnt + 1
            break

        if current_num < fin:
            multi = current_num * 2
            plus = current_num * 10 + 1
            q.append([multi, current_cnt + 1])
            q.append([plus, current_cnt + 1])

    return -1

print(find(a, b))
