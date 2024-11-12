#!/usr/bin/env python3
import sys
import math

N = int(input().strip())
T = list(map(int, input().strip().split()))

s = 0
for i in T:
    if math.log2(i + 1) != math.floor(math.log2(i + 1)):
        l = int(math.log2(i)) + 1
        s += abs(i - (pow(2, l) - 1))

print(s)

sys.stdout.close()