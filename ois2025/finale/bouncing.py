#!/usr/bin/env python

from math import gcd

W, H, T = map(int, input().split(" "))
x, y, vx, vy = map(int, input().split(" "))
x2, y2 = map(int, input().split(" "))

W2, H2 = W * 2, H * 2
div = gcd(vx, vy)
T *= div
vx //= div
vy //= div

c = 0

for _ in range(T):
  x += vx
  y += vy

  if (x % W2 == x2 or x % W2 == W2 - x2) and (y % H2 == y2 or y % H2 == H2 - y2): c += 1

print(c)
