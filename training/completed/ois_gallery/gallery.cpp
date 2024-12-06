#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N; cin >> N;
  unordered_map<int, vector<int>> P;
  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    P[y].push_back(x);
  }

  int ax2 = -1;
  for (auto [y, xs] : P) {
    sort(xs.begin(), xs.end());
    for (size_t i = 0; i <= xs.size() / 2; i++) {
      int x2 = xs[i] + xs[xs.size() - i - 1];
      if (ax2 == -1) ax2 = x2;
      else if (x2 != ax2) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;
  return 0;
}
