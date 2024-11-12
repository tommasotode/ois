#!/usr/bin/env python3


N = int(input().strip())

res = N
for i in range(N):
    alpha = {}

    S = input().strip()
    S = S.lower()
    for c in S:
        if not c.isalpha():
            continue

        if c not in alpha:
            alpha[c] = 1
        else:
            alpha[c] += 1

        if alpha[c] > 2:
            res -= 1
            break

print(res)
