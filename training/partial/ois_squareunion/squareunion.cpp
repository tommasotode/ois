#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N; cin >> N;
  vector<int> X(N), R(N);
  for (int i = 0; i < N; i++) cin >> X[i];
  for (int i = 0; i < N; i++) cin >> R[i];

  if (
    all_of(R.begin(), R.end(), [](int r) { return r == 1; }) && 
    all_of(X.begin(), X.end(), [](int x) { return x % 2 == 1; })
  ) {
    set<int> xs;
    for (int x : X) xs.insert(x);
    cout << xs.size() * 4 << endl;
    return 0;
  }

  vector<int> h(1002000);
  for (int i = 0; i < N; i++) {
    for (int x = X[i] - R[i]; x < X[i] + R[i]; x++) {
      h[x + 1000] = max(h[x + 1000], R[i] * 2);
    }
  }

  cout << accumulate(h.begin(), h.end(), 0) << endl;
  return 0;
}
