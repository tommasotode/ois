#!/usr/bin/env python3

import sys

sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

T = int(input().strip())
for test in range(1, T+1):
    N = int(input().strip())

    A = list(map(int, input().strip().split()))
    used = [False for _ in range(N)]
    P = 0
    for i in range(len(A)):
        if A[i] == 1:

            if i-1 >= 0:
                if (A[i-1] == 2) and (used[i-1] == False):
                    used[i-1] = True
                    P += 1
                    continue

            if i+1 < len(A):
                if (A[i+1] == 2) and (used[i+1] == False):
                    used[i+1] = True
                    P += 1
                    continue
    
    print(P)

sys.stdout.close()