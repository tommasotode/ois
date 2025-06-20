#!/usr/bin/env python3

import sys
N = int(input().strip())
P = list(map(int, input().strip().split()))

index_of = [None] * N
for i in range(N): index_of[P[i]] = i

answer = "YES"
swaps = []
for i in range(N):
  if index_of[i] != P[i]:
    answer = "NO"
    break

  if i < P[i]:
    swaps.append((i, P[i]))

print(answer)
if answer == "YES":
  print(len(swaps))
  for swap in swaps: print(len(swap), *swap)

sys.stdout.close()
