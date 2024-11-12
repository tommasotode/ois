#!/usr/bin/env python3
import sys

T = int(input().strip())
for test in range(1, T + 1):
    N = int(input().strip())
    C = input().strip()

    groups = []
    for i in C.split("-"):
        if i != "":
            groups.append(i)

    seconds = []
    groups.sort(reverse=True)
    for i in groups:
        seconds.append(len(i) // 2 + 1)

    print(len(groups), max(i + x for i, x in enumerate(seconds)))

sys.stdout.close()