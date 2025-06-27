#!/usr/bin/env python3
import sys

sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

N, M = map(int, input().strip().split())
S = list(map(int, input().strip().split()))


neguguali, posuguali, negdispari, posdispari, negpari, pospari = 0,0,0,0,0,0
S.sort()

counts = []
for i in range(len(S)):
    if i == 0 or S[i] != S[i - 1]: counts.append(1)
    else: counts[-1] += 1

for n in S:
    if n < 0:
        if n % 2 == 0:
            negpari += 1
        else:
            negdispari += 1
    else:
        if n % 2 == 0:
            pospari += 1
        else:
            posdispari += 1

positivi, negativi = (negpari+negdispari), (pospari+posdispari)

matchuguali = 0
for q in counts:
    matchuguali += (q*(q-1)) // 2

G = 0
T = -1

S_neg, S_pos = [], []
for n in S: (S_neg if n < 0 else S_pos).append(n)


i, j = 0, 0
while i < len(S_neg) and j < len(S_pos):
    pos, neg = S_pos[j], S_neg[i]
    d = -(pos + neg)
    if pos > -neg: d += M

    if d % 2 == 0:
        T = max(T, d // 2)
    elif M % 2 == 1:
        T = max(T, (d + M) // 2)

    if i == len(S_neg) - 1: j += 1
    elif j == len(S_pos) - 1: i += 1
    elif S_pos[j + 1] - S_pos[j] < S_neg[i + 1] - S_neg[i]: j += 1
    else: i += 1


if M % 2 == 1: # dispari
    G += negativi * positivi
    G += matchuguali

else:
    G += negdispari * posdispari
    G += negpari * pospari
    G += matchuguali


print(G, T)
sys.stdout.close()