#!/usr/bin/env python3

import sys
N = int(input().strip())

prime = [True] * (N + 1)

steps = 0
for base in range(2, N + 1):
  if not prime[base]: continue

  steps += 1

  for other in range(base, N + 1, base): prime[other] = False

print(steps)
sys.stdout.close()
