#!/usr/bin/env python3
import sys

N = int(input().strip())

pieces = 0
tiling = [[0 for j in range(N)] for i in range(N)]

if N == 1:
    print(0)
    print("0")
elif N == 2:
    print(0)
    print("0 0")
    print("0 0")
elif N == 3:
    print(1)
    print("0 1 0")
    print("0 1 1")
    print("0 0 1")
elif N == 4:
    print(4)
    print("1 1 1 2")
    print("3 1 2 2")
    print("3 3 4 2")
    print("3 4 4 4")
elif N == 5:
    print(6)
    print("1 2 2 2 3")
    print("1 1 2 3 3")
    print("1 6 0 3 4")
    print("6 6 5 4 4")
    print("6 5 5 5 4")
elif N == 6:
    print(8)
    print("1 2 2 3 3 3")
    print("1 1 2 2 3 4")
    print("1 5 0 0 4 4")
    print("5 5 0 0 6 4")
    print("5 7 7 8 6 6")
    print("7 7 8 8 8 6")
elif N == 7:
    print(11)
    print("1 1 2 2 2 3 3")
    print("4 1 1 2 3 3 5")
    print("4 4 0 6 0 5 5")
    print("4 7 0 6 6 8 5")
    print("7 7 0 0 6 8 8")
    print("7 9 10 10 10 11 8")
    print("9 9 9 10 11 11 11")
elif N == 8:
    print(16)
    print("1 3 3 3 5 7 7 7")
    print("1 1 3 4 5 5 7 8")
    print("1 2 4 4 5 6 8 8")
    print("2 2 2 4 6 6 6 8")
    print("9 11 11 11 13 15 15 15")
    print("9 9 11 12 13 13 15 16")
    print("9 10 12 12 13 14 16 16")
    print("10 10 10 12 14 14 14 16")
elif N == 9:
    print(20)
    print("1 1 2 2 3 3 4 4 4")
    print("5 1 1 2 2 3 3 4 8")
    print("5 5 6 6 7 7 7 8 8")
    print("5 9 10 6 6 7 11 8 12")
    print("9 9 10 10 0 11 11 12 12")
    print("9 13 10 14 15 15 11 12 16")
    print("13 13 14 14 14 15 15 16 16")
    print("13 17 18 18 19 19 20 20 16")
    print("17 17 17 18 18 19 19 20 20")
elif N == 10:
    print(24)
    print("1 2 2 3 3 4 4 5 5 5")
    print("1 1 2 2 3 3 4 4 5 10")
    print("1 6 7 8 8 9 9 9 10 10")
    print("6 6 7 7 8 8 9 13 10 14")
    print("6 11 7 12 0 0 13 13 14 14")
    print("11 11 12 12 0 0 13 18 14 19")
    print("11 15 12 16 17 17 18 18 19 19")
    print("15 15 16 16 16 17 17 18 19 24")
    print("15 20 21 21 22 22 23 23 24 24")
    print("20 20 20 21 21 22 22 23 23 24")
elif N % 4 == 0:
    pieces = N * N // 4
    n = 1
    for i in range(N // 4):
        for j in range(N // 4):
            bx = i * 4
            by = j * 4
            tiling[bx][by] = n
            tiling[bx + 1][by] = n
            tiling[bx + 2][by] = n
            tiling[bx + 3][by] = n + 1
            tiling[bx][by + 1] = n + 2
            tiling[bx + 1][by + 1] = n
            tiling[bx + 2][by + 1] = n + 1
            tiling[bx + 3][by + 1] = n + 1
            tiling[bx][by + 2] = n + 2
            tiling[bx + 1][by + 2] = n + 2
            tiling[bx + 2][by + 2] = n + 3
            tiling[bx + 3][by + 2] = n + 1
            tiling[bx][by + 3] = n + 2
            tiling[bx + 1][by + 3] = n + 3
            tiling[bx + 2][by + 3] = n + 3
            tiling[bx + 3][by + 3] = n + 3
            n += 4

    print(pieces)

    for j in range(N):
        for i in range(N):
            print(tiling[j][i], end=" ")

        print()
else:
    exit(1)

sys.stdout.close()
