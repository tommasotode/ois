#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using adj_list = vector<forward_list<pair<int, int>>>;

unordered_map<int, ll> dijkstra(int N, adj_list& adj, int s, unordered_set<int> n) {
  vector<ll> d(N, LLONG_MAX);
  using li = pair<ll, int>;
  priority_queue<li, vector<li>, greater<li>> q;
  unordered_set<int> v;
  q.push({0, s});

  unordered_map<int, ll> res;
  while (!q.empty()) {
    auto [c, i] = q.top(); q.pop();
    if (v.find(i) != v.end()) continue;
    v.insert(i);

    if (n.find(i) != n.end()) {
      res[i] = c;
      n.erase(i);
      if (n.empty()) return res;
    }

    for (auto [j, t] : adj[i]) {
      if (c + t < d[j]) {
        d[j] = c + t;
        q.push({c + t, j});
      }
    }
  }

  throw exception();
}

vector<ll> shorten(int N, int M, int Q, vector<ll> K, vector<int> A, vector<int> B, vector<int> C) {
  if (Q != 1 || K[0] != 0) exit(1);

  adj_list adj(N);
  for (int i = 0; i < M; i++) {
    adj[A[i]].push_front({B[i], C[i]});
    adj[B[i]].push_front({A[i], C[i]});
  }

  unordered_map<int, ll> d = dijkstra(N, adj, 1, {0, 2});
  return {d[0] + d[2]};
}
