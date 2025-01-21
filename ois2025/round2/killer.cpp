#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test)
    {
        long long N, K;
        cin >> N >> K;

        if (K == 1)
        {
            cout << "YES\n";
            continue;
        }
        long long somma = K * (K - 1) / 2;
        if (N < somma + K)
        {
            cout << "NO\n";
            continue;
        }
        cout << (((N - somma) - (K - 1) <= 2) ? "YES" : "NO") << "\n";
    }

    return 0;
}