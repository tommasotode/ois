#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return a == 0 ? b : b == 0 ? a : a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int A, B, K; cin >> A >> B >> K;
    int m = 0;
    for (int k = 0; k <= K; k++) m = max(m, gcd(A + k, B + K - k));
    cout << m << endl;
  }

  return 0;
}
