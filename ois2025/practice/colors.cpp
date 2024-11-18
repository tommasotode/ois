#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, K; cin >> N >> K;
  vector<int> a(N + 1); a[0] = K;
  int p = 1;
  for (int i = 0; i < N; i++) {
    int v; cin >> v;
    p = int(((long long) p * a[v]) % MOD);
    a[v]--; a[v + 1]++;
  }

  cout << p << endl;
  return 0;
}
