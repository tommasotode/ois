#include <bits/stdc++.h>
using namespace std;
using fi = forward_list<int>;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  size_t N, K; cin >> N >> K;
  vector<fi> adj(N);
  for (size_t i = 0; i < N - 1; i++) {
    int x, y; cin >> x >> y;
    adj[x].push_front(y);
    adj[y].push_front(x);
  }

  vector<int> ans(N);
  vector<bool> v(N);
  vector<pair<int, fi::iterator>> s{{0, adj[0].begin()}};
  while (!s.empty()) {
    auto& [n, it] = s.back();
    if (it == adj[n].end()) {
      s.pop_back();
      continue;
    }

    if (!v[n]) {
      ans[n] = s.size() > K ? s[s.size() - K - 1].first : -1;
      v[n] = true;
    }

    int c = *it; it++;
    if (!v[c]) s.push_back({c, adj[c].begin()});
  }

  for (size_t i = 0; i < N; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
