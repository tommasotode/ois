#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, M; cin >> N >> M;
  vector<long long> P(N, LLONG_MIN);
  P[0] = 0;

  int K;
  for (K = 0; K < M; K++) {
    int a, b, z; cin >> a >> b >> z;

    if (a == b) {
      if (z != 0) break;
      continue;
    }

    if (P[a] == LLONG_MIN) {
      if (P[b] == LLONG_MIN) return 1;
      P[a] = P[b] + z;
    } else {
      if (P[b] == LLONG_MIN) P[b] = P[a] - z;
      else if (P[a] - P[b] != z) break;
    }
  }

  cout << K << endl;
  return 0;
}
