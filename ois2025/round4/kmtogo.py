#!/usr/bin/env python3

import sys


N = int(input().strip())
D = [0 for _ in range(10)]

for i in range(1, N + 1):
  for c in str(i):
    D[ord(c) - 48] += 1

for i in range(10):
  print(D[i], end=' ')
print()

sys.stdout.close()
