#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int homework(int N, int M, vi& S, vi& D, int i, long long t) {
  if (i == N) return 0;

  long long end = t + S[i];
  return max(
    (end <= D[i] ? 2 : end <= M ? 1 : 0) + homework(N, M, S, D, i + 1, end),
    homework(N, M, S, D, i + 1, t)
  );
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, M; cin >> N >> M;

    vi S(N), D(N);
    for (int i = 0; i < N; i++) cin >> S[i] >> D[i];

    int P = homework(N, M, S, D, 0, 0);
    cout << P << endl;
  }

  return 0;
}
