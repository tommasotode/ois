#!/usr/bin/env python3

import sys
from math import sqrt


N, M, A = map(int, input().strip().split())

c = 0

for w in range(1, int(sqrt(A)) + 1):
  h, r = divmod(A, w)
  if r != 0: continue

  c += w >= N and h >= M
  if w == h: continue

  c += h >= N and w >= M

print(c)
sys.stdout.close()
