#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int N, i;
int X[MAXN];
int Y[MAXN];

int main()
{
    assert(1 == scanf("%d", &N));
    for (i = 0; i < N; i++)
        assert(2 == scanf("%d %d", &X[i], &Y[i]));

    map<int, vector<int>> m;
    for (int i = 0; i < N; i++)
        m[Y[i]].push_back(X[i]);
    for (auto &Y : m)
        sort(Y.second.begin(), Y.second.end());

    int simmetry = -1;
    for (auto &Y : m)
    {
        if (simmetry == -1)
            simmetry = Y.second[0] + Y.second[Y.second.size() - 1];

        int size = Y.second.size();
        for (int i = 0; i < size; i++)
        {
            if (i > size - i - 1)
                break;
            if (Y.second[i] + Y.second[size - i - 1] != simmetry)
            {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    return 0;
}