#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N; long long K;
  cin >> N >> K;

  vector<long long> P(N);
  for (int i = 0; i < N; i++) cin >> P[i];

  long long target = N * K;
  long long sum = accumulate(P.begin(), P.end(), 0ll);

  if (sum <= target) {
    cout << (target - sum + N - 1) / N << endl;
    return 0;
  }

  sort(P.begin(), P.end());

  long long prev = 1;
  for (int i = 0; i < N; i++) {
    long long req = (sum - target + N - i - 1) / (N - i);

    if (req <= P[i] - prev) {
      cout << prev + req - 1 << endl;
      return 0;
    }

    sum -= (P[i] - prev) * (N - i);
    prev = P[i];
  }

  return 1;
}
