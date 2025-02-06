#!/usr/bin/env python3

import sys


N, M, Q = map(int, input().strip().split())

bordi_h = [[False] * N for _ in range(M + 1)]
bordi_v = [[False] * (N + 1) for _ in range(M)]
c = 0

for i in range(Q):
  x1, x2, y1, y2 = map(int, input().strip().split())

  for y in y1 - 1, y2:
    for x in range(x1 - 1, x2):
      c += -1 if bordi_h[y][x] else 1
      bordi_h[y][x] = not bordi_h[y][x]

  for x in x1 - 1, x2:
    for y in range(y1 - 1, y2):
      c += -1 if bordi_v[y][x] else 1
      bordi_v[y][x] = not bordi_v[y][x]

  print(c)

sys.stdout.close()
