#!/usr/bin/env python3
import sys

T = int(input().strip())
for test in range(1, T + 1):
    input()
    N, M = map(int, input().strip().split())
    S = ["" for _ in range(N)]
    for i in range(N):
        S[i] = input().strip()
    s = S[0]

    K = 0
    i = 0
    while i < M:
        l = 1
        while (i + l) < M and s[i + l] == s[i]:
            l += 1

        if l >= 3:
            K += l // 3

        i += l

    print(K)

sys.stdout.close()
