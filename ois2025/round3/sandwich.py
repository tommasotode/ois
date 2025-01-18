#!/usr/bin/env python3

import sys
sys.stdin = open('input.txt')
sys.stdout = open('output.txt', 'w')

N = int(input().strip())
V = list(map(int, input().strip().split()))

print(sum(1 for v in V if v > 0))

sys.stdout.close()
