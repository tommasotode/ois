#include <bits/stdc++.h>

using namespace std;

int salta(int N, vector<int> S, vector<int> A, vector<int> B) {
  S.push_back(0);
  vector<int> d(N + 1, INT_MAX);
  d[0] = S[0];
  using ii = pair<int, int>;
  priority_queue<ii, vector<ii>, greater<ii>> q;
  unordered_set<int> v;
  q.push({S[0], 0});

  while (!q.empty()) {
    auto [c, i] = q.top(); q.pop();
    if (v.find(i) != v.end()) continue;
    v.insert(i);

    if (i == N) return c;

    for (int o = A[i]; o <= B[i]; o++) {
      if (max(c, S[i + o]) < d[i + o]) {
        d[i + o] = max(c, S[i + o]);
        q.push({d[i + o], i + o});
      }
    }
  }

  throw exception();
}
