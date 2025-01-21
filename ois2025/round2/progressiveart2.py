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

if (L % 3) != 0 or N < 3 or M < 3:
    print("NO")
    exit()

if L != 3 or K > M - 2:
    print("NO")
    exit()

print("YES")
for i in range(3):
    for j in range(M):
        if j <= K:
            if j % 3 == 0:
                print("R", end="")
            if j % 3 == 1:
                print("G", end="")
            if j % 3 == 2:
                print("B", end="")
        else:
            print("GBR"[K % 3], end="")
    print()

sys.stdout.close()
