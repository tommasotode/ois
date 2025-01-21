#include <bits/stdc++.h>
using namespace std;
using adj_list = vector<forward_list<int>>;

void bfs(adj_list& adj, int s, vector<int>& d_v) {
  queue<int> q;
  d_v[s] = 0;
  q.push(s);

  while (!q.empty()) {
    int n = q.front(); q.pop();

    for (int c : adj[n]) {
      if (d_v[c] == -1) {
        d_v[c] = d_v[n] + 1;
        q.push(c);
      }
    }
  }
}

int main() {
  int N, M; cin >> N >> M;
  adj_list adj(N);
  unordered_set<int> a;
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_front(v);
    adj[v].push_front(u);
    a.insert(u * N + v);
    a.insert(v * N + u);
  }

  vector<int> d_f(N, -1), d_l(N, -1);
  bfs(adj, 0, d_f);
  bfs(adj, N - 1, d_l);

  long long C = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      C += a.find(i * N + j) == a.end() && d_f[i] + d_l[j] + 1 >= d_l[0] && d_f[j] + d_l[i] + 1 >= d_l[0];
    }
  }

  cout << C << endl;
  return 0;
}
