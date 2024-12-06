#include <bits/stdc++.h>

using namespace std;

long long pow10(int e) {
  long long r = 1;
  for (int i = 0; i < e; i++) r *= 10;
  return r;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int K, X; cin >> K >> X;

  long long s = pow10(X / 2 - 1);
  long long sum = 0;
  for (int i = 0; i < K; i++) {
    long long l = s + i;
    string r = to_string(l);
    reverse(r.begin(), r.end());
    sum += l * pow10(X / 2) + stoi(r);
  }

  cout << sum << endl;
  return 0;
}
