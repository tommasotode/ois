#!/usr/bin/env python3

import sys

sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

N, M = map(int, input().strip().split())

K = [0 for i in range(N)]
S = [[] for i in range(N)]
for j in range(N):
    S[j] = list(map(int, input().strip().split()))
    K[j], S[j] = S[j][0], S[j][1:]

coppie = [set(range(1, M+1)) for i in range(M)]

for i in range(N):
    for j in range(K[i]):
        for k in range(K[i]):
            coppie[S[i][j] - 1].discard(S[i][k])

ans = set()

for i in range(M):
    for j in coppie[i]:
        ans.add((min(i + 1, j), max(i + 1, j)))


print(len(ans))
for t in ans:
    for i in range(2):
        print(t[i], end=' ')
    print()

sys.stdout.close()
