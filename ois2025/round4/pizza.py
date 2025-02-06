#!/usr/bin/env python3

import sys

sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

def cost(pizzabase, pizzares, addcost, remcost):
    c = 0

    for ingbase in pizzabase:
        if ingbase not in pizzares:
            c += remcost[ingbase]

    for ingres in pizzares:
        if ingres not in pizzabase:
            c += addcost[ingres]

    return c

def solve(Mingredienti, pizzares, addcost, remcost):
    best = float('inf')
    
    for pizzabase in Mingredienti:
        best = min(best, cost(pizzabase, pizzares, addcost, remcost))

    return best


N, M, Q = map(int, input().strip().split())

addcost = [0 for i in range(N)]
remcost = [0 for i in range(N)]
for i in range(N):
    addcost[i], remcost[i] = map(int, input().strip().split())

Mcount = [0 for i in range(M)]
Mingredienti = [[0 for j in range(N)] for i in range(M)]
for i in range(M):
    Mcount[i] = int(input().strip())
    Mingredienti[i] = list(map(int, input().strip().split()))

Qcount = [0 for i in range(Q)]
Qingredienti = [[0 for j in range(N)] for i in range(Q)]
for i in range(Q):
    Qcount[i] = int(input().strip())
    Qingredienti[i] = list(map(int, input().strip().split()))


ANS = [solve(Mingredienti, pizzares, addcost, remcost) for pizzares in Qingredienti]

for i in range(Q):
    print(ANS[i])

sys.stdout.close()
