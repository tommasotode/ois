#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

struct mat22 {
  long long m11, m12, m21, m22;

  void operator*=(const mat22& o) {
    *this = {
      (o.m11 * m11 + o.m21 * m12) % MOD, (o.m12 * m11 + o.m22 * m12) % MOD,
      (o.m11 * m21 + o.m21 * m22) % MOD, (o.m12 * m21 + o.m22 * m22) % MOD
    };
  }
};

mat22 pow(mat22 b, long long e) {
  if (e == 0) return {1, 0, 0, 1};

  mat22 r = pow(b, e / 2); r *= r;
  if (e % 2 == 1) r *= b;
  return r;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    long long N; cin >> N;
    cout << pow({0, 1, 2, 1}, N - 1).m21 << '\n';
  }

  return 0;
}
