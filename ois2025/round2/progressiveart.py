#!/usr/bin/env python3
import sys


N, M, L, K = map(int, input().strip().split())

if K == 0:
    print("YES")
    for i in range(N):
        for j in range(M):
            print("B", end="")
        print()
    exit()

if L % 3 != 0 or N < L or M < L or K > (M - L + 1) * (N - L + 1):
    print("NO")
    exit()

print("YES")
ans = [[None] * M for _ in range(N)]

rows, rest = K // (M - L + 1) + L - 1, L + K % (M - L + 1) - 1
fill = "RGB"[(rest - 1) % 3]

for i in range(rows):
    for j in range(min(K + L - 1, M)):
        ans[i][j] = "RGB"[j % 3]

if rest >= L:
    for j in range(rest): ans[rows][j] = "RGB"[j % 3]

for i in range(N):
    for j in range(M):
        print(ans[i][j] or fill, end="")
    print()

sys.stdout.close()
