#!/usr/bin/env python3

import sys
X, Y = map(int, input().strip().split())

process = X // 2 != Y // 2
print("C" if process else "N", flush=True)

while True:
  if process:
    if X // 2 == Y // 2:
      if X > Y: Y -= 1
      else: X -= 1
    else:
      if X > Y: X = Y // 2 * 2 + 1 - Y % 2
      else: Y = X // 2 * 2 + 1 - X % 2

    print(X, Y, flush=True)

  if X == 0 and Y == 1 or X == 1 and Y == 0: break

  process = True
  X, Y = map(int, input().strip().split())
  if X == 0 and Y == 1 or X == 1 and Y == 0: break

sys.stdout.close()
