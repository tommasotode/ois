#!/usr/bin/env python3
import sys

N, M = map(int, input().strip().split())

city = ["" for i in range(N)]
for i in range(N):
    city[i] = input().strip()

P = 0
for i in range(len(city)):
    for j in range(len(city[i])):
        if city[i][j] == "#":
            P += int(city[i][j-1] == ".") + \
            int(city[i][j+1] == ".") + \
            int(city[i-1][j] == ".") + \
            int(city[i+1][j] == ".")

print(P)
sys.stdout.close()