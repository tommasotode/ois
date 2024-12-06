#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int MOD = 1000000007;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int K; cin >> K;
  vi V(K);
  for (int i = 0; i < K; i++) cin >> V[i];

  int maxV = *max_element(V.begin(), V.end());
  vector<vi> prop(K, vi(maxV + 1));
  prop[0][0] = 1;
  for (int i = 1; i <= maxV; i++) {
    for (int k = 0; k < K; k++) {
      prop[k][i] = (prop[k][i] + prop[k][i - 1]) % MOD;
      int k2 = (k + 1) % K;
      prop[k2][i] = (prop[k2][i] + prop[k][i - 1]) % MOD;
    }
  }

  vector<vi> m(K, vi(K + 1));
  m[0][K] = 1;
  for (int i = K - 1; i >= 0; i--) {
    for (int s = 0; s < K; s++) {
      for (int j = 0; j < K; j++) {
        m[s][i] = int((m[s][i] + ((long long) prop[j][V[i]] * m[(s + (i + 1) * j) % K][i + 1]) % MOD) % MOD);
      }
    }
  }

  cout << m[0][0] << endl;
  return 0;
}
