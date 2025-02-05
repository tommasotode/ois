#!/usr/bin/env python3


def countletters(s):
    d = {}
    for i in s:
        d[i] = 1 if i not in d.keys() else d[i] + 1
    return d


def solve(S):
    letters = countletters(S)
    for n in letters.values():
        if n > 3:
            print(-1)
            return

    res = ""
    i = 0
    while i < len(S):
        if letters[S[i]] == 1:
            res += S[i] + " "
            letters[S[i]] -= 1

        elif letters[S[i]] == 2:
            if S[i + 1] == S[i]:
                res += S[i] + S[i] + " "
                letters[S[i]] -= 2
            else:
                print(-1)
                return

        elif letters[S[i]] == 3:
            if S[i + 1] == S[i]:
                res += S[i] + S[i] + " "
                letters[S[i]] -= 2
                i += 1
            else:
                res += S[i] + " "
                letters[S[i]] -= 1

        i += 1

    print(res.strip())


T = int(input())
for _ in range(T):
    S = input().strip()
    solve(S)
